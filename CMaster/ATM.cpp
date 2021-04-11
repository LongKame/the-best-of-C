#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
int check(){
	int n;
	char c;
	while (1) {
		scanf("%d%c",&n,&c);fflush(stdin);
		if (n>0 && c=='\n') break;
		else printf("\n");
	}
	return n;
}

void WriteDataToFile(char name[][50], int banlances[50], char mtype[][50], int &k, long long a[50], char password1[50], char password[50][50], char name1[50])
{
	remove(name1);
	int i;
	FILE *w = fopen(name1,"a+");
	fprintf(w,"%d\n",k);
	for(i=0 ;i< k;i++ )
	{
		fprintf(w,"%s\n%s\n%d\n%lld\n%s",name[i],mtype[i],banlances[i],a[i],password[i]);
	}
	fclose(w);
}

void ReadDataFromFile(char name[][50], int banlances[50], char mtype[][50], int &k, long long a[50], char password1[50], char password[50][50], char name1[50]){
	char ch;
	int i;
	FILE *r = fopen(name1,"r");
	fscanf(r,"%d\n",&k);
	for(i = 0;i<k;i++)
	{
		fscanf(r,"%[^\n]\n",name+i);
		fscanf(r,"%[^\n]\n\n",mtype+i);
		fscanf(r,"%d\n",banlances+i);
		fscanf(r,"%lld\n",a+i);
		fscanf(r,"%[^\n]\n\n",password+i);
		
          }
	fclose(r);
}
int withdraw(int &k, int founds, char account[][50], char name[][50], char mtype[][50], int banlances[50], long long a[50], char password1[50], char password[50][50]){
	founds=0;
	int i, tien, next;
	    for(i=0;i<k;i++){
	        if(strcmp(password1,password[i])==0){
			    printf("%s\n",name[i]);
			    printf("%d\n",banlances[i]);
			    printf("%s\n",mtype[i]);
			    founds=1;
			    printf("Moi ban nhap so tien can rut: "); 
				scanf("%d",&tien);
                    if(tien>banlances[i]){
                        printf("The amount you withdraw is greater than the current amount in your account");
                        printf("\nEnter any button or ESC to exit.\n");
                        getch();
						break;
					}else{
                        if(tien%10000!=0){
                            printf("The amount to be withdrawn must be a multiple of 10000.\n");
                            printf("\nEnter any button or ESC to exit.");
						}else{
                            banlances[i]-=tien;
							printf("Your banlance in your account: %d",banlances[i]);
						}
					getch();
					printf("\nAre you continue(1) or stop(other): ");
					scanf("%d",&next);
					if(next=='1'){
			            printf("\nEnter money that need withdraw : "); scanf("%d",&tien);
                        if(tien>banlances[i]){
                            printf("The amount you withdraw is greater than the current amount in your account.\n");
                            getch();
							break;
						}else{
							if(tien%10000!=0){
                                printf("Money withdraw must be > 10000.");
                                                                                            //printf("\nMoi ban nhan phim bat ki de tiep tuc, hoac Esc de thoat.");
							}else{
                                banlances[i]-=tien;
								printf("The amount of money in your account is: %d",banlances[i]);
							}
							getch();
						    }
						}else if(next!=1){
                            getch();
                            break;
						    } 
						}
					}
				}
			return founds;
}
int login(int &k, char account[][50], char name[][50], char mtype[][50], int banlances[50], long long a[50], char password1[50], char password[50][50]){
	int i, found=0, founds=0;
	long long account1;
	int tien, next;
	//char password1[50];
	printf("Login\n Please enter login account and pin:");
	printf("\nEnter your account: ");
	fflush(stdin);
	scanf("%lld",&account1);
	for(i=0;i<k;i++){
		if(account1!=a[i]){
		    found++;
	    }
	}
	if(found==k){
		printf("Your account is not exist!\n");
	}else{
		printf("\nEnter the password: ");
		fflush(stdin);
	    gets(password1);
	    withdraw(k,founds,account,name,mtype,banlances,a,password1,password);
		    if( withdraw(k,founds,account,name,mtype,banlances,a,password1,password)==0){
				printf("Your password is not correct!\n");
				}
		}
}
long long random(long long minN, long long maxN){
    return minN + rand() % (maxN + 1 - minN);
}
int regist(int &k, long long a[50], char id[][50], char id1[50], char password1[50], char password[][50], char account[][50], char name[][50], char mtype[][50], int banlances[50]){
	long long i, j, m=1;
	int count=0;
	long long x;
	srand((int)time(0));
	int r;
	srand((int)time(NULL));
	printf("\nEnter information of customer: \n");
	x=random(10000000000000,99999999999999);
	for(i=k;i<k+m;i++){
		printf("Welcome to the bank!!!\n");
		int checkCode = 1;
	        while(1){
			    printf("Enter id of citizen identification: ");
			    fflush(stdin);
			    gets(id[i]);
			    checkCode = 0;
			        for (j = 0; j < i; j++) {
				        if (strcmp(id[i],id[j])==0) {
					        checkCode = 1;
					            break;
							}
						}
		                if (checkCode == 1){
				            printf("The id of citizen identificationalready exists, please reenter!\n");
			            }else{ 
			                break;
							}
						}	
			a[i] = x;
	        x=0;
	        printf("\t\tWelcome member %d\n",i+1);
	        printf("Your account is %lld\n", a[i]);
	        printf("\n\tName: ");
		    fflush(stdin);
		    gets(name[i]);
	        printf("\n\tEnter balances: ");
		    fflush(stdin);
		    scanf("%d",&banlances[i]);
		    printf("\n\tEnter money type: ");
		    fflush(stdin); 
		    gets(mtype[i]);
		    printf("\n\tEnter password: ");
		    fflush(stdin); 
	        gets(password[i]);
	            for(int j=0;j<strlen(password[i]);j++){
	                count++;
				}if(count!=6){
					printf("Password contains 6 digits number!\n");
					printf("Reenter password:");
					gets(password[i]);
				}
			printf("Your card ATM: \n");
			printf("\t|-----------------------------------|\n");
			printf("\t|\t%s\n",name[i]);
			printf("\t|\t%lld\n",a[i]); 
			printf("\t|-----------------------------------|\n");
		}
	k+=m;
}
int transferMoney(int &k, long long a[50], int banlances[50]){
	int found=0, i, tien;
	int account1;
	printf("Enter account: ");
	printf("Login\n Please enter login account and pin:");
	printf("\nEnter your account: ");
	fflush(stdin);
	scanf("%d",&account1);
	    for(i=0;i<k;i++){
		    if(account1!=a[i]){
		        found++;
			}
			if(account1==a[i]){
				printf("Enter money that is send: "); scanf("%d",&tien);
                banlances[i]+=tien;
                printf("The amount of money in your account is: %d",banlances[i]);
                getch();
			}
	    }
	    if(found==k){
		    printf("Your account is not exact!\n");
	    }
}
int main(){
	int k=0, m=1, found=0;
	            char password1[50], password[50][50], id[50][50], id1[50];
	            char account[50][50], name[50][50], mtype[50][50];
	            int select, i, j;
	            int tk[50];
	            int tien,  banlances[50];
	            int account1;
	            long long a[50];
	            int next;
	            char name1[50] = "filek.txt";
	                        while(1){
	                            printf("1.Login\n");
	                            printf("\n2.Register account\n");
	                            printf("\n3.Transfer money\n");
	                            printf("\nYour selection 1-->3:");
	                            select=check();
	                            switch(select){
	                            	case 1:
	                            	ReadDataFromFile(name,banlances,mtype,k,a,password1,password,name1);
	                            	login(k,account,name,mtype,banlances,a,password1,password);
	                            	WriteDataToFile(name,banlances,mtype,k,a,password1,password,name1);
									break;
	                            	case 2:
	                                regist(k,a,id,id1,password1,password,account,name,mtype,banlances);
	                                WriteDataToFile(name,banlances,mtype,k,a,password1,password,name1);
									break;
	                            	case 3:
	                            	ReadDataFromFile(name,banlances,mtype,k,a,password1,password,name1);
	                            	transferMoney(k,a,banlances);
	                            	WriteDataToFile(name,banlances,mtype,k,a,password1,password,name1);
									break;
								}
	                        }
				return 0;
}



