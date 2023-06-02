#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/timer.h>
#include <driver/gpio.h>
#include "HR2046.hpp"
#include "N4094.hpp"
#include "WifiConnect.hpp"
#include "Time.hpp"
#include "NTPClient.h"
#include <EEPROM.h>
//
#include <HTTPClient.h>
#include <WiFi.h>

// EEPROM defines
#define EEPROM_SIZE 512

// Control port definitions:
#define RS_PIN GPIO_NUM_2
#define WR_PIN GPIO_NUM_4
#define CS_PIN GPIO_NUM_27
#define RST_PIN GPIO_NUM_25

// Touch pins definitions
#define TOUCH_IRQ GPIO_NUM_34
#define TOUCH_CS GPIO_NUM_15

gpio_num_t controlPins[4] = {RST_PIN, RS_PIN, WR_PIN, CS_PIN};

SPIClass vspi(VSPI);
SPIClass hspi(HSPI);
N4094 shiftRegister(vspi, GPIO_NUM_5);
HR2046 touch(hspi, TOUCH_CS);
ssd1963_gpio gpioControl(controlPins);
ssd1963 ssd1963Driver(shiftRegister, gpioControl);
font myFont;

//setup objects for time and wifi control
// NTP server request time data
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");
tmElements_t tm;
Time myTimer(tm, timeClient);
WifiConnect wifi;
HTTPClient http;
WiFiClient client;
char date_str[12];
char time_str[9];

//TEMP WIFI FIX: 
const char *ssid_ = "CatMagnet";
const char *password_ = "bingobongo!";


//data to store in EEPROM
int totalCoffees;
int todaysCoffees;

TaskHandle_t task1Handle = NULL;

void setupScreenInterface();
void insertFrame(int length, int height, int x, int y, int color, char *centerText, bool smallText);
void task1(void* parameters); //Task blinks the wifi symbol when not connected

static bool touchFlag = false;
void IRAM_ATTR touchIrq()
{
  if (!touchFlag)
  {
    touchFlag = true;
  }
}

volatile bool resetCoffeesFlag = false;


void setupTimers()
{

}

void setupWifi(){
    WiFi.begin(ssid_, password_);
    while(WiFi.status() != WL_CONNECTED) {
      delay(1000); 
      Serial.println("Connecting to wifi...");
    }
    Serial.println("Connected To Wifi");
}

void setup(){
    Serial.begin(115200);
    
    //EEPROM SETUP
    if (!EEPROM.begin(EEPROM_SIZE))
    {
      Serial.println("EEPROM failed to initialise");
      while (true);
    }
    else
    {
      Serial.println("EEPROM initialised");
    }
    
    vspi.begin();
    vspi.setFrequency(1000000);
    hspi.begin();
    hspi.setFrequency(10000000);
    touch.init();
    ssd1963Driver.DisplayInit();
    ssd1963Driver.fill(0, 0, 800, 480, COLOR_WHITE); 

    pinMode(TOUCH_IRQ, INPUT_PULLUP);
    attachInterrupt(TOUCH_IRQ, touchIrq, FALLING);
    delay(1000);
    setupScreenInterface();
    xTaskCreate(task1, "task1", 44000, NULL, 2, &task1Handle);
    //wifi.ConnectToWiFi();
    setupWifi();
    setupTimers();
}



void sendPostRequest(int coffeeAmount) {
  bool send = false;
  int tries = 0;
  int id = esp_random();
  while(!send){
    Serial.println("[HTTP] Sending POST request...");
    // Connect to the server
    if (http.begin(client, "http://192.168.1.10/")) {
      
      // Set the content type header
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      //http.addHeader("Content-Type", "text/plain");
      // Send the POST request with the coffee amount
      // Construct the POST request payload
      //Id for message to avoid duplicates: 
 
      String payload = "amount=" + String(coffeeAmount) + "&test=69&id="+ String(id);

      // Send the POST request with the payload
      int httpResponseCode = http.POST(payload);
      delay(50);
      //int httpResponseCode = http.POST("amount=" + String(coffeeAmount));
      // Check the response
      if (httpResponseCode == HTTP_CODE_OK) {
        String response = http.getString();
        Serial.println("Coffee count sent successfully");
        Serial.print("Response: ");
        Serial.println(response);
        send = true;
        resetCoffeesFlag = true;
      } else {
        Serial.print("HTTP POST request failed with error code ");
        Serial.println(httpResponseCode);
      }
      
      // Disconnect and free resources
      http.end();
    } else {
      Serial.println("Connection to server failed!");
    }
    tries += 1;
    if (tries == 10){
      Serial.println("Connection to server failed!, Breaking connection");
      send = true;
    }
  }
}


