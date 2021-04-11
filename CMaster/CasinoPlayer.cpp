#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
int CheckInteger() 
{
    int number;
    char c;
    int check;
    while(1)
    {
    fflush(stdin);
//    printf("Please enter a Binary Number: \n");
    check = (scanf("%d%c", &number, &c));
    if (check != 2 || c != '\n')
    printf("wrong input,Try again\n");
    else
    return number;
    }
}
void displayMenu(){
	printf("\nWelcome to the Casino . Here are your choices:");
	printf("\n1) Buy chips");
	printf("\n2) Sell chips");
	printf("\n3) Play Craps");
	printf("\n4) Play Arup's Game of Dice");
	printf("\n5) Status Report");
	printf("\n6) Quit\n");
}

void buyChips(int &money,int &chips){
	printf("How much cash do you want to spend for chips ?\n");
	
	int cash;
	cash=CheckInteger();
	
	if(cash<=0){
		printf("Sorry , that is not allowed\n");
	}
	
	else if(cash>money){
		printf("Sorry , you do not have that much money .No chips bought\n");
	}	
	else{
		int i=0; //chipWantToBuy
		
		while(i*11<cash){
			i++;
		}
		i--;
		chips=chips+i;
		money=money-i*11;
	}
}

void sellChips(int &money,int &chips){
	printf("How many chips do you want to sell ?\n");
	int chipWantToSell;
	chipWantToSell=CheckInteger();
	
	if(chipWantToSell>chips){
		printf("Sorry, you do not have that many chips. No chips sold.\n");
	}
	else{
		chips=chips-chipWantToSell;
		money=money+(chipWantToSell*10);
	}
}

void statusReport(int money , int chip){
	printf("You currently have $%d left and %d chips.\n",money,chip);
}

void quit(int money,int chip){
	money=money+chip*10;
	printf("After selling your chips , you have $%d .Thanks for playing!!!",money);
}

void hitToRoll(){
	while(1){
		printf("Press 'r' and hit enter for your next roll.\n");
		char r;
		fflush(stdin);
		r=getchar();
		if(r=='r'){
			break;
		}
		printf("Sorry , you must ");
	}
}

int roll(){
		srand(time(NULL));	
		int a=rand()%6+1;
		int b=rand()%6+1;
					
		return (a+b);
}

void playCraps(int &chip){	
	printf("How many chips would you like to bet ?\n");
	
	int chipBet;
	chipBet=CheckInteger();
	
	if(chipBet<=0){
		printf("Sorry , that is not allowed . No game played.\n");
	}
	
	else if(chipBet>chip){
		printf("Sorry, you do not have that many chips");
	}
	else{
			
		hitToRoll();
		int firstRoll = roll();		
		printf("You roll a %d.\n",firstRoll);
		
		if(firstRoll == 7 || firstRoll == 11 ){
			chip=chip+chipBet;
			printf("You win!!");
		}
		else if (firstRoll == 2 || firstRoll == 3 || firstRoll == 12){
			chip=chip-chipBet;
			printf("Sorry, You lost");
		}
		else {
			int point = firstRoll;
			while(1){
				
				hitToRoll();				
				int nextRoll = roll(); 
				printf("You roll a %d.\n",nextRoll);
								
				if(nextRoll == 7){
					chip=chip-chipBet;
					printf("Sorry, You lost");
					break;
				}
				
				else if(nextRoll != 7 && nextRoll == point){
					chip=chip+chipBet;
					printf("You win!!");
					break;
				}
				else{
					point=nextRoll;
				}				
			}		
		}
	}	
}

void playArup(int &chip){	
	printf("How many chips would you like to bet ?\n");
	
	int chipBet;
	chipBet=CheckInteger();
	
	if(chipBet<=0){
		printf("Sorry , that is not allowed . No game played.\n");
	}
	
	else if(chipBet>chip){
		printf("Sorry, you do not have that many chips");
	}
	else{
			
		hitToRoll();
		int firstRoll = roll();		
		printf("You roll a %d.\n",firstRoll);
		
		if(firstRoll == 12 || firstRoll == 11 ){
			chip=chip+chipBet;
			printf("You win!!");
		}
		else if (firstRoll == 2){
			chip=chip-chipBet;
			printf("Sorry, You lost");
		}
		else {
			int point = firstRoll;
			hitToRoll();				
			int nextRoll = roll(); 
			
			if(nextRoll > point ){
				chip=chip+chipBet;
				printf("You Win");
			}
			else{
				chip=chip-chipBet;
				printf("Sorry, you lost");
			}
		}
	}	
}
int main() {
	int money=1000;
	printf("You have $%d!!!!\n",money);
	int chip=0;
	char choise;
	while(1){
		displayMenu();
		fflush(stdin);
		choise=getchar();
		switch(choise){
			case '1':
				buyChips(money,chip);
				break;
				
			case '2':
				sellChips(money,chip);
				break;
				
			case '3':
				playCraps(chip);
				break;
				
			case '4':
				playArup(chip);
				break;
				
			case '5':
				statusReport(money,chip);
				break;
				
			case '6':
				quit(money,chip);
				return 0;
				break;				
			default:
				break;			
		}
	}
	return (0);
	}
