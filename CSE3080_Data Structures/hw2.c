#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void InsertMin(int num, int size);
void InsertMax(int num, int size);
int DeleteMin(int *a, int size);
int DeleteMax(int *a, int size);
void printA(int size);
void printD(int size);

int cur=0, min[1000010], max[1000010];

int main(int argc, char *argv[])
{
	int num=0;
	char command[15]={0,};
	
	clock_t runs=clock();
	if(argc!=2)
	{
		printf("usage: ./hw2 input_filename\n");
		return 0;
	}
	FILE *fp1,*fp2;
	if((fp1=fopen(argv[1],"r"))==NULL)
	{
		printf("The input file does not exist\n");
		return 0;
	}
	fp2=fopen("hw2_result.txt","w");
	fclose(fp2);
	
	while(1)
	{
		if(fscanf(fp1,"%s",command)==EOF || !strcmp(command,"\n")) break; //프로그램 종료
		if(!strcmp(command,"INSERT"))
		{
			fscanf(fp1,"%d",&num);
			cur++;
			InsertMin(num,cur);
			InsertMax(num,cur);
		} //Insert
		else if(!strcmp(command,"ASCEND"))
		{
			printA(cur);
		}//ASCENDING
		else if(!strcmp(command,"DESCEND"))
		{
			printD(cur);
		}//DESCENDING
	}
	clock_t rune=clock();
	printf("output written to hw2_result.txt.\n");
	printf("running time: %lf seconds\n",(double)(rune-runs)/CLOCKS_PER_SEC);
	fclose(fp1);
	return 0;
}

void InsertMin(int num, int size)
{
	min[size]=num;

	int i=size;
	int k=min[i];
	while(i!=1 && k<min[i/2])
	{
		min[i]=min[i/2];
		i/=2;
	}
	min[i]=k;
}

void InsertMax(int num, int size)
{
	max[size]=num;

	int i=size;
	int k=max[i];
	while(i!=1 && k>min[i/2])
	{
		max[i]=max[i/2];
		i/=2;
	}
	max[i]=k;
}

void printA(int size)
{
	FILE *fp;
	fp=fopen("hw2_result.txt","a");
	int tmp[1000010],i,output;
	for(i=1; i<=size; i++)
	{
		tmp[i]=min[i];
	}
	for(i=size; i>=1; i--)
	{
		output=DeleteMin(tmp,i);
		fprintf(fp,"%d ",output);
	}
	fprintf(fp,"\n");
	fclose(fp);
}

int DeleteMin(int *a, int size)
{
	int parent=1, child=2;
	int output=a[1];
	int num=a[size--];
	a[1]=a[size]; // set root
	while(child<=size)
	{
		if(child<size && a[child]>a[child+1]) child++;
		if(num<=a[child]) break;
		a[parent]=a[child];
		parent=child;
		child*=2;
	}
	a[parent]=num;
	return output;
}

void printD(int size)
{
	FILE *fp;
	fp=fopen("hw2_result.txt","a");
	int tmp[1000010],i,output;
	for(i=1; i<=size; i++)
	{
		tmp[i]=max[i];
	}
	for(i=size; i>=1; i--)
	{
		output=DeleteMax(tmp,i);
		fprintf(fp,"%d ",output);
	}
	fprintf(fp,"\n");
	fclose(fp);
}

int DeleteMax(int *a, int size)
{
	int parent=1, child=2;
	int output=a[1];
	int num=a[size--];
	a[1]=a[size];
	while(child<=size)
	{
		if(child<size && a[child]<a[child+1]) child++;
		if(num>=a[child]) break;
		a[parent]=a[child];
		parent=child;
		child*=2;
	}
	a[parent]=num;
	return output;
}


	
