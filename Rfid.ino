#include<SPI.h>
#include<Wire.h>
#include<MFRC522.h>
#include<Servo.h>


#define RST_PIN 9    
#define SS_PIN  10
#define STATE_SCAN_INVALID  3
#define STATE_SCAN_VALID    4



const int cardSize    = 4; //Declaring size of the array
byte slaveCard[cardSize] = {208,158,85,128};  //Slave card number
Servo myServo; // creating servo object
int servoPin=3; 
byte readCard[cardSize]; //To store the read data for checking
MFRC522 mfrc522(SS_PIN, RST_PIN); // creating object for rc522




int readCardState()
{
  int index;
  for(index = 0; index < 4; index++)
  {
    readCard[index] = mfrc522.uid.uidByte[index]; //Fetching data from card
  }
  if ((memcmp(readCard, slaveCard, 4)) == 0) //checking the data read and the data stored
  {
    return STATE_SCAN_VALID;
  }
 return STATE_SCAN_INVALID;
}
void setup() 
{
	setupServo();
}

void setupServo()
{
  SPI.begin();         // Init SPI Bus
  mfrc522.PCD_Init();  // Init MFRC522
  myServo.attach(servoPin);// Init Servo
  Serial.begin(9600);
}
void loop() 
{
	servo();
}

void servo()
{
  byte cardState; //Variable to store the value returned by readCardState function
  myServo.write(0); //Making servo to 0degrees initially
  cardState = readCardState(); //Fetching card state
  if(cardState==4)
  {
    myServo.write(70); //Rotating servo 70degrees
    delay(4000); //Delaying servo in 70 degrees state for 4 secs
    myServo.write(0); //Rotating servo to 0degrees
    }
}