void loop(){

    if (WiFi.status() == WL_CONNECTED)
    {
        myTimer.timeClient_.update();
        myTimer.getTime(time_str);
        myTimer.getDate(date_str);
        ssd1963Driver.writeString(16, 14, time_str, COLOR_BLACK, &myFont, false);
        ssd1963Driver.writeChar(16+128, 14, '-', COLOR_BLACK, &myFont, false);
        ssd1963Driver.writeString(16+144, 14, date_str, COLOR_BLACK, &myFont, false);    
        
    }
    else
    {
        ssd1963Driver.fill(16, 14, 320, 30, COLOR_WHITE);
        if (task1Handle != NULL)
        {
            xTaskCreate(task1, "task1", 44000, NULL, 2, &task1Handle);
            wifi.ConnectToWiFi();
        }
    }
    
    if (touchFlag)
    {
        uint16_t x;
        uint16_t y;
        uint32_t z;
        touch.readRaw(x, y, z);
        if(x == 9999 && y==9999 && z == 9999){
          //Fake input
        }
        else if (z > 200)
        {
            Serial.println("Touch detected");
            Serial.print("x: ");
            Serial.print(x);
            Serial.print(" y: ");
            Serial.print(y);
            Serial.print(" z: ");
            Serial.println(z);
            //Coffee ++
            if (x > 3500 && y < 1500)
            {
                Serial.println("Coffee++");
                int totalCoffees_ = EEPROM.read(0);
                int todaysCoffees_ = EEPROM.read(1);
                totalCoffees_++;
                todaysCoffees_++;
                EEPROM.write(0, totalCoffees_);
                EEPROM.write(1, todaysCoffees_);
                EEPROM.commit();
                //convert totalCoffees_ and todaysCoffees_ to char
                char totalCoffees_Str[8];
                char todaysCoffees_Str[8];
                sprintf(totalCoffees_Str,  "%d", totalCoffees_);
                sprintf(todaysCoffees_Str, "%d", todaysCoffees_);
                Serial.println(todaysCoffees_);
                Serial.println(totalCoffees_);
                //insert new text
                ssd1963Driver.fill(538+124, 283-16, 537+120+32, 283+8-16, COLOR_WHITE);
                ssd1963Driver.fill(537+122, 283-48-16, 537+120+32, 283-48+8-16, COLOR_WHITE);
                ssd1963Driver.writeString(537+122, 283-48-16, totalCoffees_Str, COLOR_BLACK, &myFont, true);
                ssd1963Driver.writeString(538+124, 283-16, todaysCoffees_Str, COLOR_BLACK, &myFont, true);
            }
            //Coffee --
            else if (x > 3500 &&  y >= 1500)
            {
                Serial.println("Coffee--");
                int totalCoffees_ = EEPROM.read(0);
                int todaysCoffees_ = EEPROM.read(1);
                if (totalCoffees_ > 0 && todaysCoffees_ > 0)
                {
                  totalCoffees_--;
                  todaysCoffees_--;
                  EEPROM.write(0, totalCoffees_);
                  EEPROM.write(1, todaysCoffees_);
                  EEPROM.commit();
                }
                else if (totalCoffees_ == 0 && todaysCoffees_ > 0)
                {
                  todaysCoffees_--;
                  EEPROM.write(0, totalCoffees_);
                  EEPROM.write(1, todaysCoffees_);
                  EEPROM.commit();
                }   
                
                //convert totalCoffees_ and todaysCoffees_ to char
                char totalCoffees_Str[8];
                char todaysCoffees_Str[8];
                sprintf(totalCoffees_Str,  "%d", totalCoffees_);
                sprintf(todaysCoffees_Str, "%d", todaysCoffees_);
                Serial.println(todaysCoffees_);
                Serial.println(totalCoffees_);
                //insert new text
                ssd1963Driver.fill(538+124, 283-16, 537+120+32, 283+8-16, COLOR_WHITE);
                ssd1963Driver.fill(537+122, 283-48-16, 537+120+32, 283-48+8-16, COLOR_WHITE);
                ssd1963Driver.writeString(538+124, 283-16, todaysCoffees_Str, COLOR_BLACK, &myFont, true);
                ssd1963Driver.writeString(537+122, 283-48-16, totalCoffees_Str, COLOR_BLACK, &myFont, true);
            }
            else if ((x > 0 && x <= 3500 && y >= 3000) && WiFi.status() == WL_CONNECTED)
            {                   
                Serial.print("POST TIME");
                int todaysCoffees_ = EEPROM.read(1);
                sendPostRequest(todaysCoffees_); 
            }  
        }
        delay(10);
        touchFlag = false;
    }
  if (resetCoffeesFlag)
    {
        resetCoffeesFlag = false;
        Serial.println("Resetting todays coffees");
        EEPROM.write(1, 0);
        EEPROM.commit();
        ssd1963Driver.writeChar(538+124, 283-16, '0', COLOR_BLACK, &myFont, true);
    }
    delay(10); 
}

