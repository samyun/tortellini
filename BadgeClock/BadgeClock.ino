/* vim: set ts=2 sw=2 sts=2 et! : */
//
// BoilerMake Fall 2014 Badge Code
//
// These boards are equivalent to an Arduino Leonardo
// And contain an ATMega32U4 microprocessor and an nRF24L01 radio
//
// Lior Ben-Yehoshua (admin@Lior9999.com)
// Viraj Sinha       (virajosinha@gmail.com)
// Scott Opell       (me@scottopell.com)
//
// 10/15/2014
//
// Happy Hacking!
//

#define MAX_TERMINAL_LINE_LEN 40
#define MAX_TERMINAL_WORDS     7

// 14 is strlen("send FFFF -m ")
// the max message length able to be sent from the terminal is
// total terminal line length MINUS the rest of the message
#define MAX_TERMINAL_MESSAGE_LEN  MAX_TERMINAL_LINE_LEN - 14

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

#include <RF24.h>
#include <SPI.h>
#include <EEPROM.h>
#include <Time.h>

void welcomeMessage(void);
void printHelpText(void);
void printPrompt(void);

void networkRead(void);
void clockFunction(void);
void serialRead(void);
void handleSerialData(char[], byte);

void setValue(word);
void handlePayload(struct payload *);

void ledDisplay(byte);
void displayDemo();

void processSyncMessage();
time_t requestSync();
void digitalClockDisplay();
void printDigits(int digits);

// Maps commands to integers
const byte PING   = 0; // Ping
const byte LED    = 1; // LED pattern
const byte MESS   = 2; // Message
const byte DEMO   = 3; // Demo Pattern

// Global Variables
int SROEPin = 3; // using digital pin 3 for SR !OE
int SRLatchPin = 8; // using digital pin 4 for SR latch
boolean terminalConnect = false; // indicates if the terminal has connected to the board yet

// nRF24L01 radio static initializations
RF24 radio(9,10); // Setup nRF24L01 on SPI bus using pins 9 & 10 as CE & CSN, respectively

uint16_t this_node_address = (EEPROM.read(0) << 8) | EEPROM.read(1); // Radio address for this node

struct payload{ // Payload structure
  byte command;
  byte led_pattern;
  char message[30];
};

// This runs once on boot
void setup() {
  Serial.begin(9600);

  // Time sync initialization
  while (!Serial) ;
  setSyncProvider(requestSync);
  
  // SPI initializations
  SPI.begin();
  SPI.setBitOrder(MSBFIRST); // nRF requires MSB first
  SPI.setClockDivider(16); // Set SPI clock to 16 MHz / 16 = 1 MHz

  // nRF radio initializations
  radio.begin();
  radio.setDataRate(RF24_1MBPS); // 1Mbps transfer rate
  radio.setCRCLength(RF24_CRC_16); // 16-bit CRC
  radio.setChannel(80); // Channel center frequency = 2.4005 GHz + (Channel# * 1 MHz)
  radio.setRetries(200, 5); // set the delay and number of retries upon failed transmit
  radio.openReadingPipe(0, this_node_address); // Open this address
  radio.startListening(); // Start listening on opened address

  // Shift register pin initializations
  pinMode(SROEPin, OUTPUT);
  pinMode(SRLatchPin, OUTPUT);
  digitalWrite(SROEPin, HIGH);
  digitalWrite(SRLatchPin, LOW);
  
  while (!Serial.available()) {};
  // Syncs the current time if available
  processSyncMessage();
  
  

  // make the pretty LEDs happen
  ledDisplay(2);
  
  
}


// This loops forever
void loop() {
    
  // Initializes the current time to prevent error in case of a rollover between getting elements
  time_t t = now();

  delay(1000);
  digitalClockDisplay();
  delay(1000);
  
  setValue(0x4400);
  delay(10000);
  setValue(0x0000);
  
  delay(1000);
  Serial.print("trolling\n");
  delay(1000);
  

  //networkRead(); // Read from network
  clockFunction();
}


