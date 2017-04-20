int slot[3][2];

#define t1 1
#define t2 2 
#define t3 3 
#define t4 4 
#define t5 5 
#define t6 6
#define e1 7
#define e2 8 
#define e3 9
#define e4 10
#define e5 11
#define e6 12

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
}


void loop()
{
  int ti1,ti2,ti3,ti4,ti5,ti6;
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
  slot[1][0]=ti3/58.2;

  digitalWrite(t4,HIGH);
  delay(100);
  digitalWrite(t4,LOW);
  ti4=pulseIn(e4,HIGH);
  slot[1][1]=ti4/58.2;

   digitalWrite(t5,HIGH);
  delay(100);
  digitalWrite(t5,LOW);
  ti5=pulseIn(e5,HIGH);
  slot[2][0]=ti5/58.2;

   digitalWrite(t6,HIGH);
  delay(100);
  digitalWrite(t6,LOW);
  ti6=pulseIn(e6,HIGH);
  slot[2][1]=ti6/58.2;
}

int updateSlot(int i,int j)
{
  return slot[i][j];
}

