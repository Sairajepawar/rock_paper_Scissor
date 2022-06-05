#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() 
{
	label1:
	printf("\nEnter 1 to start a game computer vs player\n");
	printf("Enter 2 to start a game player vs player\n");
	printf("Enter 3 to see the previous score\n");
	printf("Enter 4 to exit\n");
	int response;
	printf("Enter your response:-");
	scanf("%d",&response);
	if(response==1) 
	{
		int count_player=0;
		int count_computer=0;
		int count_tie=0;
		for(int i=1; i<=3; i++) 
		{
			int n;
			n=rand()%3+1;
			int i;
			printf("\nEnter 1 for rock\n");
			printf("Enter 2 for paper\n");
			printf("Enter 3 for scissor\n");
			label:
			printf("Enter your response:- ");
			scanf("%d",&i);
			if(i>3) {
				printf("Enter valid response\n");
				goto label;
			}
			if(i==1) {
				if(n==3) {
					count_player++;
					printf("\nPlayer Wins\n");
				} 
				else if(n==2) {
					count_computer++;
					printf("\nComputer Wins\n");
				} 
				else {
					count_tie++;
					printf("\nTie\n");
				}
			} 
			else if(i==2) {
				if(n==3) {
					count_computer++;
					printf("\nComputer Wins\n");
				}
				 else if(n==1) {
					count_player++;
					printf("\nPlayer Wins\n");
				}
				 else {
					count_tie++;
					printf("\nTie\n");
				}
			} 
			else if(i==3) {
				if(n==1) {
					count_computer++;
					printf("\nComputer Wins\n");
				}
				 else if(n==2) {
					count_player++;
					printf("\nPlayer Wins\n");
				}
				 else {
					count_tie++;
					printf("\nTie\n");
				}
			}
		}
		FILE *fptr;
		fptr=fopen("historycvsp.txt","a");
		if(count_tie>count_player)
		{
			if(count_tie>count_computer)
			{
				printf("\nGame is tie\n");
				fprintf(fptr,"T");
			}
			else
			{
				printf("\nComputer wins the game\n");
				fprintf(fptr,"C");
			}
		}
		else
		{
			if(count_player>count_computer)
			{
				printf("\nPlayer wins the game\n");
				fprintf(fptr,"P");
			}
			else
			{
				printf("\nComputer wins the game\n");
				fprintf(fptr,"C");
			}
		}
		fclose(fptr);
		goto label1;
	}
	if(response==2)
	{
		int count_player2=0;
		int count_player1=0;
		int count_tie=0;
		for(int i=1; i<=3; i++) 
		{
			int n;
			printf("\nPlayer 1 Chance\n");
			printf("Enter 1 for rock\n");
			printf("Enter 2 for paper\n");
			printf("Enter 3 for scissor\n");
			label2:
			printf("Enter your response:- ");
			scanf("%d",&n);
			if(n>3)
			{
				printf("Enter valid response\n");
				goto label2;
			}
			int i;
			printf("\nPlayer 2 Chance\n");
			printf("Enter 1 for rock\n");
			printf("Enter 2 for paper\n");
			printf("Enter 3 for scissor\n");
			label100:
			printf("Enter your response:- ");
			scanf("%d",&i);
			if(i>3) 
			{
				printf("Enter valid response\n");
				goto label100;
			}
			if(i==1) {
				if(n==3) {
					count_player2++;
					printf("\nPlayer 2 Wins\n");
				} 
				else if(n==2) {
					count_player1++;
					printf("\nPlayer 1 Wins\n");
				} 
				else {
					count_tie++;
					printf("\nTie\n");
				}
			} 
			else if(i==2) {
				if(n==3) {
					count_player1++;
					printf("\nPlayer 1 Wins\n");
				}
				 else if(n==1) {
					count_player2++;
					printf("\nPlayer 2 Wins\n");
				}
				 else {
					count_tie++;
					printf("\nTie\n");
				}
			} 
			else if(i==3) {
				if(n==1) {
					count_player1++;
					printf("\nPlayer 1 Wins\n");
				}
				 else if(n==2) {
					count_player2++;
					printf("\nPlayer 2 Wins\n");
				}
				 else {
					count_tie++;
					printf("\nTie\n");
				}
			}
		}
		//small p for player 1
		//capital p for player 2
		FILE *fptr;
		fptr=fopen("historypvp.txt","a");
		if(count_tie>count_player1)
		{
			if(count_tie>count_player2)
			{
				printf("\nGame is tie\n");
				fprintf(fptr,"T");
			}
			else
			{
				printf("\nPlayer 2 wins the game\n");
				fprintf(fptr,"P");
			}
		}
		else
		{
			if(count_player1>count_player2)
			{
				printf("\nPlayer 1 wins the game\n");
				fprintf(fptr,"p");
			}
			else
			{
				printf("\nPlayer 2 wins the game\n");
				fprintf(fptr,"P");
			}
		}
		fclose(fptr);
		goto label1;
	}
	if(response==3)
	{
		printf("1 for history of computer vs player\n");
		printf("2 for history of player vs player\n");
		printf("Enter your response:- ");
		int response1;
		scanf("%d",&response1);
		if(response1==1)
		{
			FILE *fptr;
			fptr=fopen("historycvsp.txt","r");
			int size;
			char a[1000];
			fscanf(fptr," %[^\n]s",a);
			size=strlen(a);
			printf("\nTotal Matches Played %d\n",size);
			int count_player=0;
			int count_computer=0;
			int count_tie=0;
			for(int i=0;i<size;i++)
			{
				if(a[i]=='P')
				{
					count_player++;
				}
				else if(a[i]=='C')
				{
					count_computer++;
				}
				else if(a[i]=='T')
				{
					count_tie++;
				}
			}
			printf("Computer wins %d times\n",count_computer);
			printf("Player wins %d times\n",count_player);
			printf("%d ties\n",count_tie);
			fclose(fptr);
		}
		else if(response1==2)
		{
			FILE *fptr;
			fptr=fopen("historypvp.txt","r");
			int size;
			char a[1000];
			fscanf(fptr," %[^\n]s",a);
			size=strlen(a);
			printf("\nTotal Matches Played %d\n",size);
			int count_player1=0;
			int count_player2=0;
			int count_tie=0;
			for(int i=0;i<size;i++)
			{
				if(a[i]=='P')
				{
					count_player2++;
				}
				else if(a[i]=='p')
				{
					count_player1++;
				}
				else if(a[i]=='T')
				{
					count_tie++;
				}
			}
			printf("Player 1 wins %d times\n",count_player1);
			printf("Player 2 wins %d times\n",count_player2);
			printf("%d ties\n",count_tie);
			fclose(fptr);
		}
		goto label1;
	}
	if(response==4)
	{
		return 0;	
	}	
}