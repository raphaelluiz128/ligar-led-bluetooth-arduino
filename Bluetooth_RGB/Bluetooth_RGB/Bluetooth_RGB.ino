#include <SoftwareSerial.h>

int red = 8, green = 9, blue = 10;
char rec;
SoftwareSerial bluetoothBridge(2,3);

void setup()
{
  bluetoothBridge.begin(9600);
  bluetoothBridge.println("Connection established");
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{
  rec = bluetoothBridge.read();
  switch(rec)
  {
    case '0':
      ligarLed(red, "Red on");
    break;
    case '1':
      desligarLed(red, "Red off");
    break;
    case '2':
      ligarLed(green, "Green on");
    break;
    case '3':
      desligarLed(green, "Green off");
    break;
    case '4':
      ligarLed(blue, "Blue on");
    break;
    case '5':
      desligarLed(blue, "Blue off");
    break;
  }
}

void ligarLed(int ledValue, const char* message)
{
  digitalWrite(ledValue, HIGH);
  bluetoothBridge.println(message);
}

void desligarLed(int ledValue, const char* message)
{
  digitalWrite(ledValue, LOW);
  bluetoothBridge.println(message);
}

