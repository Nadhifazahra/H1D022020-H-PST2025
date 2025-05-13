#include <Arduino.h>
#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Nadhifa";
const char *password = "halohalo";

ESP8266WebServer server(80);
String webpage;

void setup()
{
  Serial.begin(9600);
  delay(10);

  pinMode(D0, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

  // CONNECT WIFI NETWORK
  Serial.println();
  Serial.print("Configuring Access Point");

  // Mengatur Wifi
  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid, password);

  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());

  // Halaman HTML sederhana
  webpage = "<html><head><title>ESP8266 Control</title></head><body>";
  webpage += "<h1>Kontrol LED</h1>";
  webpage += "<p>LED1: ";
  webpage += "<a href=\"LED1ON\"><button>ON</button></a><a href=\"LED1OFF\"><button>OFF</button></a></p><br>";
  webpage += "<p>LED2: ";
  webpage += "<a href=\"LED2ON\"><button>ON</button></a><a href=\"LED2OFF\"><button>OFF</button></a></p><br>";
  webpage += "<p>LED3: ";
  webpage += "<a href=\"LED3ON\"><button>ON</button></a><a href=\"LED3OFF\"><button>OFF</button></a></p><br>";

  // Membuat tampilan webpage
  server.on("/", []()
            { server.send(200, "text/html", webpage); });

  // Bagian ini untuk merespon perintah
  server.on("/LED1ON", []()
            {
    server.send(200, "text/html", webpage);
    digitalWrite(D0, HIGH);
    delay(100); });

  server.on("/LED2ON", []()
            {
    server.send(200, "text/html", webpage);
    digitalWrite(D2, HIGH);
    delay(100); });

  server.on("/LED3ON", []()
            {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, HIGH);
    delay(100); });

  server.on("/LED1OFF", []()
            {
    server.send(200, "text/html", webpage);
    digitalWrite(D0, LOW);
    delay(100); });

  server.on("/LED2OFF", []()
            {
    server.send(200, "text/html", webpage);
    digitalWrite(D2, LOW);
    delay(100); });

  server.on("/LED3OFF", []()
            {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, LOW);
    delay(100); });

  server.begin();
  Serial.print("Web server dijalankan");
}

void loop()
{
  server.handleClient();
}