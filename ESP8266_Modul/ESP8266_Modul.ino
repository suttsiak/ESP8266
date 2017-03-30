#include <ESP8266WiFi.h>
#include <Wire.h>
#include "Define.h"
#include "Global.h"
#include "Object.h"


void setup()
{
   //************* Inital ***************
    Init_PIN();
    Init_PWR_GSM();
    Init_Serial(); 
    Init_Wifi();
    init_TPC_Client();
    Init_LCD();
    init_MCP23017();
    init_TFT();
    Init_DHT();
  //************  Connect Monitor *********
   // Monitor_Connect();
    Monitor_Lcd();

}
void loop()
{
  Counter++;
      delay(100);
      switch(Counter){
      case 1:   mcpA.digitalWrite(0, LOW);
                LCD_Count();
             break;
      case 2:   mcpA.digitalWrite(1, LOW);
                LCD_Count();
             break;
      case 3:
                mcpA.digitalWrite(2, LOW);
               LCD_Count();
             break;
      case 4:
                mcpA.digitalWrite(3, LOW);
               LCD_Count();
             break;
      case 5:
                mcpA.digitalWrite(4, LOW);
               LCD_Count();
             break;
      case 6:
                mcpA.digitalWrite(5, LOW);
               LCD_Count();
             break;
      case 7:
                mcpA.digitalWrite(6, LOW);
               LCD_Count();
             break;
      case 8:
                mcpA.digitalWrite(7, LOW);
               LCD_Count();
             break;
     case 9:
                DO_ALL_HIGH(); //off
                LCD_Count();
             break;

     case 10:
               mcpA.digitalWrite(7, LOW);
               LCD_Count();
             break;
     case 11:
               mcpA.digitalWrite(6, LOW);
               LCD_Count();
             break;
     case 12:
               mcpA.digitalWrite(5, LOW);
               LCD_Count();
             break;  
     case 13:
               mcpA.digitalWrite(4, LOW);
               LCD_Count();
             break;  
     case 14:
               mcpA.digitalWrite(3, LOW);
               LCD_Count();
             break;   
     case 15:
               mcpA.digitalWrite(2, LOW);
               LCD_Count();
             break;                                  
     case 16:
               mcpA.digitalWrite(1, LOW);
               LCD_Count();
             break;
     case 17:
               mcpA.digitalWrite(0, LOW);
               LCD_Count();
             break; 
     case 18:
                DO_ALL_HIGH(); //off
                LCD_Count();
             break;               
     case 19:
               DO_SELECT(C0);
               LCD_Count();
             break;
      case 20:
               DO_SELECT(C1);
               LCD_Count();
             break;
      case 21:
               DO_SELECT(C2);
               LCD_Count();
             break;
      case 22:
               DO_SELECT(C3);
               LCD_Count();
             break;
      case 23:
               DO_SELECT(C4);
               LCD_Count();
             break;
      case 24:
               DO_SELECT(C5);
               LCD_Count();
             break;
      case 25:
               DO_SELECT(C6);
               LCD_Count();
             break;     
      case 26:
               DO_SELECT(C7);
               LCD_Count();
             break;    

      case 27:      
             Read_ADS1105_TFT(); 
             LCD_Count();    
             break;  
      case 28:
              Read_DHT();
              LCD_Count();
             break;
             
      case 29:
              TCP_SEND();
              LCD_Count();   
             // Serial.println("SEND TCP :");
              break;
               
      case 30:
               Counter = 0;
                    DO_ALL_HIGH();
                      lcd.setCursor(6, 3);
                      lcd.print("0 ");
                    //Serial.println("Clear PIN:");
             break;
      defualt:
             break;
      }
}


