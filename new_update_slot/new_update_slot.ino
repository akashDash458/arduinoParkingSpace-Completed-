int slot[2][3];

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

//the matrix will hold the pin assignments for the led
 
int ledMatrix[2][3] = {
 
  {43,  44,  45  },
  {46,  47,  48  }
};
void setup()
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

  //Initialse the LED's
  for(int i = 0; i < 2; i++){
 
    for(int j = 0; j < 3; j++){
 
      pinMode(ledMatrix[i][j], OUTPUT);
 
    }//close for i
 
  }//close for j
}


void loop()
{
  /*
   * Changes made:-
   * 1)Removed the array of ti's and integer of ti's and replaced them by required ones.
   * 2)Added some comments and indented the code.
   * 
   * Error showing:- lcd was not declared in scope.
   * 
   * Please remove this comment after this has served its purpose.
   */
  int arr_e[6]={e1,e2,e3,e4,e5,e6};//declared the array of echo
  int arr_t[6]={t1,t2,t3,t4,t5,t6};//declared the array of transmitter
  int i=0,j=0,k=1;//declared counter variables 
  int row=2,col=3;//size of parking space
  int n=0;//initialse the index of array to be zero
  float dist=0.0,dur=0.0;
  
   for(j=0;j<col;j++)//loop across columns
    {
     for(i=0;i<row;i++)      //loop across rows
     {
      digitalWrite(arr_t[n], LOW);//set the LED off
      delayMicroseconds(2);
      lcd.clear();
      lcd.print("col=");
      lcd.print(j);
      lcd.print(" row=");
      lcd.print(i);
      delay(1000);//waits for a second
      digitalWrite(arr_t[n],HIGH);
      delayMicroseconds(10);
      digitalWrite(arr_t[n],LOW);
      dur=pulseIn(arr_e[n],HIGH);//store the length of pulse for pin
      dist = dur*.034/2;
      if(dist<=5&&dist>0)//check if slot is empty or full
      {
        slot[i][j]=1;//indicate that the slot is filled
        digitalWrite(ledMatrix[i][j], HIGH);//set led on for that slot 
        lcd.setCursor(0,1);
        lcd.print(dist);
        delay(1000);
      }
      else
      {
        slot[i][j]=0;//indicates the slot is empty
        digitalWrite(ledMatrix[i][j], LOW);//set led off for that slot 
      }
      n++;//increment the index of arrays e and t
    }

}

int updateSlot(int i,int j)
{
  return slot[i][j];
}

