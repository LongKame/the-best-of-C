#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
//int k=0;
//char name1[50] = "file1.txt";
void tachten2(char s[], char ten2[], char dem1[], char dem2[], char ho2[]) {
  int i, j, n, m, k,f;
  n = strlen(s);
  for (i=0;i<n;i++)
    if(s[i]==' ')
      break;
for(k=i+1;k<n;k++){
   	 if(s[k]==' ')
   	break;
   }
for(f=k+1;f<n;f++){
   	 if(s[f]==' ')
   	break;
   }
for(m=0;m<i;m++){
     ho2[m]=s[m];
     ho2[i]='\0';	
  }
for(m=i+1;m<k;m++){
    dem1[m-i-1]=s[m];
    dem1[k]='\0';
}
for(m=k+1;m<f;m++){
    dem2[m-k-1]=s[m];
    dem2[f]='\0';
}
for(m=f+1;m<n;m++){
     ten2[m-f-1]=s[m];
     ten2[n-f-1]='\0';
}
}
void tachten(char s[], char ten[], char dem[], char ho[]) {
  int i, j, n, m, k;
  n = strlen(s);
  for (i=0;i<n;i++)
    if(s[i]==' ')
      break;
for(k=i+1;k<n;k++){
   	 if(s[k]==' ')
   	break;
   }
for(m=0;m<i;m++){
     ho[m]=s[m];
     ho[i]='\0';	
  }
for(m=i+1;m<k;m++){
    dem[m-i-1]=s[m];
    dem[k]='\0';
}
for(m=k+1;m<n;m++){
     ten[m-k-1]=s[m];
     ten[n-k-1]='\0';
}
}
void tachten1(char s[], char ten[], char lot[]) {
  int i, j, n;
  n = strlen(s);
  for(i=n-1;i>0;i--){
    if(s[i]==' ')
      break;
      }
  for(j=0;j<i;j++){
    lot[j]=s[j];
    lot[i]='\0';
      }
  for(j=i+1;j<n;j++){
    ten[j-i-1]=s[j];
    ten[n-i-1]='\0';
    }
}
int input(){
	int n;
	char c;
	while (1) {
		scanf("%d%c",&n,&c);fflush(stdin);
		if (n>0 && n<9 && c=='\n') break;
		else printf("Reenter: ");
	}
	return n;
}
int enterstd(char code[][50], char name[][50], char date[][50], float point[50], int &k)
{
                    int i,j,m=1;
		printf("Enter new student:\n");
			for(i=k;i<k+m;i++){
			printf("Student %d\n",i+1);
			         int checkCode = 1;
	               	while(1){
			printf("Enter code : ");
			fflush(stdin);
			gets(code[i]);
			checkCode = 0;
			for (j = 0; j < i; j++) {
				if (strcmp(code[i],code[j]) == 0) {
					checkCode = 1;
					break;
				}
			}
		          if (checkCode == 1){
				printf("The code %s already exists, please reenter!\n",code[i]);
			}
			else{ 
			            break;
			}
		}	
			          printf("Student name: ");
	                                        fflush(stdin);
			                    gets(name[i]);
			          printf("Date of birth: ");
                                                  fflush(stdin);
			                    scanf("%s",&date[i]);
			          printf("Learning point: ");
			                 point[i]=input();
			}
			k+=m;
}
void WriteDataToFile(char code[][50], char name[][50], char date[][50], float point[50], int &k, char name1[50])
{
	remove(name1);
	int i;
	FILE *w = fopen(name1,"a+");
	fprintf(w,"%d\n",k);
	for(i=0 ;i< k;i++ )
	{
		fprintf(w,"%s\n%s\n%s\n%.1f\n",code[i],name[i],date[i],point[i]);
	}
	fclose(w);
}
void ReadDataFromFile(char code[][50], char name[][50], char date[][50], float point[50], int &k, char name1[50])
{
	char ch;
	int i;
	FILE *r = fopen(name1,"r");
	fscanf(r,"%d\n",&k);
	for(i = 0;i<k;i++)
	{
		fscanf(r,"%[^\n]\n",code+i);
		fscanf(r,"%[^\n]\n\n",name+i);
		fscanf(r,"%[^\n]\n",date+i);
		fscanf(r,"%f\n",point+i);
		
          }
	fclose(r);
}
int demsotu(char *name)
{
	int n=strlen(name),i;
	int dem=0;
	if(name[0]!=' ')
		dem=1;
	for( i=0;i<n-1;i++)
	{
		if(name[i]==' ' && name[i+1]!=' ')
			dem++;
	}
	return dem;
}
int lookstd(char code[][50], char name[][50], char date[][50], float point[50], char ten[50], char dem[50], char ho[50], char ten1[50], char lot[50], char ten2[50], char dem1[50], char dem2[50], char ho2[50], int &k)
{
	int found=0;
	char nameC[50];
	int i;
	printf("\nPlease enter student name: ");
	scanf("%s",nameC);
		for(i=0;i<k;i++){
			tachten(name[i], ten, dem, ho);
			tachten1(name[i],ten1,lot);
			tachten2(name[i],ten2,dem1,dem2,ho2);
		          if(demsotu(name[i])==3){
		          	
			         if(strcmp(nameC,ten)==0 || strcmp(nameC,dem)==0 || strcmp(nameC,ho)==0 ){
				
					printf("code:%s",code[i]);
					printf("\nname:%s",name[i]);
					printf("\ndate:%s",date[i]);
					printf("\npoint:%0.2f",point[i]);
					printf("\n");
					found=1;	
				}
				else if(strcmp(nameC,name[i])==0){
					printf("code:%s",code[i]);
					printf("\nname:%s",name[i]);
					printf("\ndate:%s",date[i]);
					printf("\npoint:%0.2f",point[i]);
					printf("\n");
					found=1;	
				
				}
				else if(strcmp(nameC,ten)==0 && strcmp(nameC,dem)==0 && strcmp(nameC,ho)==0 ){
					printf("code:%s",code[i]);
					printf("\nname:%s",name[i]);
					printf("\ndate:%s",date[i]);
					printf("\npoint:%0.2f",point[i]);
					printf("\n");
					found=1;	
				}
			
			}
			else if(demsotu(name[i])==2){
				if(strcmp(nameC,ten1)==0 || strcmp(nameC,lot)==0 || strcmp(nameC,name[i])==0){
					printf("code:%s",code[i]);
					printf("\nname:%s",name[i]);
					printf("\ndate:%s",date[i]);
					printf("\npoint:%0.2f",point[i]);
					printf("\n");
					found=1;
				}
			
				else if(strcmp(nameC,name[i])==0){
					printf("code:%s",code[i]);
					printf("\nname:%s",name[i]);
					printf("\ndate:%s",date[i]);
					printf("\npoint:%0.2f",point[i]);
					printf("\n");
					found=1;	
			          }
			          else if(strcmp(nameC,ten1)==0 && strcmp(nameC,lot)==0){
					printf("code:%s",code[i]);
					printf("\nname:%s",name[i]);
					printf("\ndate:%s",date[i]);
					printf("\npoint:%0.2f",point[i]);
					printf("\n");
					found=1;	
				}
			          
			          
			}
			else if(demsotu(name[i])==4){
				if(strcmp(nameC,ten2)==0 || strcmp(nameC,dem1)==0 || strcmp(nameC,dem2)==0 || strcmp(nameC,ho2)==0 ){
				
					printf("code:%s",code[i]);
					printf("\nname:%s",name[i]);
					printf("\ndate:%s",date[i]);
					printf("\npoint:%0.2f",point[i]);
					printf("\n");
					found=1;	
				}
				else if(strcmp(nameC,name[i])==0){
					printf("code:%s",code[i]);
					printf("\nname:%s",name[i]);
					printf("\ndate:%s",date[i]);
					printf("\npoint:%0.2f",point[i]);
					printf("\n");
					found=1;	
				
				}
				else if(strcmp(nameC,ten1)==0 && strcmp(nameC,dem1)==0 && strcmp(nameC,dem2)==0 &&strcmp(nameC,ho2)==0 ){
					printf("code:%s",code[i]);
					printf("\nname:%s",name[i]);
					printf("\ndate:%s",date[i]);
					printf("\npoint:%0.2f",point[i]);
					printf("\n");
					found=1;	
				}
				
			}
		}
			if(found==0){
				          printf("Do not exist\n");
			          }
}
int display(char code[][50], char name[][50], char date[][50], float point[50], int &k)
{         
int i;
          printf("Print list student  \n");	
			for(i=0;i<k;i++){
		                   printf("\n%s",code[i]);
				printf("\n%s",name[i]);
				printf("\n%s",date[i]);
				printf("\n%0.2f",point[i]);
				printf("\n");
	                    }
}
int main(){
	char code[50][50];
	char name[50][50];
	char date[50][50]; 
	float point[50];
    char ten[50];
	char dem[50];
	char ho[50];
	char ten1[50];
	char lot[50];
	char ten2[50];
	char dem1[50];
	char dem2[50]; 
	char ho2[50];
	int k=0;
	char name1[50] = "file1.txt";
	int n;
        do{
	        printf("1. Enter student list\n");
	        printf("2. Look up student\n");
	        printf("3. Display student list\n");
	        printf("4. Exit\n");
	        printf("Please choose menu(1-4):\n");
	        n=input(); fflush(stdin);
	            switch(n){ 
		            case 1:   
		                enterstd(code, name, date, point,k);
		                WriteDataToFile(code, name, date, point,k,name1);
		                system("pause");
			            system("cls");
			            break;
		            case 2:
			            ReadDataFromFile(code, name, date, point,k,name1);
			            lookstd(code,name,date,point,ten,dem,ho, ten1, lot,ten2, dem1, dem2, ho2,k);
		                system("pause");
			            system("cls");
			            break;	
		            case 3:
			            ReadDataFromFile(code, name, date, point,k,name1);
		                display(code, name, date, point,k);
                        system("pause");
			            system("cls");
	                    break;
	          case 4: 
	                   return 0;
	                   break;
		    }
	    }while (1);	
return 0;
}

