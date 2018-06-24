#include <SoftwareSerial.h>

int red = 13, green = 9, blue = 10;
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
      TurnLedOn(red, "Red on");
    break;
    case '1':
      TurnLedOff(red, "Red off");
    break;
    case '2':
      TurnLedOn(green, "Green on");
    break;
    case '3':
      TurnLedOff(green, "Green off");
    break;
    case '4':
      TurnLedOn(blue, "Blue on");
    break;
    case '5':
      TurnLedOff(blue, "Blue off");
    break;
  }
}

void TurnLedOn(int ledValue, const char* message)
{
  digitalWrite(ledValue, HIGH);
  bluetoothBridge.println(message);
}

void TurnLedOff(int ledValue, const char* message)
{
  digitalWrite(ledValue, LOW);
  bluetoothBridge.println(message);
}

