#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
void isValid(string,char *); 
bool isLeftParentheses(char); 
bool isRightParentheses(char); 
char getParenthesesPair(char); 
char pop(char *);
void push(char,char *);
int sizeofstack=-1;
string s;
int main()
{
  char stack[100]={'\0'};  //靜態stack
  cout<<"Please input a string:"<<"\n";
  cin>>s;
  isValid(s,stack);
}
void push(char c,char stack[]) //stack push 功能
{
  if(sizeofstack==100)
 {
   cout<<"overflow!"<<"\n";  
 } 
  sizeofstack++;
  stack[sizeofstack]=c;
}
char pop(char stack[])   //stack pop 功能
{
   char v;
   if(sizeofstack==-1)
  {
     cout<<"the stack of empty"<<"\n";
  } 
   v=stack[sizeofstack];
   sizeofstack--;
   return v;   
}
void isValid(string s,char stack[]) 
  {
    char before[100]={'\0'};
    for(int i=0; i<s.length();i++ ) 
    {        
           if (isLeftParentheses(s.at(i))) 
          {
            push(s.at(i),stack);
          } 
           else if(isRightParentheses(s.at(i))) 
          {            
            if (sizeofstack<0&&before[0]=='\0') 
              {
                 cout<<"Error!! You should add "<<getParenthesesPair(s.at(i))<<"right before"<<s.at(i)<<"!!";
                 return ;
              }
             if(sizeofstack<0&&before[0]!='\0')
               {
                 cout<<"Error!! You should add "<<getParenthesesPair(s.at(i))<<"right after"<<before<<"!!";
                 return ;
               } 
            char pair =pop(stack);
            char ch = getParenthesesPair(s.at(i));
            if ( pair != ch )
              {
                  cout<<"Error!! You should add "<<getParenthesesPair(pair)<<"right after"<<before<<"!!";
                  return ;
              }
           }
      before[i]=s.at(i);
    }    
    if(sizeofstack>=0) //檢查有沒有落單的左括號
       {
        cout<<"Error!! You should add "<<stack[sizeofstack]<<"right after"<<before<<"!!";
        return ;
       }
    cout<<"OK! The string "<<before<<" passed the check!!";
    return ;
 }
bool isLeftParentheses(char c) {
    if ( c == '[' || c == '{' || c == '(')
        return true;
    return false;
}
bool isRightParentheses(char c) {
    if ( c==']' || c=='}' || c==')' )
        return true;
    return false;
 }
char getParenthesesPair(char c) {  //幫它配對
    if ( c == ']' )
        return '[';
    else if ( c == '}' )
        return '{';
    else if ( c == ')' )
        return '(';
    else if( c == '{')
       return '}';
    else if ( c == '[' )
        return ']';
    else if ( c == '(' )
        return ')';

}




