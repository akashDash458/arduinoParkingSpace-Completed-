/**This Arduino project uses Arduino Mega 2560 for a 3x2 parking system.
 * It uses ultrasonic sensors to detect cars, servo motors to open and close gate after scanning Rfid card.
 * Display is taken care by a 16x2 lcd panel and LCDs to show parking status of each slot.  
 * 
 */
#include <LiquidCrystal.h>  

LiquidCrystal lcd(28, 27, 25, 24, 23, 22); 

int slot[2][3]={{1,0,0},{1,0,1}};
int Contrast=50;      //Instead of using potentiometer, I ve manually set the contrast
/*Initialse all the variables and have the slot set to zero by default
 * When slot is full have the sensor send voltage change to the ide and result will change.
 */
int row = 2,col=3,flag = 1;   //declare the variables

  

 void setup()
 { 
    setupLCD();
 }

   
void setupLCD()
{
    analogWrite(26,Contrast);  //To set the contrast
    lcd.begin(16, 2);         //To setup no. of columns and rows of lcd panel
    lcd.print("hello, world!");
    //pinMode(30, OUTPUT);       //Set pin 9 as output for brightness
    //analogWrite(30,20);        //Set brightness as 50 (0-255)

}

//This part needs to be  changed once we combine the project  
void loop()
 {  
     dispGateOpen();
     
     dispGateClose();
    
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
         break;         //break out of the loop
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

