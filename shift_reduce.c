
#include<stdio.h>
#include<string.h>
int novar=0,sttop=1,intop=1,j=0,i=0,handlelength=0;
char ipstr1[100],ipstr[100],popped,var;
char prod[20][20],handle[100],stack[100]="#",input[100]="#";

struct grammar
{
	char lhs,rhs[20][20];
	int noprod;
}g[20];

int checkhandle()
{
	int i,m,k;
	char temp[2]={ ' ' , '\0'};
	for(i=0;i<sttop;i++)
	{
		strcpy(handle,"");
		for(m=i;m<=sttop-1;temp[0]=stack[m],strcat(handle,temp),m++);
		for(m=0;m<novar;m++)
		{
			for(k=0;k<g[m].noprod && strcmp(handle,g[m].rhs[k])!=0;k++);
			if(k!=g[m].noprod)
			{
				var=g[m].lhs;
				return strlen(handle);
			}
		}
	}
	return 0;
}

void print(char *text,int textlen)
{
	int i;
	for(i=0;i<textlen;i++)
		printf("%c",text[i]);
	printf("\t\t\t");
}
void printi(char *text,int textlen)
{
	int i;
	for(i=textlen-1;i>=0;i--)
		printf("%c",text[i]);
	printf("\t\t\t");
}

int main()
{
	int n,m,k,len,j=0,v;

	printf("\n Enter the productions of the grammar(END to end):\n");
  // Store all the production in prod arr till END is typed
  do
	{
		scanf("%s",prod[i++]);
	}while(strcmp(prod[i-1],"END")!=0);


  for(n=0;n<i-1;n++)
	{
		m=0,k=0;
		for(j=0;j<novar;j++)
			if(g[j].lhs==prod[n][0])
				break;
		if(j==novar)
			g[novar++].lhs=prod[n][0];
		for(k=3;k<strlen(prod[n])+1;k++)
		{
			if(prod[n][k]!='|' && prod[n][k]!='\0')
				g[j].rhs[g[j].noprod][m++]=prod[n][k];
			if(prod[n][k]=='|' || prod[n][k]=='\0')
			{
				g[j].rhs[g[j].noprod++][m]='\0';
				m=0;
			}
		}
	}
	printf("\nENTER THE INPUT STRING:");
	scanf("%s",ipstr);
	printf("\n\n\n\n");
	for(i=strlen(ipstr)-1;i>=0;i--)
		input[intop++]=ipstr[i];
	printf("-------------------------------------------------------------\n");
	printf(" STACK\t\t\tINPUT\t\t\tACTION\n");
	printf("-------------------------------------------------------------\n");
	print(stack,sttop);
	printi(input,intop);
	while(1)
	{
		int count=0;
		while((handlelength=checkhandle())>0)
		{
			if(input[intop-1]=='*' && count++==2)
				break;
			else if(input[intop-1]=='=' && count++==3)
				break;
			else if(input[intop-1]=='e' && count++==1)
				break;
			for(i=0;i<handlelength;i++,--sttop);
				stack[sttop++]=var;
			printf("REDUCE BY %c -> %s\n",var,handle);
			print(stack,sttop);
			printi(input,intop);
		}
		popped=input[--intop];
		if(popped!='#')
			stack[sttop++]=popped;
		handlelength=checkhandle();
		if(popped=='#' && (handlelength=checkhandle())==0)
			break;
		printf("SHIFT ' %c '\n",popped);
		print(stack,sttop);
		printi(input,intop);
	}
	if(sttop==2 && stack[1]==g[0].lhs)
		printf("ACCEPT\n");
	else
		printf("ERROR\n");
	printf("---------------------------------------------------------------");
return 0;
}
