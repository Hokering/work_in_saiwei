
// This is the command sequence that initialises the ST7796 driver
//
// This setup information uses simple 8 bit SPI writecommand() and writedata() functions
//
// See ST7735_Setup.h file for an alternative format

#define TFT_INIT_DELAY 0
{
	writecommand(0xF0);                           
	writedata(0xC3);
	writecommand(0xF0);                           
	writedata(0x96);
	writecommand(0x36);                           
	writedata(0x68);
	writecommand(0x3A);                           
	writedata(0x05);
	writecommand(0xB0);                           
	writedata(0x80);
	writecommand(0xB6);                           
	writedata(0x00);
	writedata(0x02);
	writecommand(0xB5);                           
	writedata(0x02);
	writedata(0x03);
	writedata(0x00);
	writedata(0x04);
	writecommand(0xB1);                           
	writedata(0x80);
	writedata(0x10);
	writecommand(0xB4);                           
	writedata(0x00);
	writecommand(0xB7);                           
	writedata(0xC6);
	writecommand(0xC5);                           
	writedata(0x24);
	writecommand(0xE4);                           
	writedata(0x31);

	writecommand(0xE8);                           
	writedata(0x40);                         
	writedata(0x8A);
	writedata(0x00);                         
	writedata(0x00);
	writedata(0x29);                         
	writedata(0x19);
	writedata(0xA5);                         
	writedata(0x33);

	writecommand(0xC2); 
	delay(50);                          
	writecommand(0xA7);
	delay(50);

	writecommand(TFT_CASET);                           
	writedata(0x00);                         
	writedata(0x00);
	writedata(TFT_WIDTH>>8);                        
	writedata(TFT_WIDTH&0xFF);
	writecommand(TFT_PASET);
	writedata(0x29);                         
	writedata(0x19);
	writedata(TFT_HEIGHT>>8);                         
	writedata(TFT_HEIGHT&0xFF);  

	writecommand(ST7796_GMCTRP1);                           
	writedata(0xF0);                         
	writedata(0x09);
	writedata(0x13);                         
	writedata(0x12);
	writedata(0x12);                         
	writedata(0x2B);
	writedata(0x3C);                         
	writedata(0x44);  
	writedata(0x4B);                         
	writedata(0x1B);
	writedata(0x18);                         
	writedata(0x17);
	writedata(0x1D);                         
	writedata(0x21);

	writecommand(ST7796_GMCTRN1);                           
	writedata(0xF0);                         
	writedata(0x09);
	writedata(0x13);                         
	writedata(0x0C);
	writedata(0x0D);                         
	writedata(0x27);
	writedata(0x3B);                         
	writedata(0x44);  
	writedata(0x4D);                         
	writedata(0x0B);
	writedata(0x17);                         
	writedata(0x17);
	writedata(0x1D);                         
	writedata(0x21); 

	writecommand(0X36);                           
	writedata(0xEC);
	writecommand(0xF0);                           
	writedata(0xC3); 
	writecommand(0xF0);                           
	writedata(0x69); 
	writecommand(ST7796_NORON); 
	delay(100);                          
	writecommand(ST7796_SLPOUT);
	delay(100); 
	writecommand(ST7796_DISPON);
	delay(100); 

  end_tft_write();
  delay(120);
  begin_tft_write();

	writecommand(0x29); //Display on                                          	
}
            