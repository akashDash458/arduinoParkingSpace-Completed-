/**This Arduino project uses Arduino Mega 2560 for a 3x2 parking system.
 * It uses ultrasonic sensors to detect cars, servo motors to open and close gate after scanning Rfid card.
 * Display is taken care by a 16x2 lcd panel and LCDs to show parking status of each slot. * 
 * 
 */
#include <LiquidCrystal.h>  
int Contrast=10;
//Instead of using potentiometer, I ve manually set the contrast
LiquidCrystal lcd(28, 27, 25, 24, 23, 22);   
 int slot[2][3]={{0,1,0},{1,0,0}};
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
  dispNearest(0,0); 
  
 }

//This function shows the current parking status. LED status to be added later.
void dispParkingStatus()
{
  lcd.clear();
  lcd.print("Parking Status :");
  delay(1000);
  lcd.clear();
  int rows=2,columns=3;
  int i,j;
  
  for(i=0;i<rows;i++)
   { 
    lcd.setCursor(0,i);
    for(j=0;j<columns;j++)
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


//This function shows nearest slot after taking parameters from calculateNearest function
void dispNearest(int r,int c)
{
  lcd.clear();
  
  lcd.print("Nearest slot: ");
  char row=(char)(r+65);
  int col =c+1;
  float distance = 4.0 + 2.5*c;
  lcd.print(row);
  lcd.print(col);
  
  lcd.setCursor(0,1);
  lcd.print("Distance :");
  lcd.print(distance);
  lcd.print(" m");
  delay(3000); 
  loop();  
}

void dispFull();
{
  lcd.clear();  
  lcd.print("ALL SLOTS TAKEN");  
}

