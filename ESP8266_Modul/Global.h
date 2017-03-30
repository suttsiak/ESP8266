
//***************  Veriable ***********************
IPAddress server_ip = {192,168,10,23};       //ค่า ip ของ Server
WiFiServer server(SERVER_PORT); //สร้าง object server และกำหนด port ที่ต้องการเชื่อมต่อกับ server
WiFiClient client;              //สร้าง object client

float humidity;
float temperature;
int Counter = 0;
int16_t adc0,adc1,adc2,adc3;
int C0[8] = {1, 0, 0, 0, 0, 0, 0, 1};
int C1[8] = {1, 1, 0, 0, 0, 0, 1, 1};
int C2[8] = {1, 1, 1, 0, 0, 1, 1, 1};
int C3[8] = {1, 1, 1, 1, 1, 1, 1, 1};
int C4[8] = {1, 1, 1, 0, 0, 1, 1, 1};
int C5[8] = {1, 1, 0, 0, 0, 0, 1, 1};
int C6[8] = {1, 0, 0, 0, 0, 0, 0, 1};
int C7[8] = {0, 0, 0, 0, 0, 0, 0, 0};