// Handle reading from the radio
void networkRead() {
  while (radio.available()) {
    struct payload * current_payload = (struct payload *) malloc(sizeof(struct payload));

    // Fetch the payload, and see if this was the last one.
    radio.read( current_payload, sizeof(struct payload) );
    handlePayload(current_payload);
  }
}

//The clock function
void clockFunction(){
 
  Serial.print("damn\n");
  
  
if (hour() == 0 || hour() == 12){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x0000);
                        delay(500);
		}else{
			setValue(0x0001);
                        delay(500);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x0002);
		}else{
			setValue(0x0003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x0004);
		}else{
			setValue(0x0005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x0008);
		}else{
			setValue(0x0009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x0010);
		}else{
			setValue(0x0011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x0020);
		}else{
			setValue(0x0021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x0040);
		}else{
			setValue(0x0041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x0080);
		}else{
			setValue(0x0081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x0100);
		}else{
			setValue(0x0101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x0200);
		}else{
			setValue(0x0201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x0400);
		}else{
			setValue(0x0401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x0800);
		}else{
			setValue(0x0801);
		}
	}
}
else if (hour() == 1 || hour() == 13){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x8000);
		}else{
			setValue(0x8001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x8002);
		}else{
			setValue(0x8003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x8004);
		}else{
			setValue(0x8005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x8008);
		}else{
			setValue(0x8009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x8010);
		}else{
			setValue(0x8011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x8020);
		}else{
			setValue(0x8021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x8040);
		}else{
			setValue(0x8041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x8080);
		}else{
			setValue(0x8081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x8100);
		}else{
			setValue(0x8101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x8200);
		}else{
			setValue(0x8201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x8400);
		}else{
			setValue(0x8401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x8800);
		}else{
			setValue(0x8801);
		}
	}
}
else if (hour() == 2 || hour() == 14){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x4000);
		}else{
			setValue(0x4001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x4002);
		}else{
			setValue(0x4003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x4004);
		}else{
			setValue(0x4005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x4008);
		}else{
			setValue(0x4009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x4010);
		}else{
			setValue(0x4011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x4020);
		}else{
			setValue(0x4021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x4040);
		}else{
			setValue(0x4041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x4080);
		}else{
			setValue(0x4081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x4100);
		}else{
			setValue(0x4101);
		}
	}
	while (minute() < 50){
                digitalClockDisplay();
		if (second() % 2 == 0){
			setValue(0x4200);
		}else{
			setValue(0x4201);                        
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x4400);
                        delay(500);
		}else{
			setValue(0x4401);
                        delay(500);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x4800);
                        delay(500);
		}else{
			setValue(0x4801);
                        delay(500);
		}
	}
}
else if (hour() == 3 || hour() == 15){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0xC000);
		}else{
			setValue(0xC001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0xC002);
		}else{
			setValue(0xC003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0xC004);
		}else{
			setValue(0xC005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0xC008);
		}else{
			setValue(0xC009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0xC010);
		}else{
			setValue(0xC011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0xC020);
		}else{
			setValue(0xC021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0xC040);
		}else{
			setValue(0xC041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0xC080);
		}else{
			setValue(0xC081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0xC100);
		}else{
			setValue(0xC101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0xC200);
		}else{
			setValue(0xC201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0xC400);
		}else{
			setValue(0xC401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0xC800);
		}else{
			setValue(0xC801);
		}
	}
}
else if (hour() == 4 || hour() == 16){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x2000);
		}else{
			setValue(0x2001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x2002);
		}else{
			setValue(0x2003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x2004);
		}else{
			setValue(0x2005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x2008);
		}else{
			setValue(0x2009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x2010);
		}else{
			setValue(0x2011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x2020);
		}else{
			setValue(0x2021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x2040);
		}else{
			setValue(0x2041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x2080);
		}else{
			setValue(0x2081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x2100);
		}else{
			setValue(0x2101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x2200);
		}else{
			setValue(0x2201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x2400);
		}else{
			setValue(0x2401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x2800);
		}else{
			setValue(0x2801);
		}
	}
}
else if (hour() == 5 || hour() == 17){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0xA000);
		}else{
			setValue(0xA001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0xA002);
		}else{
			setValue(0xA003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0xA004);
		}else{
			setValue(0xA005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0xA008);
		}else{
			setValue(0xA009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0xA010);
		}else{
			setValue(0xA011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0xA020);
		}else{
			setValue(0xA021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0xA040);
		}else{
			setValue(0xA041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0xA080);
		}else{
			setValue(0xA081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0xA100);
		}else{
			setValue(0xA101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0xA200);
		}else{
			setValue(0xA201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0xA400);
		}else{
			setValue(0xA401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0xA800);
		}else{
			setValue(0xA801);
		}
	}
}
else if (hour() == 6 || hour() == 18){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x6000);
		}else{
			setValue(0x6001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x6002);
		}else{
			setValue(0x6003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x6004);
		}else{
			setValue(0x6005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x6008);
		}else{
			setValue(0x6009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x6010);
		}else{
			setValue(0x6011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x6020);
		}else{
			setValue(0x6021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x6040);
		}else{
			setValue(0x6041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x6080);
		}else{
			setValue(0x6081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x6100);
		}else{
			setValue(0x6101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x6200);
		}else{
			setValue(0x6201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x6400);
		}else{
			setValue(0x6401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x6800);
		}else{
			setValue(0x6801);
		}
	}
}
else if (hour() == 7 || hour() == 19){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0xE000);
		}else{
			setValue(0xE001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0xE002);
		}else{
			setValue(0xE003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0xE004);
		}else{
			setValue(0xE005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0xE008);
		}else{
			setValue(0xE009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0xE010);
		}else{
			setValue(0xE011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0xE020);
		}else{
			setValue(0xE021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0xE040);
		}else{
			setValue(0xE041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0xE080);
		}else{
			setValue(0xE081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0xE100);
		}else{
			setValue(0xE101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0xE200);
		}else{
			setValue(0xE201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0xE400);
		}else{
			setValue(0xE401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0xE800);
		}else{
			setValue(0xE801);
		}
	}
}
else if (hour() == 8 || hour() == 20){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x1000);
		}else{
			setValue(0x1001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x1002);
		}else{
			setValue(0x1003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x1004);
		}else{
			setValue(0x1005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x1008);
		}else{
			setValue(0x1009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x1010);
		}else{
			setValue(0x1011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x1020);
		}else{
			setValue(0x1021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x1040);
		}else{
			setValue(0x1041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x1080);
		}else{
			setValue(0x1081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x1100);
		}else{
			setValue(0x1101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x1200);
		}else{
			setValue(0x1201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x1400);
		}else{
			setValue(0x1401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x1800);
		}else{
			setValue(0x1801);
		}
	}
}
else if (hour() == 9 || hour() == 21){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x9000);
		}else{
			setValue(0x9001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x9002);
		}else{
			setValue(0x9003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x9004);
		}else{
			setValue(0x9005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x9008);
		}else{
			setValue(0x9009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x9010);
		}else{
			setValue(0x9011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x9020);
		}else{
			setValue(0x9021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x9040);
		}else{
			setValue(0x9041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x9080);
		}else{
			setValue(0x9081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x9100);
		}else{
			setValue(0x9101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x9200);
		}else{
			setValue(0x9201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x9400);
		}else{
			setValue(0x9401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x9800);
		}else{
			setValue(0x9801);
		}
	}
}
else if (hour() == 10 || hour() == 22){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x5000);
		}else{
			setValue(0x5001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x5002);
		}else{
			setValue(0x5003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x5004);
		}else{
			setValue(0x5005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x5008);
		}else{
			setValue(0x5009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x5010);
		}else{
			setValue(0x5011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x5020);
		}else{
			setValue(0x5021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x5040);
		}else{
			setValue(0x5041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x5080);
		}else{
			setValue(0x5081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x5100);
		}else{
			setValue(0x5101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x5200);
		}else{
			setValue(0x5201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x5400);
		}else{
			setValue(0x5401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x5800);
		}else{
			setValue(0x5801);
		}
	}
}
else if (hour() == 11 || hour() == 23){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0xD000);
		}else{
			setValue(0xD001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0xD002);
		}else{
			setValue(0xD003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0xD004);
		}else{
			setValue(0xD005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0xD008);
		}else{
			setValue(0xD009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0xD010);
		}else{
			setValue(0xD011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0xD020);
		}else{
			setValue(0xD021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0xD040);
		}else{
			setValue(0xD041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0xD080);
		}else{
			setValue(0xD081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0xD100);
		}else{
			setValue(0xD101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0xD200);
		}else{
			setValue(0xD201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0xD400);
		}else{
			setValue(0xD401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0xD800);
		}else{
			setValue(0xD801);
		}
	}
}
else if (hour() == 12){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x3000);
		}else{
			setValue(0x3001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x3002);
		}else{
			setValue(0x3003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x3004);
		}else{
			setValue(0x3005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x3008);
		}else{
			setValue(0x3009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x3010);
		}else{
			setValue(0x3011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x3020);
		}else{
			setValue(0x3021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x3040);
		}else{
			setValue(0x3041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x3080);
		}else{
			setValue(0x3081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x3100);
		}else{
			setValue(0x3101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x3200);
		}else{
			setValue(0x3201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x3400);
		}else{
			setValue(0x3401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x3800);
		}else{
			setValue(0x3801);
		}
	}
}

 
}


