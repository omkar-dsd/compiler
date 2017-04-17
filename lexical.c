
// Lexical Analysis
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 30

int main()
{
	char str[MAX];
	int state=0,i=0,j,startid=0,endid;
	int startcon,endcon;

	for(j=0;j<MAX;j++)
		str[j]='\0';
	printf("\n***** PROGRAM ON LEXICAL ANALYSIS *****\n");
	printf("\n\nEnter the statement : ");
	gets(str);
	printf("\n\nAnalysis : ");
  str[strlen(str)]=' ';
	while(str[i]!='\0')
	{
		while(str[i]==' ')
			i++;

		switch(state)
		{
			case 0:
			if(str[i]=='i')
				state=1; // if
			else if(str[i]=='w')
				state=3;
			else if(str[i]=='d')
				state=8;
			else if(str[i]=='e')
				state=10;
			else if(str[i]=='f')
				state=14;
			else if(isalpha(str[i]) || str[i]=='_')
			{
				state=17;
				startid=i;
			}
			else if(str[i]=='<')
				state=19;
			else if(str[i]=='>')
				state=21;
			else if(str[i]=='=')
				state=23;
			else if(isdigit(str[i]))
			{
				state=25;
				startcon=i;
			}
			else if(str[i]=='(')
				state=26;
			else if(str[i]==')')
				state=27;
			else if(str[i]==';')
				state=28;
			else if(str[i]=='+')
				state=29;
			else if(str[i]=='-')
				state=30;
			else if(str[i]=='*')
				state=31;
			else if(str[i]=='/')
				state=32;
			else if(str[i]=='%')
				state=33;
			else if(str[i]=='}')
				state=34;
			else if(str[i]=='{')
				state=35;
			break;

			case 1:
			if(str[i]=='f')
				state=2;
			else
			{
				state=17;
				startid=i-1;
				i--;
			}
			break;

			case 2:
			if(str[i]=='(' || str[i]=='\0')
			{
				printf("\n if - Keyword");
				state=0;
				i--;
			}
			else
			{
				state=17;
				startid=i-2;
				i--;
			}
			break;

			case 3:
			if(str[i]=='h')
				state=4;
			else
			{
				state=17;
				startid=i-1;
				i--;
			}
			break;

			case 4:
			if(str[i]=='i')
				state=5;
			else
			{
				state=17;
				startid=i-2;
				i--;
			}
			break;

			case 5:
			if(str[i]=='l')
				state=6;
			else
			{
				state=17;
				startid=i-3;
				i--;
			}
			break;

			case 6:
			if(str[i]=='e')
				state=7;
			else
			{
				state=17;
				startid=i-4;
				i--;
			}
			break;

			case 7:
			if(str[i]=='(' || str[i]=='\0')
			{
				printf("\nwhile : Keyword");
				state=0;
				i--;
			}
			else
			{
				state=17;
				startid=i-5;
				i--;
			}
			break;

			case 8:
			if(str[i]=='o')
				state=9;
			else
			{
				state=17;
				startid=i-1;
				i--;
			}
			break;

			case 9:
			if(str[i]=='{' || str[i]==' '||str[i]=='\0'||str[i]=='(')
			{
				printf("\ndo : Keyword");
				state=0;
				i--;
			}
			break;

			case 10:
			if(str[i]=='l')
				state=11;
			else
			{
				state=17;
				startid=i-1;
				i--;
			}
			break;

			case 11:
			if(str[i]=='s')
				state=12;
			else
			{
				state=17;
				startid=i-2;
				i--;
			}
			break;

			case 12:
			if(str[i]=='e')
				state=13;
			else
			{
				state=17;
				startid=i-3;
				i--;
			}
			break;

			case 13:
			if(str[i]=='{' || str[i] == ' '||str[i]=='\0')
			{
				printf("\nelse : Keyword");
				state=0;
				i--;
			}
			else
			{
				state=17;
				startid=i-4;
				i--;
			}
			break;

			case 14:
			if(str[i]=='o')
				state=15;
			else
			{
				state=17;
				startid=i-1;
				i--;
			}
			break;

			case 15:
			if(str[i]=='r')
				state=16;
			else
			{
				state=17;
				startid=i-2;
				i--;
			}
			break;

			case 16:
			if(str[i]=='(' || str[i]=='\0')
			{
				printf("\nfor : Keyword");
				state=0;
				i--;
			}
			else
			{
				state=17;
				startid=i-3;
				i--;
			}
			break;

			case 17:
			if(isalnum(str[i]) || str[i]=='_')
			{
				state=18;
				i++;
			}
			else if(str[i]=='\0'||str[i]=='<'||str[i]=='>'||str[i]=='('||str[i]==')'||str[i]==';'||str[i]=='='||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')
				state=18;
			i--;
			break;

			case 18:
			if(str[i]=='\0'||str[i]=='<'||str[i]=='>'||str[i]=='('||str[i]==')'||str[i]==';'||str[i]=='='||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')
			{
				endid=i-1;
				printf("\n");
				for(j=startid;j<=endid;j++)
					printf("%c",str[j]);
				printf(" : Identifier");
				state=0;
				i--;
			}
			break;

			case 19:
			if(str[i]=='=')
				state=20;
			else if(isalnum(str[i])||str[i]=='_')
			{
				printf("\n< : Relational Operator");
				i--;
				state=0;
			}
			break;

			case 20:
			if(isalnum(str[i]) || str[i]=='_')
			{
				printf("\n<= : Relational Operator");
				i--;
				state=0;
			}
			break;

			case 21:
			if(str[i]=='=')
				state=22;
			else if(isalnum(str[i]) || str[i]=='_')
			{
				printf("\n> : Relational Operator");
				i--;
				state=0;
			}
			break;

			case 22:
			if(isalnum(str[i]) || str[i]=='_')
			{
				printf("\n>= : Relational Operator");
				i--;
				state=0;
			}
			break;

			case 23:
			if(str[i]=='=')
				state=24;
			else
			{
				printf("\n= : Assignment Operator");
				i--;
				state=0;
			}
			break;

			case 24:
			if(isalnum(str[i]) || str[i]=='_')
			{
				printf("\n== : Relational Operator");
				state=0;
				i--;
			}
			break;

			case 25:
			if(isalpha(str[i]))
			{
				printf("\n**** ERROR ****");
				puts(str);
				for(j=0;j<i;j++)
					printf(" ");
				printf("^");
				printf("\nError @ pos %d alphabet cannot follow digit",i);
				state=99;
			}
			else if(str[i]=='('||str[i]==')'||str[i]=='>'||str[i]=='<'||str[i]=='\0'||str[i]==';'||str[i]=='=')
			{
				endcon=i-1;
				printf("\n");
				for(j=startcon;j<=endcon;j++)
					printf("%c",str[j]);
				printf(" : Constant");
				state=0;
				i--;
			}
			break;

			case 26:
			printf("\n( : Special Character");
			startid=i;
			state=0;
			i--;
			break;

			case 27:
			printf("\n) : Special Character");
			state=0;
			i--;
			break;

			case 28:
			printf("\n; : Special Character");
			state=0;
			i--;
			break;

			case 29:
			if(str[i]=='+')
				state=36;
			else
			{
				printf("\n+ : Operator");
				state=0;
				i--;
			}
			break;

			case 30:
			if(str[i]=='-')
				state=37;
			else
			{
				printf("\n- : Operator");
				state=0;
				i--;
			}
			break;

			case 31:
			printf("\n* : Operator");
			state=0;
			i--;
			break;

			case 32:
			printf("\n/ : Operator");
			state=0;
			i--;
			break;

			case 33:
			printf("\n% : Operator");
			state=0;
			i--;
			break;

			case 34:
			printf("\n} : Special Character");
			state=0;
			i--;
			break;

			case 35:
			printf("\n{ : Special Character");
			state=0;
			i--;
			break;

			case 36:
			printf("\n++ : Increment Operator");
			state=0;
			i--;
			break;

			case 37:
			printf("\n-- : Decrement Operator");
			state=0;
			i--;
			break;

			case 99:
			exit(0);
			break;
		}
		i++;
	}
	printf("\nEND OF ANALYSIS");
	return 0;
}
