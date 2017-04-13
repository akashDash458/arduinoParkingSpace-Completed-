#include <LiquidCrystal.h>  
int Contrast=30;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   

 void setup()
 { 
    analogWrite(6,Contrast);
    lcd.begin(16, 2);
    lcd.print("hello, world!");

  }  
void loop()
 {  
     lcd.setCursor(0, 0);
        
 }

void gateOpen()
{
  lcd.clear();
  lcd.print("OPENING GATE");
  delay(2500); 
}

void gateClose()
{
  lcd.clear();
  lcd.print("CLOSING GATE");
  delay(2500); 
  update(2500);
  parkingStatus();
 }

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

