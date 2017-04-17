/*Initialse all the variables and have the slot set to zero bydefault
 * When slot is full have the sensor send voltage change to the ide and result will change.
 */
int m=3,n=2,i=0,j=0,flag=1;   //declare the variables
int slot[3][2];   //declare the slot as 2d array

void setup() {
  // put your setup code here, to run once:
  
}

void loop(
  ) {
  // put your main code here, to run repeatedly:
    for(i=0;i<m;i++)
     for(j=0;j<n;j++)
     {
      //get the inputs here
     }
    for(i=0;i<m;i++)//loop across rows
    {
     for(j=0;j<n;j++)      //loop across columns
     {
      if(slot[i][j]==0)//check availability of slot
      {
       flag=0;             //tells that empty slot is there
       goto found;         //directs to the display function
      }
     }
    }
    if(flag==1)            //if no spot is found
    {
     print_it(flag);       //slot not found
    }
    else
    {
    found:
     print_it(i,j);        //send index to display panel
    }
}
