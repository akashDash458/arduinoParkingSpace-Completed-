
/**This Arduino project uses Arduino Mega 2560 for a 3x2 parking system.
 * It uses ultrasonic sensors to detect cars, servo motors to open and close gate after scanning Rfid card.
 * Display is taken care by a 16x2 lcd panel and LCDs to show parking status of each slot.  
 * 
 */
#include <LiquidCrystal.h>  

LiquidCrystal lcd(28, 27, 25, 24, 23, 22); 

int slot[2][3]={{1,0,0},{1,0,1}};
int ledMatrix[2][3] = { {43,  44,  45  }, {46,  47,  48  } };   
//the matrix will hold the pin assignments for the LED
int Contrast=50;      //Instead of using potentiometer, I ve manually set the contrast
/*Initialse all the variables and have the slot set to zero by default
 * When slot is full have the sensor send voltage change to the ide and result will change.
 */
int row = 2,col=3,flag = 1;   //declare the variables

#define t1 31
#define t2 32 
#define t3 33 
#define t4 34 
#define t5 35 
#define t6 36
#define e1 37
#define e2 38 
#define e3 39
#define e4 40
#define e5 41
#define e6 42
  

 void setup()
 { 
    setupLCD();
    setupUltrasonic();
    setupLED();
 }

   
void setupLCD()
{
    analogWrite(26,Contrast);  //To set the contrast
    lcd.begin(16, 2);         //To setup no. of columns and rows of lcd panel
    lcd.print("hello, world!");
    //pinMode(30, OUTPUT);       //Set pin 9 as output for brightness
    //analogWrite(30,20);        //Set brightness as 50 (0-255)

}

void setupUltrasonic()
{
  Serial.begin(9600);
  pinMode(t1,OUTPUT);
  pinMode(t2,OUTPUT);
  pinMode(t3,OUTPUT);
  pinMode(t4,OUTPUT);
  pinMode(t5,OUTPUT);
  pinMode(t6,OUTPUT);
  pinMode(e1,INPUT);
  pinMode(e2,INPUT);
  pinMode(e3,INPUT);
  pinMode(e4,INPUT);
  pinMode(e5,INPUT);
  pinMode(e6,INPUT);
}

void setupLED()
{
  //Initialse the LED's
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      pinMode(ledMatrix[i][j], OUTPUT);
 
    } 
  }
}
 

//This part needs to be  changed once we combine the project  
void loop()
 {  
     dispGateOpen();
     
     dispGateClose();
     updateSlot();
 }
//Invoked when the gate opens
void dispGateOpen()
{
  lcd.clear();
  lcd.print("<<OPENING GATE>>");
  delay(3000); 
   
}

////Invoked when the gate closes
void dispGateClose()
{
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("<<CLOSING GATE>>");
  delay(3000);
  dispParkingStatus();
  
  calcNearest();  
 }


//This function shows the current parking status. LED status to be added later.
void dispParkingStatus()
{
  lcd.clear();
  lcd.print("Parking Status :");
  delay(1000);
  lcd.clear();
  
  int i,j;
  
  for(i=0;i<row;i++)
   { 
    lcd.setCursor(0,i);
    for(j=0;j<col;j++)
    {
      if(slot[i][j]==1)
        {
          lcd.print("  X  ");
          
        }
      else
        {
          lcd.print("  ");
          lcd.print((char)(j+65));
          lcd.print(i+1);
          lcd.print(" ");       
          
        }
    } 
  }
   delay(3000); 
    
}

void calcNearest()
{
  int i,j;
  for(j=0;j<col;j++)//loop across columns
   for(i=0;i<row;i++)      //loop across rows
     {
      if(slot[i][j]==0)//check availability of slot
      {
         flag=0;             //tells that empty slot is there
        dispNearest(i,j);        //send index to display panel
         return ;
      }
     }
  
    
  if(flag==1)            //if no spot is found
    dispFull();       //slot not found
    
    
}

//This function shows nearest slot after taking parameters from calculateNearest function
void dispNearest(int r,int c)
{
  lcd.clear();
  
  lcd.print("Nearest slot: ");
  lcd.print((char)(c+65));
  lcd.print(r+1);
  
  float distance = 4.0 + 2.5*c;
    
  lcd.setCursor(0,1);
  lcd.print("Distance :");
  lcd.print(distance);
  lcd.print(" m");
  delay(3000); 
  
}

void dispFull()
{
  lcd.clear();  
  lcd.print("ALL SLOTS TAKEN!");  
   delay(3000); 
}

void updateSlot()
{
  int ti1,ti2,ti3,ti4,ti5,ti6;
  int arr_ti[6]={ti1,ti2,ti3,ti4,ti5,ti6};//declared the array of ti
  int arr_e[6]={e1,e2,e3,e4,e5,e6};//declared the array of e
  int arr_t[6]={t1,t2,t3,t4,t5,t6};//declared the array of t
  int i=0,j=0,k=1;//declared counter variables 
  int row=2,col=3;//size of parking space
  
   for(j=0;j<col;i++)//loop across columns
    {
     for(i=0;i<row;i++)      //loop across rows
     {
      digitalWrite(arr_t[n],HIGH);
      delay(100);
      digitalWrite(arr_t[n],LOW);
      arr_ti[n]=pulseIn(arr_e[n],HIGH);
      slot[i][j]=arr_ti[n]/58.2;
      if(slot[i][j]<=10)
      {
        slot[i][j]=1;
        digitalWrite(ledMatrix[i][j], HIGH);
      }
      else
      {
        slot[i][j]=0;
        digitalWrite(ledMatrix[i][j], LOW);
      }
      k++;
    }
  }
  /*
  digitalWrite(t1,HIGH);
  delay(100);
  digitalWrite(t1,LOW);
  ti1=pulseIn(e1,HIGH);
  slot[0][0]=ti1/58.2;
  
  digitalWrite(t2,HIGH);
  delay(100);
  digitalWrite(t2,LOW);
  ti2=pulseIn(e2,HIGH);
  slot[0][1]=ti2/58.2;

  digitalWrite(t3,HIGH);
  delay(100);
  digitalWrite(t3,LOW);
  ti3=pulseIn(e3,HIGH);
  slot[0][2]=ti3/58.2;

  digitalWrite(t4,HIGH);
  delay(100);
  digitalWrite(t4,LOW);
  ti4=pulseIn(e4,HIGH);
  slot[1][0]=ti4/58.2;

   digitalWrite(t5,HIGH);
  delay(100);
  digitalWrite(t5,LOW);
  ti5=pulseIn(e5,HIGH);
  slot[1][1]=ti5/58.2;

   digitalWrite(t6,HIGH);
  delay(100);
  digitalWrite(t6,LOW);
  ti6=pulseIn(e6,HIGH);
  slot[1][2]=ti6/58.2;
  */
}


