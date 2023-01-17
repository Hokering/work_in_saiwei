/*
 * @Date: 2020-10-28 19:10:28
 * @LastEditors: liuzewen
 * @LastEditTime: 2020-10-30 12:56:49
 * @FilePath: \Blinker-Douse:\GITHUB\ESP32-Wifi实时桌面\1.Code\1.ESP32_1.14LCD-WIFI传输桌面\src\main.cpp
 */

#pragma GCC optimize ("O3")

#include <TFT_eSPI.h>  

TFT_eSPI Tft = TFT_eSPI(135, 240); // Invoke custom library

#include <WiFi.h>
#include <esp_wifi.h>

#include "TCPReceiver.h"
#include "DMADrawer.h"

TCPReceiver recv;

void setup(void)
{
  Serial.begin(115200);
  Serial.flush();
  //LCD屏幕初始化
  Tft.begin(); /* TFT init */
  
  //显示屏背光
  ledcSetup(10, 5000/*freq*/, 10 /*resolution*/);
  ledcAttachPin(TFT_BL, 10);
  analogReadResolution(10);
  ledcWrite(10,512);

  Tft.setRotation(0);
  if (Tft.width() < Tft.height())
    Tft.setRotation(1);

  int width  = Tft.width();
  int height = Tft.height();
  if (width  > 240) width  = 240;
  if (height > 135) height = 135;

  Tft.setTextFont(2);
  Tft.fillScreen(TFT_WHITE);

  Serial.println("WiFi begin.");
  Tft.println("WiFi begin.");
  //尝试连接到存储的AP
  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin();

//等待10秒钟再连接
  for (int i = 0; WiFi.status() != WL_CONNECTED && i < 200; i++) { delay(100); }

  //如果无法连接，请启动SmartConfig
  // https://itunes.apple.com/app/id1071176700
  // https://play.google.com/store/apps/details?id=com.cmmakerclub.iot.esptouch
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("SmartConfig start.");
    Tft.println("SmartConfig start.");
    WiFi.mode(WIFI_MODE_APSTA);
    WiFi.beginSmartConfig();

    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
    }
    WiFi.stopSmartConfig();
    WiFi.mode(WIFI_MODE_STA);
  }

  Serial.println(String("IP:") + WiFi.localIP().toString());
  Tft.println(WiFi.localIP().toString());

  setup_t s;
  Tft.getSetup(s);

  int spi_freq = SPI_FREQUENCY;
//如果您进入80MHz的重启循环，请尝试降低到40MHz。
//如果（spi_freq> 40000000）spi_freq = 40000000;

  recv.setup( s.r0_x_offset
            , s.r0_y_offset
            , width
            , height
            , spi_freq
            , TFT_MOSI
            , TFT_MISO
            , TFT_SCLK
            , TFT_CS
            , TFT_DC
            );
}

void loop(void)
{
  recv.loop();
}