// Get user input from serial terminal
void serialRead() {
  char inData[MAX_TERMINAL_LINE_LEN]; // allocate space for incoming serial string
  byte index = 0; // Index into array, where to store chracter
  char inChar; // Where to store the character to read

  // fills up characters from the terminal, leaving room for null terminator
  while ( index < MAX_TERMINAL_LINE_LEN - 1 && Serial.available() > 0){
    inChar = Serial.read();
    if (inChar == '\r'){
      inData[index] = '\0';
      break;
    } else {
      inData[index] = inChar;
      index++;
    }
  }

  if (index > 0){ // if we read some data, then process it
    Serial.println(inData);
    handleSerialData(inData, index);
    printPrompt();
  }

}


// Handle received commands from user obtained via the serial termina
void handleSerialData(char inData[], byte index) {
  // tokenize the input from the terminal by spaces
  char * words[MAX_TERMINAL_WORDS];
  byte current_word_index = 0;
  char * p = strtok(inData, " ");
  while(p != NULL) {
    words[current_word_index++] = p;
    p = strtok(NULL, " ");
  }

  if (strcmp(words[0], "help") == 0) {
    printHelpText();

  } else if (strcmp(words[0], "send") == 0) {
    // checks if address field was given valid characters
    if ((strspn(words[1], "1234567890AaBbCcDdEeFf") <= 4)
        && (strspn(words[1], "1234567890AaBbCcDdEeFf") > 0)) {

      uint16_t TOaddr = strtol(words[1], NULL, 16);

      if (strncmp(words[2], "-p", 2) == 0) { // Send ping
        struct payload myPayload = {PING, '\0', {'\0'}};
        size_t len = sizeof(PING) + sizeof('\0') * 2;

        radio.stopListening();
        radio.openWritingPipe(TOaddr);
        radio.write(&myPayload, len);
        radio.startListening();

      } else if (strcmp(words[2], "-l") == 0) { // Send LED pattern
        if (strspn(words[3], "1234567890") == 1) {
          byte led_patt = (byte) atoi(words[3]);
          struct payload myPayload = {LED, led_patt, {'\0'}};
          size_t len = sizeof(LED) + sizeof(led_patt) + sizeof('\0');

          radio.stopListening();
          radio.openWritingPipe(TOaddr);
          radio.write(&myPayload, len);
          radio.startListening();
        }

        else {
          Serial.println("  Invalid LED pattern field.");
        }

      } else if (strcmp(words[2], "-m") == 0) { // Send message
        char str_msg[MAX_TERMINAL_MESSAGE_LEN];

        char * curr_pos = str_msg;
        for (int i = 3; i < current_word_index; i++){
          byte curr_len = strlen(words[i]);
          strncpy(curr_pos, words[i], curr_len);
          curr_pos += curr_len;

          // this will add in the space characters that tokenizing removes
          if (i < current_word_index - 1){
            strncpy(curr_pos, " ", 1);
            curr_pos++;
          }
        }

        struct payload myPayload = {MESS, '\0', {}};

        // the end of the string minus the start of the string gives the length
        memcpy(&myPayload.message, str_msg, curr_pos - str_msg);
        Serial.println(myPayload.message);
        radio.stopListening();
        radio.openWritingPipe(TOaddr);
        radio.write(&myPayload, sizeof(myPayload));
        radio.startListening();
      }

      else {
        Serial.println("  Invalid command field.");
      }
    }

    else {
      Serial.println("  Invalid address field.");
    }

  } else if (strcmp(words[0], "channel") == 0) {

    // Set radio channel
    byte chn = (byte) atoi(words[1]);

    if (chn >= 0 && chn <= 83) {
      Serial.print("Channel is now set to ");
      Serial.println(chn);
      radio.setChannel(chn);
    } else {
      Serial.println(" Invalid channel number. Legal channels are 0 - 83.");
    }

  } else if (strcmp(words[0], "radio") == 0) {
    // Turn radio listening on/off
    if (strcmp(words[1], "on") == 0) {
      Serial.println("Radio is now in listening mode");
      radio.startListening();
    } else if (strcmp(words[1], "off") == 0) {
      Serial.println("Radio is now NOT in listening mode");
      radio.stopListening();
    } else {
      Serial.println(" Invalid syntax.");
    }
  }
}


