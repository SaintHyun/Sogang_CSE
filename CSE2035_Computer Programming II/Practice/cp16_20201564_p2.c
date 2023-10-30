#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int number;
	char id[50];
	char pw[50];
	char name[50];
	char address[50];
}customer;

int main()
{
	FILE *fp,*fp2;
	char id[50],pw[50];
	char h1[1000];
	int k=0,li=0,lp=0,l=1;
	char head[1000];
	customer a[1000];
	printf("로그인 프로그램\n");
	printf("아이디 : ");
	scanf("%s",id);
	printf("패스워드 : ");
	scanf("%s",pw);
	int i=0;
	int num,idf,p,na,add;
	fp=fopen("customer.txt","r");
	fp2=fopen("customer.txt","r");
	fscanf(fp,"%s",head);
	fscanf(fp2,"%s",head);
	while(fgets(h1,1000,fp)!=NULL)
	{
		k++;
		fscanf(fp2,"%d,%50[^,],%50[^,],%50[^,],%50[^'\n']",&a[k].number,a[k].id,a[k].pw,a[k].name,a[k].address);
	//	printf("\n id: %s pw: %s \n",a[k].id,a[k].pw);
	}
	do
	{
		for(i=1; i<=k; i++)
		{
			if( strcmp(a[i].id,id)==0 )
			{
				lp=i;
				li=1;
			}
		}
		if(li==1 && strcmp(a[lp].pw,pw)==0)
		{
			printf("===================\n");
			printf("회원번호 : %d\n",a[lp].number);
			printf("아이디 : %s\n",a[lp].id);
			printf("패스워드 : %s\n",a[lp].pw);
			printf("이름 : %s\n",a[lp].name);
			printf("주소 : %s\n",a[lp].address);
			return 0;
		}
		else{ printf("일치하는 회원이 없습니다.\n");}
		if(l==3) break;
		printf("아이디 : ");
		scanf("%s",id);
		printf("패스워드 : ");
		scanf("%s",pw);
		l++;
	}while(l<=3);
}



			
