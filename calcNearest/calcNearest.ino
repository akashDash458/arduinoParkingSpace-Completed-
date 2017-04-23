/*Initialse all the variables and have the slot set to zero bydefault
 * When slot is full have the sensor send voltage change to the ide and result will change.
 */
int row=2,col=3,flag=1;   //declare the variables
int slot[2][3];   //declare the slot as 2d array

void setup() {
  // put your setup code here, to run once:
  
}

void loop() 
{
    calcNearest();
}

void calcNearest()
{
  int i,j;
  for(j=0;j<col;j++)//loop across columns
    {
     for(i=0;i<row;i++)      //loop across rows
     {
      if(slot[i][j]==0)//check availability of slot
      {
         flag=0;             //tells that empty slot is there
         break;         //break out of the loop
      }
     }
    }
    
  if(flag==1)            //if no spot is found
    dispFull();       //slot not found
    
  else
    dispNearest(i,j);        //send index to display panel
   
}

