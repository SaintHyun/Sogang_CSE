#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int num;
	char name[20];
	int level;
	char type1[30];
	char type2[30];

	char sk1[20];
	char sk2[20];
	char sk3[20];
	char sk4[20];
}dex;

typedef struct
{
	int inx;
	char name[10];
	char region[10];
	dex poke[6];
}user;

int main()
{
	int n=0,i=0,j=0,inin=0,k,l=0;
	user *a;
	a=(user*)calloc(1000,sizeof(user));
	FILE *fp1,*fp2;
	char h[1000];
	int difference=0;
	char iname[20],iregion[10],dname[20],dtype[100];
	char dtype1[30],dtype2[30];
	char s1[20],s2[20],s3[20],s4[20];
	char nul[60]={0,};
	int dnum,dlevel;
	fp1=fopen("user.txt","r");
	fp2=fopen("user.txt","r");
	while(fgets(h,1000,fp1)!=NULL)
	{
		fscanf(fp2,"%10[^\t]\t%10[^\t]\t%d\t%20[^\t]\t%d\t%50[^\t]\t%20[^,],%20[^,],%20[^,],%20[^\n]\n",iname,iregion,&dnum,dname,&dlevel,dtype,s1,s2,s3,s4);
	//	printf("iname: %s iregion: %s dnum: %d dname: %s dlevel: %d dtype: %s\n\n",iname,iregion,dnum,dname,dlevel,dtype);
		difference=0;
		inin=0; l=0;
		for(i=0; i<30; i++)
		{
			dtype1[i]=0; dtype2[i]=0;
		}
	//	strcpy(dtype1,nul);
	//	strcpy(dtype2,nul);
		for(i=0; dtype[i]!=0; i++)
		{
			if(dtype[i]==',')
			{
				inin=1;
				//printf("\n%d %d\n",i,l);
				continue;
			}
			if(inin==0){ dtype1[i]=dtype[i]; l++;}
			else if(inin==1)
				dtype2[i-l-1]=dtype[i];
		}
	//	printf(" dtype1: %s dtype2: %s\n\n",dtype1, dtype2);
		for(i=1; i<=n; i++)
		{
			if( strcmp(a[i].name, iname) == 0)
			{
				difference=1;
				a[i].inx++;
				strcpy(a[i].poke[a[i].inx].name,dname);
				a[i].poke[a[i].inx].num=dnum;
				a[i].poke[a[i].inx].level=dlevel;
				strcpy(a[i].poke[a[i].inx].type1,dtype1);
				strcpy(a[i].poke[a[i].inx].type2,dtype2);
				k=i;
				break;
			}
		}
		if(difference!=1)
		{
			n++;
			a[n].inx++;
			strcpy(a[n].name,iname);
			strcpy(a[n].region,iregion);
			strcpy(a[n].poke[a[n].inx].name,dname);
			a[n].poke[a[n].inx].num=dnum;
			a[n].poke[a[n].inx].level=dlevel;
			strcpy(a[n].poke[a[n].inx].type1,dtype1);
			strcpy(a[n].poke[a[n].inx].type2,dtype2);
			k=n;
		}
		strcpy(a[k].poke[a[k].inx].sk1,s1);
		strcpy(a[k].poke[a[k].inx].sk2,s2);
		strcpy(a[k].poke[a[k].inx].sk3,s3);
		strcpy(a[k].poke[a[k].inx].sk4,s4);
	//	fscanf(fp2,"%20[^,],%20[^,],%20[^,],%20[^\n]\n",a[k].poke[a[k].inx].sk1,a[k].poke[a[k].inx].sk2,a[k].poke[a[k].inx].sk3,a[k].poke[a[k].inx].sk4);
		//fgets(h,1000,fp1);
	}
	printf("Number of Users = %d\n\n",n);
	for(i=1; i<=n; i++)
	{
		printf("[Name] %s(%s)\n",a[i].name,a[i].region);
		printf(" [Pokemon]\n");
		for(j=1; j<=a[i].inx; j++)
		{
			printf("  [Name]%s(%d)\n",a[i].poke[j].name,a[i].poke[j].num);
			printf("  [Level]%d\n",a[i].poke[j].level);
			if(a[i].poke[j].type2[0]!=0)
			{
				printf("  [Type1]%s\n",a[i].poke[j].type1);
				printf("  [Type2]%s\n",a[i].poke[j].type2);
			}
		//	printf("\ndtype2 : %c\n",a[i].poke[j].type2[1]);
			else printf("  [Type]%s\n",a[i].poke[j].type1);
			printf("  [Skill1]%s\n",a[i].poke[j].sk1);
			printf("  [Skill2]%s\n",a[i].poke[j].sk2);
			printf("  [Skill3]%s\n",a[i].poke[j].sk3);
			printf("  [Skill4]%s\n",a[i].poke[j].sk4);
			printf("\n");
		}
	}
			

}


