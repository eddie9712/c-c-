#include "reg51.h" 
void delay (int t); 
void turn ( );

 char step [ ] = {0x01,0x04,0x02,0x08}; 
int dir , dt;	//dir：方向	dt：時間間隔

void main ( )
{
 dt=3000;
 dir=1; 
 while(1) {
  dt-=3;  //加速
  turn(1);
  if(dt<=500) //改變方向
 {
   while(1)
  {
    dt+=3;//減速
    turn(2);
  }
 }
}
}

void turn( )
{
 int x;
 int y;
if(dir == 1){	//turn right 
   for(x=0;x<4;x++) { 
   P1=step[x];
   delay(dt);
}
}
if(dir==2)  //turn left
 {
    for(y=4;x>=0;y--)
   {
     P1=step[x];
     delay(dt);
   }
 }

}
void delay(int t)
{
int x; for(x=0;x<t;x++)
;
}