// Grab message received by nRF for this node
void handlePayload(struct payload * myPayload) {
  switch(myPayload->command) {

    case PING:
      Serial.println("Someone pinged us!");
      printPrompt();
      break;

    case LED:
      ledDisplay(myPayload->led_pattern);
      break;

    case MESS:
      Serial.print("Message:\r\n  ");
      Serial.println(myPayload->message);
      printPrompt();
      break;

    case DEMO:
      displayDemo();
      break;

    default:
      Serial.println(" Invalid command received.");
      break;
  }
  free(myPayload); // Deallocate payload memory block
}

void printPrompt(void){
  Serial.print("> ");
}

/*
// Display LED pattern

// LED numbering:

           9
       8       10
     7           11
   6               12
  5                 13
   4               14
     3           15
       2       16
           1

shift register 1-8: AA
shift register 9-16: BB

setValue data in hex: 0xAABB
where AA in binary = 0b[8][7][6][5][4][3][2][1]
      BB in binary = 0b[16][15][14][13][12][11][10][9]

*/
void ledDisplay(byte pattern) {
  setValue(0x0000);
  digitalWrite(SROEPin, LOW);
  if(pattern == 0) {
    word pattern = 0x0000; // variable used in shifting process
    int del = 62; // ms value for delay between LED toggles

    for(int i=0; i<16; i++) {
      pattern = (pattern << 1) | 0x0001;
      setValue(pattern);
      delay(del);
    }

    for(int i=0; i<16; i++) {
      pattern = (pattern << 1);
      setValue(pattern);
      delay(del);
    }
  }
  else if(pattern == 1) {
    word pattern = 0x0000; // variable used in shifting process
    int del = 62; // ms value for delay between LED toggles

    for (int i = 0; i < 16; i++) {
      pattern = (pattern >> 1) | 0x8000;
      setValue(pattern);
      delay(del);
    }
    for (int i=0; i<16; i++) {
      pattern = (pattern >> 1);
      setValue(pattern);
      delay(del);
    }
  }
  else if(pattern == 2) {
    int del = 100;
    setValue(0x1010);
    delay(del);
    setValue(0x3838);
    delay(del);
    setValue(0x7C7C);
    delay(del);
    setValue(0xFEFE);
    delay(del);
    setValue(0xFFFF);
    delay(del);
    setValue(0xEFEF);
    delay(del);
    setValue(0xC7C7);
    delay(del);
    setValue(0x8383);
    delay(del);
    setValue(0x0101);
    delay(del);
    setValue(0x0000);
    delay(del);
  }
  else if(pattern == 3) {
    word pattern = 0x0101;
    int del = 125;
    setValue(pattern);
    for(int i=0; i<8; i++) {
      delay(del);
      pattern = (pattern << 1);
      setValue(pattern);
    }
  }
  else if(pattern == 4) {
    for (int i = 0; i < 4; i++) {
      setValue(0xFFFF);
      delay(125);
      setValue(0x0000);
      delay(125);
    }
  }
  digitalWrite(SROEPin, HIGH);
}


