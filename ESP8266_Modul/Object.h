#include "Adafruit_MCP23017.h"
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_ADS1015.h>
#include <SoftwareSerial.h>
#include "DHT.h"



//***************  Object ***********************
LiquidCrystal_I2C lcd(0x27, 20, 4);
Adafruit_MCP23017 mcpA;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_ADS1015 ads;     /* Use thi for the 12-bit version */
// Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
DHT dht;

//***********************************************
