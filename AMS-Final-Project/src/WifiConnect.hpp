#include <WiFi.h>
#include "ssd1963_displayDriver.hpp"


class WifiConnect
{
private:
    int networkList = 0;
    int ledPin_ = 2;

public:
    WifiConnect(/* args */);
    ~WifiConnect();
    void BeginWiFiConnection();
    void ScanForWiFiSignal();
    void ConnectToWiFi();
    void WiFiConnectStatus(const char *ssid, const char *password);
    void DisconnectFromWiFi();
    const char *ssid_ = "Emmi is nice";
    const char *password_ = "Kaese123";
};

