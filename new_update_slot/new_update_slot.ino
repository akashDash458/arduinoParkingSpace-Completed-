

int slot[2][3]={{0,0,0},{0,0,0}};
int ledMatrix[2][3] = { {43,  44,  45  }, {46,  47,  48  } };


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
 

void setup()
{
  setupUltrasonic();
  setupLED();
 
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
 
    }//close for i
 
  }//close for j
}
 
void loop()
{
  updateSlot();
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


