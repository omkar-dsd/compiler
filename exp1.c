// Program to read write and append in file
// Omkar


#include<stdio.h>
#include<stdlib.h>

void read();
void write();
void append();
void delete();

int main(void){

  int option;
  char sentence[100];
  do{

  printf("Options:\n1: READ\n2: WRITE\n3: APPEND\n4: DELETE CONTENT\n5: EXIT\n\n");
  printf("Enter choice:  ");
  scanf("%d", &option);
  if(option>5 || option<1){
    printf("Invalid choice\n");
    continue;
  }

    switch(option){
      case 1:
              read();
              break;

      case 2:
              write();
              break;

      case 3:

              printf("Enter a sentence:\n");
              scanf("%s", sentence);
              // fgets(sentence);
              append(sentence);
              break;

      case 4:
              delete();
              break;

      if(option==5)
      break;
    }

  }while(option!=5);

  return 0;
}



void read(){

  char ch;
  FILE *fp;

  fp = fopen("exp1_file.txt","r"); // read mode

  if( fp == NULL )
  {
     perror("Error while opening the file.\n");
     exit(EXIT_FAILURE);
  }

  while( ( ch = fgetc(fp) ) != EOF )
     printf("%c",ch);

  fclose(fp);
  return;

}

void write(){


  char sentence[1000];
  FILE *fptr;

  fptr = fopen("exp1_file.txt", "w");
  if(fptr == NULL)
  {
     printf("Error!");
     exit(1);
  }

  printf("Enter a sentence:\n");

  scanf("%s", sentence);

  fprintf(fptr,"%s", sentence);
  fclose(fptr);

  return;
}

void append(char* sentence){


    
    FILE *fptr;

    fptr = fopen("exp1_file.txt", "a");
    if(fptr == NULL)
    {
       printf("Error!");
       exit(1);
    }

    fprintf(fptr,"%s", sentence);
    fclose(fptr);


  return;
}

void delete(){


    char a = ' ';
    FILE *fptr;

    fptr = fopen("exp1_file.txt", "w");
    if(fptr == NULL)
    {
       printf("Error!");
       exit(1);
    }


    fprintf(fptr,"%c", a);
    fclose(fptr);


  return;
}
