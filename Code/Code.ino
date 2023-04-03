// Importing all the necessary libraries
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Wifi setup
const char* ssid = "your_ssid"; // Replace with your wifi SSID
const char* password = "your_password"; // Replace with your wifi password
WiFiClientSecure client;

// Initialize Telegram setup
#define BOTtoken "your_bot_token"  // your Bot Token (Get from Botfather)
#define CHAT_ID "your_chat_id"
UniversalTelegramBot bot(BOTtoken, client);


// Set pin numbers
const int buttonPin = 4;
const int ledPin =  5;

// variable for storing the pushbutton status 
int buttonState = 0;

void setup() {
  Serial.begin(115200);  
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(CHAT_ID, "Bot started up", "");
}

void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    digitalWrite(ledPin, HIGH);
    // send message from the bot
    bot.sendMessage(CHAT_ID, "Bing Bong, der Eiermann ist da!", ""); // the message is sent here, change it to whatever you like!

    // sleep for 500 ms 
    delay(500)
  } else {
    // turn LED off
    digitalWrite(ledPin, LOW);
  }
}
