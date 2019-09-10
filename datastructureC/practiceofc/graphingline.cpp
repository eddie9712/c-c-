#include<iostream>
#include<cstdlib>
using namespace std;
int const number_rows=11;
int const number_cols=31;
struct point {
   int x;
   int y;
};
struct line{
    point p1;
    point p2;
};
void userinput(line &);
void graphline(char grid[number_rows][number_cols],line);
void print(char grid[number_rows][number_cols]);
void setbackground(char grid[][number_cols]);
int main()
{
  char grid[number_rows][number_cols]; 
  line line1;
  char doanother;
  setbackground(grid);  
  do{
    userinput(line1);  
    graphline(grid,line1);
    print(grid);
    cout<<"do you want ot add another line?";
    cin>>doanother;
  }while(doanother=='y');
  return 0;
}
void userinput(line &line1)
{
  do{
   cout<<"enter column p1:";
   cout<<"enter row p1:";
   cin>>line1.p1.x>>line1.p2.y;
  }while();
  do{

  }while();
}