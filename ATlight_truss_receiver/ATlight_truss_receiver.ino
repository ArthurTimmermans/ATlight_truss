#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
#define REQ_BUF_SZ   60

int toneVal = 1;
int tonePin = 44;

// Ethernet define
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 109);
EthernetServer server(80);
char HTTP_req[REQ_BUF_SZ] = {0};
char req_index = 0;

File webFile;
void setup() {
  
  // Setting segment display pins to output
  for(int x=22; x<40; x++){
    pinMode(x, OUTPUT);
  }
  pinMode(44, OUTPUT);
  // Start serial
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  
  //SD setup
  Serial.println("Initializing SD card...");
  if(!SD.begin(4)){
    Serial.println("ERROR: SD card initialization failed!");
    return;
  }
Serial.println("SD card initialized!");
if(!SD.exists("index.htm")){
  Serial.println("ERROR: Cannot find index.htm");
  return;
}

  // Start ethernet connection.
  Ethernet.begin(mac,ip);
  server.begin();
  Serial.print("Server is at: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
   EthernetClient client = server.available();  // get client

    if (client) {
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client still there to read data from
                char c = client.read(); // read 1 byte (character) from client
                // buffer first part of HTTP request in HTTP_req array (string)
                // leave last element in array as 0 to null terminate string (REQ_BUF_SZ - 1)
                if (req_index < (REQ_BUF_SZ - 1)) {
                    HTTP_req[req_index] = c;          // save HTTP request character
                    req_index++;
                }
                // print HTTP request character to serial monitor
                Serial.print(c);
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    // open requested web page file
                    if (StrContains(HTTP_req, "GET / ")
                                 || StrContains(HTTP_req, "GET /index.htm")) {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println("Connnection: keep-alive");
                        client.println();
                        webFile = SD.open("index.htm");// open main page
                    }
                    else if (StrContains(HTTP_req, "GET /css/style.css")) {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/css");
                        client.println("Connnection: keep-alive");
                        client.println();
                        webFile = SD.open("css/style.css");        // open style
                    }
                    else if(StrContains(HTTP_req, "GET /favicon.ico")) {
                        webFile = SD.open("favicon.ico");       // open favicon
                    }
                    if (webFile) {
                        while(webFile.available()) {
                            client.write(webFile.read()); // send web page to client
                        }
                        webFile.close();
                    }
                    // reset buffer index and all buffer elements to 0
                    req_index = 0;
                    StrClear(HTTP_req, REQ_BUF_SZ);
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)

    //countdown();
    numberTranslate(1,2);
}

// Test all the segments from the 2 segment displays. 
void testLights(){
  for(int testLightsInt=22; testLightsInt<40; testLightsInt++){
    digitalWrite(testLightsInt, HIGH);
    digitalWrite(testLightsInt-1, LOW);
    delay(200);
  }
  for(int testLightsFull=22; testLightsFull<40; testLightsFull++){
    digitalWrite(testLightsFull, HIGH);
  }
}

// Turns segments from display off
void lightsOff(){
  for(int numOff=22; numOff<40; numOff++){
   digitalWrite(numOff, LOW); 
  }
}

// Counts down from 9.9 to 0.0
void countdown(){
  for(int countNum=99; countNum>= 0; countNum--){
    int digit1 = countNum/10;
    int digit2 = countNum-(countNum/10)*10;
    numberTranslate(digit1, digit2);
    delay(100);
    lightsOff();
  }
  
}

// Translate the numbers to segment display. 
void numberTranslate(int num2, int num1){
  digitalWrite(29, HIGH);
  switch(num2){
    case 0:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 1:
      digitalWrite(24, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 2:
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(27, HIGH);
      break;
    case 3:
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 4:
      digitalWrite(22, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 5:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 6:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 7:
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 8:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 9:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
  }
  switch(num1){
    case 0:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(36, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 1:
      digitalWrite(34, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 2:
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(36, HIGH);
      digitalWrite(37, HIGH);
      break;
    case 3:
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 4:
      digitalWrite(32, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 5:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 6:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(36, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 7:
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 8:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(36, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 9:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
  }
}

void StrClear(char *str, char length)
{
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;

    len = strlen(str);
    
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }

    return 0;
}