void setupScreenInterface()
{
  //convert totalCoffees and todaysCoffees to char
  char totalCoffeesStr[25];
  char todaysCoffeesStr[25];
  char lastCoffeesStr[45];
  sprintf(totalCoffeesStr,  "Total coffees: %d", EEPROM.read(0));
  sprintf(todaysCoffeesStr, "Coffees today: %d", EEPROM.read(1));
  sprintf(lastCoffeesStr, "Last coffee: (0s):(0m):(0h):(0d)");
  //draw the screen interface
  insertFrame(336, 38, 0, 0, COLOR_BLACK, "", true);
  insertFrame(378, 112, 408, 0, COLOR_BLACK, "Coffee ++", false);
  insertFrame(378, 232, 408, 120, COLOR_BLACK, "", true);
  ssd1963Driver.writeString(500, 160, "Coffee counter", COLOR_BLACK, &myFont, false);
  insertFrame(378, 112, 408, 360, COLOR_BLACK, "Coffee --", false);
  insertFrame(346, 38, 428, 220-16, COLOR_BLACK, totalCoffeesStr, true);
  insertFrame(346, 38, 428, 268-16, COLOR_BLACK, todaysCoffeesStr, true);
  insertFrame(346, 38, 428, 316-16, COLOR_BLACK, lastCoffeesStr, true);
  insertFrame(378, 112, 0, 360, COLOR_BLACK, "UPLOAD", false);
}

void insertFrame(int length, int height, int x, int y, int color, char* centeredText, bool smallText)
{
  // Draw frame
  for (size_t i = 0; i < length; i++)
  {
    ssd1963Driver.writeChar(x+i, y, BORDER_HORIZONTAL, color, &myFont, true);
    ssd1963Driver.writeChar(x+i, y+height, BORDER_HORIZONTAL, color, &myFont, true);
  }
  for (size_t i = 0; i < height; i++)
  {
    ssd1963Driver.writeChar(x, y+i, BORDER_VERTICAL, color, &myFont, true);
    ssd1963Driver.writeChar(x+length, y+i, BORDER_VERTICAL, color, &myFont, true);
  }
  ssd1963Driver.writeChar(x, y, BORDER_UPPER_LEFT, color, &myFont, true);
  ssd1963Driver.writeChar(x+length, y, BORDER_UPPER_RIGHT, color, &myFont, true);
  ssd1963Driver.writeChar(x, y+height, BORDER_LOWER_LEFT, color, &myFont, true);
  ssd1963Driver.writeChar(x+length, y+height, BORDER_LOWER_RIGHT, color, &myFont, true);
  //Center text to the left in frame, text is not centered if centeredText is NULL
  if (centeredText != NULL) // last inserted frame in setupScreenInterface() is used as an example
  {
    int textLength = strlen(centeredText);        //textLength usually 16 -> "Total coffees: %d"
    int textX = x + (length/2) - (textLength*4);  //x + (346/2) - (16*4)) = 537
    int textY = y + (height/2) - 4;               //y + (38/2) - 4) = 283
    ssd1963Driver.writeString(textX, textY, centeredText, color, &myFont, smallText);
  }
}

// Task1 thread that connects to wifi, 
// and blinks wifi icon while not connected to wifi
void task1(void *parameter)
{ 
    for(;;)
    {
        if (WiFi.status() != WL_CONNECTED)
        {
          ssd1963Driver.writeChar(352, 10, WIFI_ICON, COLOR_BLACK, &myFont, false);
          vTaskDelay(500 / portTICK_PERIOD_MS);
          ssd1963Driver.writeChar(352, 10, WIFI_ICON, COLOR_WHITE, &myFont, false);
          vTaskDelay(500 / portTICK_PERIOD_MS);
        }
        else if (WiFi.status() == WL_CONNECTED)
        {
          ssd1963Driver.writeChar(352, 10, WIFI_ICON, COLOR_BLACK, &myFont, false);
          vTaskDelete(task1Handle);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

