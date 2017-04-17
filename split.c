#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){

  char str[100];
  char splitstr[10][10];
   int i,j,cnt;

   gets(str);

   j=0;
   cnt=0;
   for(i=0;i<=strlen(str);i++){

     if(str[i]==' ' || str[i] == '\0' ){

       splitstr[cnt][j] = '\0';
       cnt++;
       j=0;
     }

     else{
       splitstr[cnt][j] = str[i];
       j++;
     }
   }


   for(i=0;i<cnt;i++){
    if(strcmp(splitstr[i], "for")==0)
    printf('keyword');
  }


  return 0;
}
