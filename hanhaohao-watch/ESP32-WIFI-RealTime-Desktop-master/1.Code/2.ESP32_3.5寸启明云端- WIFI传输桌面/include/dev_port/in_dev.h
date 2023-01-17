//输入驱动
#ifndef _IN_DEV_H_
#define _IN_DEV_H_

#include <lvgl.h>
#include "mywatch.h"
#include "FT6336U.h"

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;
lv_indev_t * indev_mouse;
lv_indev_t * indev_keypad;
lv_indev_t * indev_encoder;
lv_indev_t * indev_button;

//触摸屏引脚定义和数据缓存
FT6336U ft6336u(I2C_SDA, I2C_SCL, RST_N_PIN, INT_N_PIN); 
FT6336U_TouchPointType tp; 

static void touchpad_init(void);
static bool touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_port_indev_init(void)
{
    /* Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    /*Initialize your touchpad if you have*/
    touchpad_init();
    /*初始化输入设备驱动程序*/
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);             /*Descriptor of a input device driver*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;    /*Touch pad is a pointer-like device*/
    indev_drv.read_cb = touchpad_read;      /*Set your driver function*/
    indev_touchpad = lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/
}

/*Initialize your touchpad*/
static void touchpad_init(void)
{
    //触摸屏初始化
    ft6336u.begin();/* Touch init */
    ft6336u.setRotation(Rotation_1);//为横屏方向
}

/*电容触摸驱动*/
bool touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  int16_t touchX, touchY;
  tp = ft6336u.scan();
	touchX = tp.tp[0].x;
	touchY = tp.tp[0].y;
	//bool touched = tp.tp[0].status;  //  bool TFT_eTouch<T>::getXY(int16_t& x, int16_t& y)
	bool touched = tp.touch_count;
  if(!touched)
  {
    return false;
  }
  if(touchX>screenWidth || touchY > screenHeight)
  {
    Serial.println("Y or y outside of expected parameters..");
    Serial.print("y:");
    Serial.print(touchX);
    Serial.print(" x:");
    Serial.print(touchY);
  }
  else
  {
    data->state = touched ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL; 
    /*Set the coordinates (if released use the last pressed coordinates)*/
    data->point.x = touchX;
    data->point.y = touchY;
    Serial.print("Data x");
    Serial.println(touchX);
    Serial.print("Data y");
    Serial.println(touchY);
  }
  return false; /*Return `false` because we are not buffering and no more data to read*/
}

#endif