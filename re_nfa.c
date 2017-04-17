#include<iostream>
#include<stdio.h>
#include<string.h>
char reg[20];

using namespace std;
void postfix();
void e_nfa();
void disp(int,char,int);
int main(){
   cin>>reg; postfix();
    cout<<reg<<endl;
     e_nfa();
     return 0;
   }
void postfix(){
   char string[10],stack[10];
    int string_n=0,stack_n=0;
     int n=0; strcat(reg,"X");
      while(reg[n]!='\0') {
        switch(reg[n]) {
            case 'a' : string [string_n]='a';
            string_n++;  string[string_n]='\0';
            break;
            case 'b' : string[string_n]='b';
            string_n++;  string[string_n]='\0';
            break;
            case '*' : string[string_n]='*';
            string_n++;  string[string_n]='\0';
            break;
            case '(' :
            stack[stack_n]='(';
            stack_n++;
            break;
            case ')' : stack_n--;
            while(stack[stack_n]!='(')  {
              string[string_n]=stack[stack_n];
              stack[stack_n]='\0';
              string_n++;
              string[string_n]='\0';
              stack_n--;
            }
            stack[stack_n]='\0';

            break;
            case 'X' :
            while(stack_n!=0)  {
              stack_n--;
              string[string_n]=stack[stack_n];
              stack[stack_n]='\0';
              string_n++;
              string[string_n]='\0';
            }
            break;
            case '+' :
            if(stack[stack_n-1]!='+'&&stack[stack_n-1]!='.')  {
               stack[stack_n]='+';
               stack_n++;
                  stack[stack_n]='\0';
                   break;
                 }
                 else
                  {
                     string[string_n]=stack[stack_n-1];
                       string_n++;
                          stack[stack_n-1]='+';
                           break;
                          }
                          case '.' :
                          if(stack[stack_n-1]!='+'&&stack[stack_n-1]!='.')
                            {
                                stack[stack_n]='.';
                                  stack_n++;
                                     stack[stack_n]='\0';
                                       break;   }
                                          else
                                             {
                                                 string[string_n]=stack[stack_n-1];
                                                    string_n++;   stack[stack_n-1]='.';
                                                      break;
                                                     }
                                                       default:break;
                                                       }  n++;
                                                      }
                                                      strcpy(reg,string);
                                                     }void e_nfa(){
                                                       int strt[3],last[3],s,l;
                                                       int n=0,x=0,i=-1;
                                                        while(reg[n]!='\0')
                                                         {
                                                           switch(reg[n]) {
                                                              case 'a':i++;

strt[i]=x++;
  last[i]=x++;
  disp(strt[i],'a',last[i]);
   break;
   case 'b':i++;
   strt[i]=x++;
   last[i]=x++;
   disp(strt[i],'b',last[i]);
     break;
      case '+' : s=x++;
      l=x++;
      disp(s,'e',strt[i]);
       disp(s,'e',strt[i-1]);
         disp(last[i],'e',l);
         disp(last[i-1],'e',l);
         i--;
         strt[i]=s;
         last[i]=l;
         break;
         case '.' : disp(last[i-1],'e',strt[i]);
         last[i-1]=last[i];
         i--;
         break;
          case '*' : s=x++;
          l=x++;
          disp(s,'e',strt[i]);
          disp(s,'e',l);
          disp(last[i],'e',strt[i]);
          disp(last[i],'e',l);
          strt[i]=s;
          last[i]=l;
          break;
          default:break;
         } n++;
        } cout<<i<<" "<<strt[i]<<" "<<last[i];
      }
      void disp(int qs,char a,int qf){ cout<<qs<<"-->\t"<<a<<"-->\t"<<qf<<"\n";
    }
