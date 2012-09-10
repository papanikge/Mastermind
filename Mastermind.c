// George Papanikolaou 2010

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int RandomInteger(int low, int high)
{
  int k;
  double d;

  d = (double)rand()/(1.0 + (double)RAND_MAX);
  k = (int) (d*(high - low + 1));
  return (low + k);
}

main()
{
	int l,min,sum;
	printf("Welcome to Mastermind - Colors available: RBGYPW\nPlease define secret code length (max:100):");
	scanf("%d", &l);
	srand((int)time(NULL));
	int i;
	int table[l];
	for (i=0;i<=(l-1);i++)
		table[i]=RandomInteger(1,6);
	char code[l];
	for (i=0;i<=(l-1);i++)
		{
			if (table[i]==1) code[i]='R';
			if (table[i]==2) code[i]='B';
			if (table[i]==3) code[i]='G';
			if (table[i]==4) code[i]='Y';
			if (table[i]==5) code[i]='P';
			if (table[i]==6) code[i]='W';
		}
	
	//enar3h !!!
	char string[100];
	int try=1, cp=0, c=0, flag=0;
	while (flag==0)
	{
		//dhlwsh kai arxikopoihsh
		error : printf("Try %d:", try);
		scanf("%s", string);
		int length = strlen(string);
	
			//elenxos SURRENDER
			if (string[0]=='S' && string[1]=='U' && string[2]=='R'
				&& string[3]=='R' && string[4]=='E' && string[5]=='N'
				&& string[6]=='D' && string[7]=='E' && string[8]=='R'){
					printf("You have lost the game. The secret code was %s\n", code);
					break;
				}
	
			//elenxos mikous
			if (length != l)
				{printf("Code sequence has to be exactly %d colors\n", l);
				goto error;}				// EDW GOTO
		
			//elenxo grammatwn
			for (i=0;i<=(l-1);i++)
			{
				if (string[i]!='R' && string[i]!='B' && string[i]!='G' &&
				string[i]!='Y' && string[i]!='P' && string[i]!='W')
				{
					printf("Error sequence, please try again\n");
					goto error;
				}
			}
		
		//enenxos olo mazi
		flag=1;
		for (i=0;i<=(l-1);i++)
			{
				if (string[i]!=code[i])
					flag=0;
			}
		if (flag==1)
			{printf("Congratulations! You have won the game after %d tries\n", try);
			break;}
		
		//elenxos ena-ena
		for (i=0;i<=(l-1);i++)
		{
			if (string[i]==code[i])
				cp++;
		}
		printf("\tColor and position correct: %d\n", cp);
		
		int R1=0,R2=0,B1=0,B2=0,G1=0,G2=0,Y1=0,Y2=0,P1=0,P2=0,W1=0,W2=0;
		for (i=0;i<=(l-1);i++)
		{
			if (string[i]=='R') R1++;
			if (string[i]=='B') B1++;
			if (string[i]=='G') G1++;
			if (string[i]=='Y') Y1++;
			if (string[i]=='P') P1++;
			if (string[i]=='W') W1++;
			if (code[i]=='R') R2++;
			if (code[i]=='B') B2++;
			if (code[i]=='G') G2++;
			if (code[i]=='Y') Y2++;
			if (code[i]=='P') P2++;
			if (code[i]=='W') W2++;
		}
		sum=0;
		min=R1;
		if (R2<min) min=R2;	
		sum=sum+min;
		min=B1;
		if (B2<min) min=B2;	
		sum=sum+min;
		min=G1;
		if (G2<min) min=G2;	
		sum=sum+min;
		min=Y1;
		if (Y2<min) min=Y2;	
		sum=sum+min;
		min=P1;
		if (P2<min) min=P2;	
		sum=sum+min;
		min=W1;
		if (W2<min) min=W2;	
		sum=sum+min;
		
		c=sum-cp;
		printf("\tOnly color correct: %d\n", c);
		c=0;
		cp=0;	
		try++;	
	}
}