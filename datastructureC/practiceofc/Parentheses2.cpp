#include<iostream> 
#include<string>
#include<cstdlib>
using namespace std;
class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
                     // 需要先宣告
class ListNode{
    
   public:
    char data;
    ListNode *next;
    ListNode():data(0),next(0){};
    ListNode(char a):data(a),next(0){};

    friend class LinkedList;
};   
class LinkedList{
  public:
    ListNode *first;            // list的第一個node
    LinkedList():first(0){};
};
void isValid();  //檢查是否符合 
bool isLeftParentheses(char);    //是否為左
bool isRightParentheses(char);   //是否為右
char getParenthesesPair(char); 
char pop();
void push(char);
int sizeofstack=0;
string s;
LinkedList stack;  //宣告stack 
int main()
{
  cout<<"Please input a string:"<<"\n";
  cin>>s;
  isValid();
}
void push(char c) //stack push 功能
{
    sizeofstack++;
    ListNode *newNode = new ListNode(c);   // 配置新的記憶體
    newNode->next = stack.first;                 
    stack.first = newNode;                       
}
char pop()   //stack pop 功能
{
   char v;
   if(sizeofstack==0)
  {
     cout<<"the stack empty"<<"\n";
  }
   v=stack.first->data;
   stack.first=stack.first->next;
   sizeofstack--;
   return v;   
}
void isValid() 
{
    char before[100]={'\0'};
    for(int i=0; i<s.length();i++ ) 
   {        
           if (isLeftParentheses(s.at(i))) 
          {
            push(s.at(i));
          } 
           else if(isRightParentheses(s.at(i))) 
          {        
            if (sizeofstack==0&&before[0]=='\0') 
              {
                 cout<<"Error!! You should add "<<getParenthesesPair(s.at(i))<<"right before"<<s.at(i)<<"!!";
                 return ;
              }
             if(sizeofstack==0&&before[0]!='\0')
               {
                 cout<<"Error!! You should add "<<getParenthesesPair(s.at(i))<<"right after"<<before<<"!!";
                 return ;
               } 
            char pair =pop();
            char ch = getParenthesesPair(s.at(i));
            if ( pair != ch )
              {
                  cout<<"Error!! You should add "<<getParenthesesPair(pair)<<"right after"<<before<<"!!";
                  return ;
              }
           }
      before[i]=s.at(i);
    }    
    if(sizeofstack>0) //檢查有沒有落單的左括號
       {
        cout<<"Error!! You should add "<<pop()<<"right after"<<before<<"!!";
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




















    
