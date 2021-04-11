#include<stdio.h> 
#include<string.h>
#include<ctype.h>

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
int add(char str[][50], int &k)
{	
          int i,m=1;
		printf("Enter new student:\n");
			for(i=k;i<k+m;i++){
			printf("Student %d\n",i+1);
			          printf("Student name: ");
	                                        fflush(stdin);
			                    gets(str[i]);
			}
			k+=m;

}
int remove(int &k, char strD[], char strS[], char str[][50], char t[])
{               
    int found = 0;
     printf("Enter name that remove: ");
    fflush(stdin);
     gets(strD);
    for(int i = 0; i < k; i++) {
        if (strcmp(str[i],strD) == 0) {
            found = 1;
            for (int j = i; j < k; j++) {
                 strcpy(str[j],str[j+1]);
                 }
            k--;
            printf("\n Remove succesfully\n");
            break;
        }
    }
    if (found == 0) {
         printf("\n Do not exist.\n");
        return 0;
    } else {
        return 1;
    }
}
int search(int &k, 	char strS[], char str[][50], char chi_so[])
{
	int found=0;
	int f, i;
          printf("Enter name that search: ");
		          fflush(stdin);
		          gets(strS);
		                    f=0;
		                    for(i=0;i<k;i++){
		          	          if(strcmp(str[i],strS) == 0){
		          	          	printf("%s",strS);
		          	          	chi_so[f]=i;
		          	          	f++;
		          	          	found++;
					}
				}
			          for(i=0;i<f;i++){
			          	int S=chi_so[i];
   	                              printf(" o vi tri do la %d \n" ,S+1);}
   
				if(found==0){
			          	printf("\nDo not exist\n");
				}
}
int outputascending(int &k, char str[][50], char t[])
{
	int i,j;
          for(i=0;i<k-1;i++){
		for(j=i+1;j<k;j++){
			          if(strcmp(str[i], str[j])>0){
				                    strcpy(t, str[i]);
				                    strcpy(str[i], str[j]);
				                    strcpy(str[j], t);
					          }
					}
				}
			printf("Print list student in an ascending: \n");	
			for(i=0;i<k;i++){
		                    printf("%s\n" ,str[i]);
	                    }

int main()
{
	int select,k=0;
	char strD[50], strS[50], str[50][50], chi_so[50], t[100], Nc;
	while(1){
	printf("1.Add a student name into the array.\n");
	printf("2.Remove a student name.\n");
	printf("3.Search a student name.\n");
	printf("4.Output student names in ascesding orders alphabetically.\n");
	printf("5.Exit the program.\n");

	printf("Your chose 1-->5: ");
	select=input();
	switch(select){
		case 1:   add(str,k);
		          break;
		case 2:   remove(k,strD,strS,str,t);
		          break;
		case 3:   search(k,strS,str,chi_so);
			break;
		case 4:   outputascending(k,str,t);
	                    break;
	          case 5:
	          	return 0;
	          	break;
 	          }
}
return 0;
}



