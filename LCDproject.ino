/**This Arduino project uses Arduino Mega 2560 for a 3x2 parking system.
 * It uses ultrasonic sensors to detect cars, servo motors to open and close gate after scanning Rfid card.
 * Display is taken care by a 16x2 lcd panel and LCDs to show parking status of each slot. * 
 * 
 */
 #include <LiquidCrystal.h>  
int Contrast=30;
//Instead of using potentiometer, I ve manually set the contrast
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   

 void setup()
 { 
    analogWrite(6,Contrast);  //To set the contrast
    lcd.begin(16, 2);         //To setup no. of columns and rows of lcd panel
    lcd.print("hello, world!");

  }  
//This part needs to be  changed once we combine the project  
void loop()
 {  
     lcd.setCursor(0, 0);
        
 }
//Invoked when the gate opens
void gateOpen()
{
  lcd.clear();
  lcd.print("OPENING GATE");
  delay(2500); 
}

////Invoked when the gate closes
void gateClose()
{
  lcd.clear();
  lcd.print("CLOSING GATE");
  delay(2500); 
  update(2500);
  parkingStatus();
 }

//This function shows the current parking status. LED status to be added later.
void parkingStatus()
{
  lcd.clear();
  int rows=2,columns=3;
  int i,j;
  for(i=0;i<columns;i++)
  {
    for(j=0;j<rows;j++)
    {
      if(slot[i][j]==1)
        lcd.print(".X.");
      else
        lcd.print("."+(char)(i+65)+(j+1)+".");   
    }
    lcd.setCursor(0,1);
  }
}

//This function shows nearest slot after taking parameters from calciulateNearest function
void displayNearest(int r,int c)
{
  lcd.clear();
  double distance = 4 + 2.5*(r+1);
  lcd.print("Nearest slot is: ");
  lcd.print((char)(c+65)+(r+1));
  lcd.setCursor(0,1);
  lcd.print("Distance = "+diatance+" metres");
  delay(5000);
}