// LED display demo
void displayDemo() {
  digitalWrite(SROEPin, LOW);
  for (int i = 0; i < 100; i++) {
    setValue(0xAAAA);
    delay(125);
    setValue(0x5555);
    delay(125);
  }
  digitalWrite(SROEPin, HIGH);
}

// Sends word sized value to both SRs & latches output pins
void setValue(word value) {
  byte Hvalue = value >> 8;
  byte Lvalue = value & 0x00FF;
  SPI.transfer(Lvalue);
  SPI.transfer(Hvalue);
  digitalWrite(SRLatchPin, HIGH);
  digitalWrite(SRLatchPin, LOW);
}

// Prints 'help' command
void printHelpText() {
  Serial.println("Available commands:");
  Serial.println("  help          - displays commands list.");
  Serial.println();
  Serial.println("  send [addr] [command] [data] - send packets to other node.");
  Serial.println("      [addr]    - address of destination node, as a 4 digit hex value");
  Serial.println("      [command] - command field.");
  Serial.println("        -p - ping destination node.");
  Serial.println("        -l - send LED pattern to destination node.");
  Serial.println("           - [data] - LED pattern. Valid range: 0-255.");
  Serial.println("        -m - send message to destination node.");
  Serial.println("           - [data] - message to be sent. Max 26 characters.");
  Serial.println();
  Serial.println("  channel [val] - change channel of your node.");
  Serial.println("                - [val] - new channel. Valid range: 0-83.");
  Serial.println();
  Serial.println("  radio [on | off] - turn radio on or off");
}

void welcomeMessage(void) {
  char hex_addr[10];
  sprintf(hex_addr, "%04x", this_node_address);
  Serial.print("\r\nWelcome to the BoilerMake Hackathon Badge Network...\r\n\n");
  Serial.print("Your address: ");
  Serial.println(hex_addr);
  Serial.print("\nAll commands must be terminated with a carriage return.\r\n"
      "Type 'help' for a list of available commands.\r\n\n> ");
}

void processSyncMessage() {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if(Serial.find(TIME_HEADER)) {
     pctime = Serial.parseInt();
     if( pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
       setTime(pctime); // Sync Arduino clock to the time received on the serial port
     }
  }
}

time_t requestSync()
{
  Serial.write(TIME_REQUEST);  
  return 0; // the time will be sent later in response to serial mesg
}

void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}


