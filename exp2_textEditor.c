#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void read();
void write(char*);
void append(char*);
void copy_paste();
void cut_paste();
void delete();
void delete_all();

int main(){

	int option;
	char sentence[1000];

	while(1){

		printf(" \n1: READ\n2: WRITE\n3: APPEND\n4: COPY & PASTE\n5: CUT & PASTE\n6: DELETE\n7: DELETE ALL\n0: EXIT\n\nSelect Option:");

		scanf("%d", &option);

		switch (option){


			case 0:

				exit(1);
				break;

			case 1:

				read();

				break;

			case 2:


				printf("Enter a sentence:\n");
				scanf("%s", sentence);
				write(sentence);

				break;

			case 3:


			    printf("Enter a sentence:\n");
			    scanf("%s", sentence);
				append(sentence);

				break;

			case 4:

				copy_paste();
				break;

			case 5:

				cut_paste();
				break;

			case 6:

				delete();
				break;

			case 7:

				delete_all();
				break;

		}
	}

	return 0;
}


void read(){

	char ch;
	char file_content[100];
	int i=0;

	FILE *fp;

	fp = fopen("exp2_textEditorFile.txt","r"); // read mode

	if( fp == NULL )
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	printf("\n------------------------------------\n");

	while( ( ch = fgetc(fp) ) != EOF ){

		printf("%c",ch);
		file_content[i]=ch;
		i++;
	}

	printf("\n------------------------------------\n");


	fclose(fp);
	return;

}


void write(char* sentence){


  // char sentence[1000];
  FILE *fptr;

  fptr = fopen("exp2_textEditorFile.txt", "w");

  if(fptr == NULL)
  {
     printf("Error!");
     exit(1);
  }

  fprintf(fptr,"%s", sentence);
  fclose(fptr);

  return;
}




void append(char* sentence){


    // char sentence[1000];
    FILE *fptr;

    fptr = fopen("exp2_textEditorFile.txt", "a");
    if(fptr == NULL)
    {
       printf("Error!");
       exit(1);
    }

    fprintf(fptr,"%s", sentence);
    fclose(fptr);


  return;
}



void copy_paste(){

	int start_position, length, paste_position, pos=0,i=0,j=0;
	char copied_string[20];
	char rewrite[1000];
  	char ch;
  	char file_content[100];
  
  	FILE *fp;

  	fp = fopen("exp2_textEditorFile.txt","r"); // read mode

  	if( fp == NULL )
  	{
    	perror("Error while opening the file.\n");
     	exit(EXIT_FAILURE);
  	}

	printf("FILE:\n\n");

  	while( ( ch = fgetc(fp) ) != EOF ){
 
	  	printf("%c", ch);
	    file_content[i]=ch;
	    i++;
		
	}

	printf("\nEnter Starting position to copy: ");
	scanf("%d", &start_position);
	start_position--;
	printf("\nEnter length of copy string: ");
	scanf("%d", &length);

	memcpy( copied_string, &file_content[start_position], length );

	printf("\n>>>Text Copied<<<\n");
	printf("Enter Postion to paste: ");

	scanf("%d", &paste_position);


	for(pos=0;pos<(strlen(file_content)+length);pos++){

		if(pos-1==paste_position){

			for(i=0;i<length;i++){

				rewrite[pos]=copied_string[i];
				pos++;
			}
			pos--;
		}

		else{

			rewrite[pos]=file_content[j];
			j++;
		}
	}

	
	write(rewrite);
	
}



void cut_paste(){

	int start_position, length, paste_position, pos=0,i=0,j=0;
	char cut_string[20];
	char rewrite[1000];
    char re_rewrite[1000];
    char ch;
    char file_content[100];

	FILE *fp;

	fp = fopen("exp2_textEditorFile.txt","r"); // read mode

	if( fp == NULL )
	{
	 perror("Error while opening the file.\n");
	 exit(EXIT_FAILURE);
	}

	printf("FILE:\n\n");

	while( ( ch = fgetc(fp) ) != EOF ){

		printf("%c", ch);
	file_content[i]=ch;
	i++;
	}

	printf("\nEnter Starting position to CUT: ");
	scanf("%d", &start_position);
	start_position--;
	printf("\nEnter length of String to CUT: ");
	scanf("%d", &length);

	
	memcpy( cut_string, &file_content[start_position], length );
	
	for(pos=0;pos<(strlen(file_content)-length);pos++){

		if(pos==start_position){
			j+=length;
		
		}
		
			rewrite[pos]=file_content[j];
			j++;
		
	}
	rewrite[pos]='\0';

	printf("\n>>>Text CUT<<<\n");
	printf("\nEnter Postion to paste: ");

	scanf("%d", &paste_position);

	j=0;
	for(pos=0;pos<(strlen(rewrite)+length);pos++){

		if(pos+1==paste_position){

			for(i=0;i<length;i++){

				re_rewrite[pos]=cut_string[i];
				pos++;
			}
			pos--;
		}

		else{

			re_rewrite[pos]=rewrite[j];
			j++;
		}
	}

	
	write(re_rewrite);

	return;
}


void delete(){

	int start_position, length, paste_position, pos=0,i=0,j=0;

	char rewrite[1000];
    char ch;
    char file_content[100];


	FILE *fp;

	fp = fopen("exp2_textEditorFile.txt","r"); // read mode

	if( fp == NULL )
	{
	 perror("Error while opening the file.\n");
	 exit(EXIT_FAILURE);
	}

	printf("FILE:\n\n");

	while( ( ch = fgetc(fp) ) != EOF ){

		printf("%c", ch);
	file_content[i]=ch;
	i++;
	}


	
	printf("\nEnter Starting position to DELETE: ");
	scanf("%d", &start_position);
	start_position--;
	printf("\nEnter length of String to DELETE: ");
	scanf("%d", &length);
	

	for(pos=0;pos<(strlen(file_content)-length);pos++){

		if(pos==start_position){
			j+=length;
		
		}

		
			rewrite[pos]=file_content[j];
			j++;
		
	}

	printf("\n>>>Text DELETED<<<\n");
	write(rewrite);

	return;
	
}


void delete_all(){


    char a = ' ';
    FILE *fptr;

    fptr = fopen("exp2_textEditorFile.txt", "w");
    if(fptr == NULL)
    {
       printf("Error!");
       exit(1);
    }


    fprintf(fptr,"%c", a);
    fclose(fptr);


  return;
}

