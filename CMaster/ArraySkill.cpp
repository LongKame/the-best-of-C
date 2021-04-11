#include<stdio.h>
#include<string.h>
#include<ctype.h>

int k=0;
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
int add(int a[], int b[])
{
          int i,m=1;
		printf("Enter new value:\n");
			for(i=k;i<k+m;i++){
			printf("value %d: \n",i+1);
			          printf("Enter value: ");
				a[i]=input(); 
				b[i]=a[i];    
			}
			k+=m;
}
int search(int a[])
{
int chi_so[50], found=0;
int i, j, m, h;

          
	printf("Nhap gia tri k:"); scanf("%d", &h);
	
	j=0;
	for(i=0;i<k;i++){
		if(a[i]==h){
			chi_so[j]=i;
			j++;
			found=1;
		}
	}
	
	m=j;
	for(i=0;i<m;i++){
		printf("\nHien thi mang chi_so %d:", chi_so[i]);
	}
	if(found==0){
		printf("not exist");
	}

}
void remove(int a[])
{
	int i,j,X;
	int num;
	printf("nhap vao phan tu muon xoa: ");
	scanf("%d",&X);
	for(i = 0; i < k; i++)
	{
		if(a[i]==X){
			for(j=i;j<k;j++){
				num=a[j];
				a[j]=a[j+1];
				a[j+1]=num;
				}
				k--;
				break;
			
		}
	}
}
int Xoa1PhanTu(int a[], int ViTriXoa)
{
	for(int i = ViTriXoa; i < k; i++)
	{
		a[i] = a[i + 1];
	}
	k--;
}
int removeall(int a[])
{
	int i,S;
	printf("nhap vao phan tu muon xoa: ");
	scanf("%d",&S);
          for(int i = 0; i < k; i++)
	{
		if((a[i]) == S)
		 {
			Xoa1PhanTu(a, i);
			i--;
		}
	}
}
int output(int a[])
{
	for(int i = 0; i < k; i++)
	{
		printf("%4d", a[i]);
	}
	if(k==0){
		printf("Ko co du lieu");
	}
}
void HoanVi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SapXepTangDan(int a[])
{
	for(int i = 0; i < k - 1; i++)
	{
		for(int j = i + 1; j < k; j++)
		{
			if(a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
void SapXepGiamDan(int a[])
{
	for(int i = 0; i < k - 1; i++)
	{
		for(int j = i + 1; j < k; j++)
		{
			if(a[i] < a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
int outputintitial(int b[])
{
	int i;
	for(i=0;i<k;i++){
		printf("%4d",b[i]);
	}
}
int main()
{
	int select;
	int a[50], b[50];
	char Nc;
	while(1){
	printf("\n1.Add a value\n");
	printf("\n2.Search a value\n");
	printf("\n3.Remove the first existence of value\n");
	printf("\n4.Remove all existences of value\n");
	printf("\n5.Print out the array\n");
	printf("\n6.Sort asc\n");
	printf("\n7.Sort desc\n");
	printf("\n8.Output array presort");

	printf("Your chose 1-->5: ");
	select=input();
	switch(select){
		case 1:   add(a,b);
		          break;
		case 2:   search(a);
		          break;
		case 3:   remove(a);
			break;
		case 4:   removeall(a);
		          break;
		case 5:   output(a);
	                    break;
	          case 6:   SapXepTangDan(a);
	                    break;
	          case 7:    SapXepGiamDan(a);
	                    break;
	          case 8:   outputintitial(b);
	                    break;
 	          }
}
return 0;
}



