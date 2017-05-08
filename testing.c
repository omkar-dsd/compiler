#include<stdio.h>
#include<stdlib.h>


void read(){

	char ch;
	FILE *fp;

	fp  = fopen("test.txt","r");

	if(fp==NULL){

		printf("Opening error.\n");
		exit(1);
	}

	while((ch = fgetc(fp))!= EOF)
		printf("%c", ch);


	fclose(fp);
	return;
}


void write(){

	char sentence[1000];


	FILE *fp;

	printf("Sentence: ");
	scanf("%s", sentence);

	fp  = fopen("test.txt","w");

	if(fp==NULL){

		printf("Opening error.\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fp,"%s", sentence);

	fclose(fp);
	return;
}


void append(){

	char sentence[1000];


	FILE *fp;

	printf("Sentence: ");
	scanf("%s", sentence);

	fp  = fopen("test.txt","a");

	if(fp==NULL){

		printf("Opening error.\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fp,"%s", sentence );
	fclose(fp);

	return;
}


void delete(){

	char ch = ' ';
	FILE *fp;

	fp  = fopen("test.txt","w");

	if(fp==NULL){

		printf("Opening error.\n");
		exit(1);
	}

	fprintf(fp,"%c", ch);

	fclose(fp);
	return;
}


int main(){

	int option;

	do{

		printf("\n1: READ\n2: WRITE\n3: APPEND\n4: DELETE\n");
		scanf("%d", &option);
		if(option>4||option<0){
			printf("Invalid Option\n");
			continue;
		}
		else{

			switch(option){

				case 0:
					exit(1);
					break;

				case 1:
					read();
					break;
				case 2:
					write();
					break;
				case 3:
					append();
					break;
				case 4:
					delete();
					break;
			}
		}
	}while(option!=0);

	return 0;
}