#ifndef _MY_WATCH_H
#define _MY_WATCH_H

#include <Arduino.h>

//固件版本号
#define Firmware_version "V 1.0.0"

//是否开启debug功能
const unsigned long BAUD_RATE = 115200;   //波特率

#define DEBUG 

#ifdef DEBUG 
#define DebugPrintln(message) Serial.println(message)
#else 
#define DebugPrintln(message)
#endif

#ifdef DEBUG 
#define DebugPrint(message) Serial.print(message) 
#else 
#define DebugPrint(message)
#endif

//星座信息

//默认WIFI信息
char ssid[] = "liuzewen";
char pswd[] = "17609245102liu";

//-----------------------GPIO配置-----------------------------

//触摸引脚
#define I2C_SDA 18
#define I2C_SCL 19
#define RST_N_PIN -1
#define INT_N_PIN 39

//SD卡接口
#define SD_MISO     2
#define SD_MOSI     14
#define SD_SCLK     17
#define SD_CS       4

long up_pres_time = 0;
long m_pres_time = 0;
long down_pres_time = 0;

//wifi结构体
struct config_type{   
  char stassid[32];   
  char stapsw[64]; 
}config;

uint16_t Battery_capacity = 500;                         //电池电量

long key_long_pres_time = 1.2*1000;   //按键长时间按下时间

//屏幕宽长
int screenWidth = 480;
int screenHeight = 320;

#endif /* _MY_WATCH_H */