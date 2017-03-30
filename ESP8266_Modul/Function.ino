
//***************  Function  ***********************
void GSM_SEND_TCP(void){
  Serial.print("AT+CIPSTART=\"TCP\",\"58.9.244.94\",350");
}
void TCP_SEND(void){
  while(Serial.available() > 0){
      uint8_t data = client.read();
      Serial.write(data);
  }
  ESP.wdtDisable(); //close watch dog Timer
 // client.println("Hello");
  client.print(humidity, 1);
  client.print("\t\t");
  client.print(temperature, 1);
  client.print("\t\t");
  client.println(dht.toFahrenheit(temperature), 1);
  client.flush();
  
}
void LCD_Count(void){
    lcd.setCursor(6, 3);
    lcd.print(Counter);
}
void Read_DHT(void){
  delay(dht.getMinimumSamplingPeriod());

   humidity = dht.getHumidity(); // ดึงค่าความชื้น
   temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
/*
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);
  */
}
void Read_ADS1105_TFT(void){
  adc0 = ads.readADC_SingleEnded(0);
  delay(200);
  adc1 = ads.readADC_SingleEnded(1);
  delay(200);
  adc2 = ads.readADC_SingleEnded(2);
  delay(200);
  adc3 = ads.readADC_SingleEnded(3);
  delay(200);

  tft.fillRect(150,120,70,21,BLACK);
  tft.setCursor(150, 120); tft.setTextColor(ILI9341_ORANGE); tft.setTextSize(3);tft.println(adc0);

  tft.fillRect(150,150,70,21,BLACK);
  tft.setCursor(150, 150); tft.setTextColor(ILI9341_ORANGE); tft.setTextSize(3);tft.println(adc1);

  tft.fillRect(150,180,70,21,BLACK);
  tft.setCursor(150, 180); tft.setTextColor(ILI9341_ORANGE); tft.setTextSize(3);tft.println(adc2);

  tft.fillRect(150,210,70,21,BLACK);
   tft.setCursor(150, 210); tft.setTextColor(ILI9341_ORANGE); tft.setTextSize(3);tft.println(adc3);
/*
  float Voltage1 = (adc0 * 0.1875)/1000;
  float Voltage2 = (adc1 * 0.1875)/1000;
  float Voltage3 = (adc2 * 0.1875)/1000;
  float Voltage4 = (adc3 * 0.1875)/1000;

  Serial.print("AIN0: "); Serial.print(adc0); Serial.print(", Voltage: "); Serial.println(Voltage1);
  Serial.print("AIN1: "); Serial.print(adc1); Serial.print(", Voltage: "); Serial.println(Voltage2);
  Serial.print("AIN2: "); Serial.print(adc2); Serial.print(", Voltage: "); Serial.println(Voltage3);
  Serial.print("AIN3: "); Serial.print(adc3); Serial.print(", Voltage: "); Serial.println(Voltage4);
  */
}
void DO_SELECT(int a[8])
{
  //int j[8];
  for(int i = 0; i < 8; i++){
    //j[i] = a[i];
      if(a[i] == 0){
        mcpA.digitalWrite(i, LOW);
       }else{
        mcpA.digitalWrite(i, HIGH);
      }
   }
}

void DO_ALL_HIGH(void)
{
   for (int i = 0; i < 8; i++)
   {   
      mcpA.digitalWrite(i, HIGH);
   }
  
}
void Monitor_Lcd(void){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Wifi Connected   ");
    lcd.setCursor(0, 1);
    lcd.print("IP:");
    lcd.setCursor(4, 1);
    lcd.print(WiFi.localIP());
    lcd.setCursor(0, 3);
    lcd.print("Count:");

}
void Monitor_Connect(void){
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
//********************************** Inital Device ****************************
void Init_A7GSM(void){
   Serial.println("Init_A7GSM");
   Serial.println("AT");
   delay(500);  
   Serial.println("AT+CGATT=1");
   delay(500);
   Serial.println("AT+CIPMUX=0");
   delay(500);
   Serial.println("AT+CSTT=\"internet\",\"\",\"\"");
   delay(500);
   Serial.println("AT+CIICR");
   delay(500);
   Serial.println("AT+CIFSR");
}
void init_TFT(){
  tft.begin();
 // tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

  //tft.setTextColor(ILI9341_BLACK, ILI9341_WHITE);

  tft.setRotation(1);

  tft.setCursor(10, 0);
  tft.setTextColor(ILI9341_BLUE); tft.setTextSize(3);
  tft.println("WiFi:Connect");
  tft.setTextColor(ILI9341_WHITE); tft.setTextSize(2);
  tft.println("--------------------------");
  tft.setTextColor(ILI9341_GREEN); tft.setTextSize(2);
  tft.print("SSID:"); tft.println(WiFi.SSID());
  tft.setTextColor(ILI9341_GREEN); tft.setTextSize(2);
  tft.print("IPADDRESS:"); tft.println(WiFi.localIP());
  tft.setTextColor(ILI9341_GREEN); tft.setTextSize(2);
  tft.print("SUBNETMARK:"); tft.println(WiFi.subnetMask());
  tft.setTextColor(ILI9341_GREEN); tft.setTextSize(2);
  tft.print("GATEWAY:"); tft.println(WiFi.gatewayIP());
  tft.setTextColor(ILI9341_WHITE); tft.setTextSize(2);
  tft.println("--------------------------");
  
  tft.setCursor(10, 120);
  tft.setTextColor(ILI9341_ORANGE); tft.setTextSize(3);
  tft.println("AIN0:");

  tft.setCursor(10, 150);
  tft.setTextColor(ILI9341_ORANGE); tft.setTextSize(3);
  tft.println("AIN1:");

  tft.setCursor(10, 180);
  tft.setTextColor(ILI9341_ORANGE); tft.setTextSize(3);
  tft.println("AIN2:");

  tft.setCursor(10, 210);
  tft.setTextColor(ILI9341_ORANGE); tft.setTextSize(3);
  tft.println("AIN3:");

  
  }
void init_TPC_Client(){
  Serial.println("Connect TCP Server");
  while(!client.connect(server_ip,SERVER_PORT))
  {
     Serial.print(".");
     delay(100);
  }
  Serial.println("Success");
  ESP.wdtDisable(); //close watch dog Timer
}
void init_MCP23017(){
   Wire.begin();//(scl,sda)
  mcpA.begin(0);

  for (int i = 0; i < 8; i++){
    mcpA.pinMode(i, OUTPUT);
    mcpA.digitalWrite(i, HIGH);
  }

}
void Init_Wifi(void){
  
   Serial.println();
   Serial.println();
   Serial.print("Connecting to ");
   Serial.println(ssid);
   
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}
void Init_LCD(void){
   Wire.begin();//(scl,sda)
   lcd.begin();  
}
void Init_DHT(void){
   dht.setup(12); // data pin 2
}

void Init_Serial(void){
   Serial.begin(115200);
   delay(10);
}
void Init_PWR_GSM(void){
 digitalWrite(PWR_GSM,LOW);
 delay(500);
 digitalWrite(PWR_GSM,HIGH);
 delay(1000);
 digitalWrite(PWR_GSM,LOW);
 delay(500);
}
void Init_PIN(void){
  pinMode(PWR_GSM, OUTPUT);
  delay(10);
}

