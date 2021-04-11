#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int input(){
	int n;
	char c;
	while (1) {
		scanf("%d%c",&n,&c);fflush(stdin);
		if (n>0 && c=='\n') break;
		else printf("Enter an integer: ");
	}
	return n;
}
void WriteFile(float d, char FileName[]){
	FILE* file=fopen(FileName,"w");
	fprintf(file,"%.2f",d);
	fclose(file);
}
float ReadFile(char FileName[]){
	float d=0.0;
	FILE* file=fopen(FileName,"r");
	if (file == NULL){
		printf("File '%s' does not exist... Create a new file with $10.00",FileName);
		WriteFile(10.0,FileName);
		d=10.0;	
	}else {
		int tem = fscanf(file,"%f",&d);
		if (d<0.25 || tem !=1) d=10.0;
		printf("File exist. Value is : %.2f",d);
		fclose(file);
	}
	return d;
}

float play(){
	int a,b,c;
	float d=0.0;
	srand(time(NULL));    
	a= rand()%10;        
	b = rand()%10;
	c= rand()%10;
	d=d-0.25;
	printf("The slot machine shows %d %d %d\n",a,b,c);
	if (a==b && b==c){
		printf("You win the big prize : $10.00!\n");
		d=d+10.00;
	}else if (a==b || a==c || b==c){
			printf("You win 50 cents!\n");
			d=d+0.5;	
		}else printf("You don't win \n");
	return d;
}

int main(){
	int i;
	float e = ReadFile("slotMachine.txt");
	do{
	

		printf("\nYou have %.2f\n",e);
		printf("Choose one of the following menu options:\n");
		printf("1. Play the slot machine\n");
		printf("2. Save game.\n");
		printf("3. Cash out.\n");
		i=input(); fflush(stdin);
		switch (i){
			case 1: 
				if (e==0.0) {
					printf("You don't enought money to play game\n");
					return 0;
				}else {
					e=e+play();
				}
			case 2: 
				WriteFile(e,"slotMachine.txt"); 
				break;
			case 3:
				printf("Thanks you for playing! You end with $%.2f",e);
				remove("slotMachine.txt");
				return 0;
			default: 
				printf("Input error. Chose 1-3 (int)");
				break;
		}
	}while (1);	
return 0;
}


