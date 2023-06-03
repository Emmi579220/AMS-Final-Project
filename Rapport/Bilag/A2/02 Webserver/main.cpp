#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ESPAsyncWebServer.h>


const char *ssid = "cringe";
const char *password = "cringecringe";

volatile int coffeeCount = 67;
volatile int lastid = 0;
AsyncWebServer server(80);

void handleGetRequest(AsyncWebServerRequest *request) {
  const int maxHtmlLength = 2048;
  char html[maxHtmlLength];
  
  snprintf(html, maxHtmlLength,
    "<html><head><title>Coffee Counter</title>"
    "<style>"
    "body { font-family: 'Courier New', monospace; background-color: #000; color: #fff; text-align: center; }"
    ".container { display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; }"
    ".coffee-symbol { font-size: %dpx; margin-bottom: 30px; }"
    ".counter { font-size: 24px; }"
    "</style>"
    "</head><body>"
    "<div class='container'>"
    "<h1>Coffee Counter</h1>"
    "<div class='coffee-symbol' id='coffeeSymbol'></div>"
    "<div class='counter'>Total cups of coffee consumed: <span id='counter'>%d</span></div>"
    "<script>"
    "setTimeout(function(){window.location.reload();}, 5000);" //This command refreshes the page
    "var coffeeCount = %d;" 
    "var coffeeSymbolDiv = document.getElementById('coffeeSymbol');"
    "for (var i = 0; i < coffeeCount; i++) {"
    "  coffeeSymbolDiv.innerHTML += '&#9749;';"
    "}"
    "</script>"
    "</div>"
    "</body></html>",5*((600^2)/coffeeCount)^(1/2), coffeeCount, coffeeCount);

  request->send(200, "text/html", html);
}

void handlePostRequest(AsyncWebServerRequest *request) {
  Serial.println("Recieved POST");
  if (request -> hasArg("id")){
    int id = (request -> arg("id")).toInt();
    if(id != lastid){
        if (request-> hasArg("amount")){
          String coffeeUpdate = request->arg("amount");
          coffeeCount += coffeeUpdate.toInt();
            Serial.println("Updating wit amount " + coffeeUpdate);
          // Send the response
          char responseBuffer[64];
          snprintf(responseBuffer, sizeof(responseBuffer), "%d", coffeeCount);
          request->send(200, "text/plain", responseBuffer);
          lastid = id;
        }
    } else {
          char responseBuffer[64];
          snprintf(responseBuffer, sizeof(responseBuffer), "%d", coffeeCount);
          request->send(200, "text/plain", responseBuffer);
    } 
  } else {
    request->send(400); // Bad Request
  }
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    handleGetRequest(request);
  });

  server.on("/", HTTP_POST, [](AsyncWebServerRequest *request){
    handlePostRequest(request);
  });

  server.begin();
}

void loop() {
  // Code here will run repeatedly
}