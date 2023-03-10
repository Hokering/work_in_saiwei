// This header file contains a list of user setup files and defines which one the
// compiler uses when the IDE performs a Verify/Compile or Upload.
//
// Users can create configurations for different Espressif boards and TFT displays.
// This makes selecting between hardware setups easy by "uncommenting" one line.

// The advantage of this hardware configuration method is that the examples provided
// with the library should work with different setups immediately without any other
// changes being needed. It also improves the portability of users sketches to other
// hardware configurations and compatible libraries.
//
// Create a shortcut to this file on your desktop to permit quick access for editing.
// Re-compile and upload after making and saving any changes to this file.

// Customised User_Setup files are stored in the "User_Setups" folder.

#ifndef USER_SETUP_LOADED //  Lets PlatformIO users define settings in
                          //  platformio.ini, see notes in "Tools" folder.
						  
#include <User_Setups/My_ESP32_Watch_Setup.h>    // Setup file for ESP32 and TTGO T-Display ST7789V SPI bus TFT

#endif // USER_SETUP_LOADED



/////////////////////////////////////////////////////////////////////////////////////
//                                                                                 //
//     DON'T TINKER WITH ANY OF THE FOLLOWING LINES, THESE ADD THE TFT DRIVERS     //
//       AND ESP8266 PIN DEFINITONS, THEY ARE HERE FOR BODMER'S CONVENIENCE!       //
//                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////


// Identical looking TFT displays may have a different colour ordering in the 16 bit colour
#define TFT_BGR 0   // Colour order Blue-Green-Red
#define TFT_RGB 1   // Colour order Red-Green-Blue

// Load the right driver definition - do not tinker here !
#if defined (ST7789_DRIVER)
     #include "TFT_Drivers/ST7789_Defines.h"
     #define  TFT_DRIVER 0x7789
                              // <<<<<<<<<<<<<<<<<<<<<<<< ADD NEW DRIVER HERE
                              // XYZZY_init.h and XYZZY_rotation.h must also be added in TFT_eSPI.c
#elif defined (XYZZY_DRIVER)
     #include "TFT_Drivers/XYZZY_Defines.h"
     #define  TFT_DRIVER 0x0000
#else
     #define  TFT_DRIVER 0x0000
#endif


// These are the pins for ESP8266 boards
//      Name   GPIO    NodeMCU      Function
#define PIN_D0  16  // GPIO16       WAKE
#define PIN_D1   5  // GPIO5        User purpose
#define PIN_D2   4  // GPIO4        User purpose
#define PIN_D3   0  // GPIO0        Low on boot means enter FLASH mode
#define PIN_D4   2  // GPIO2        TXD1 (must be high on boot to go to UART0 FLASH mode)
#define PIN_D5  14  // GPIO14       HSCLK
#define PIN_D6  12  // GPIO12       HMISO
#define PIN_D7  13  // GPIO13       HMOSI  RXD2
#define PIN_D8  15  // GPIO15       HCS    TXD0 (must be low on boot to enter UART0 FLASH mode)
#define PIN_D9   3  //              RXD0
#define PIN_D10  1  //              TXD0

#define PIN_MOSI 8  // SD1          FLASH and overlap mode
#define PIN_MISO 7  // SD0
#define PIN_SCLK 6  // CLK
#define PIN_HWCS 0  // D3

#define PIN_D11  9  // SD2
#define PIN_D12 10  // SD4
