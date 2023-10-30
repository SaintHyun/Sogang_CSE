#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char dept_name[20];
	int dept_no;
}dept;

enum Gender { Male=0, Female};

typedef struct
{
	int employee_id;
	char name[40];
	enum Gender gender;
	dept department;
	double salary;
}employee_data;

int search(employee_data *e, int num, int keyword)
{
	int i;
	for(i=1; i<=num; i++)
	{
		if(e[i].employee_id==keyword) return i;
	}
	return 0;
}
employee_data update(employee_data e, int n)
{
	char nul[20]={0,};
	dept new[5]={{"FINANCE",1},{"SALES",2},{"RESEARCH",3},{"PLANNIN",4}};
	strcpy(e.department.dept_name,nul);
	strcpy(e.department.dept_name,new[n-1].dept_name);
	e.department.dept_no=new[n-1].dept_no;
	return e;
}

int main()
{
	employee_data *a;
	FILE *fp;
	fp=fopen("16_input.txt","r");
	int n;
	fscanf(fp,"%d",&n);
	int i,j=0,q;
	char whether;
	char nul[40]={0,};
	char first[40]={0,},last[40]={0,},gen[20]={0,};
	int number,newnumber;
	a=(employee_data*)calloc(n+2,sizeof(employee_data));
	for(i=1; i<=n; i++)
	{
	//	fscanf(fp,"%d / %s",&a[i].employee_id,first);
		fscanf(fp,"%d / %40[^/] / %s / %s / %d / %lf",&a[i].employee_id, a[i].name,gen,a[i].department.dept_name,&a[i].department.dept_no,&a[i].salary);
		//first[strlen(first)]=' ';
		//printf("%d %s / %s\n",i,first,last);
		//strcat(first,last);
		//strcpy(a[i].name,first);
		//for(j=0; j<40; j++) first[j]=0;
		//strcpy(last,nul);
	//	printf("%s\n",gen);
		if(strcmp(gen,"Male")==0)   a[i].gender=0;
		else a[i].gender=1;
		strcpy(gen,nul);
	//	printf("%d %s %s\n",i,first,last);
	}
	//printf("%d, %d %s",n,a[1].employee_id,a[1].name);
	do
	{
		printf("Employee ID : ");
		scanf("%d",&number);
		j=search(a,n,number);
		if(j==0) printf("No employee\n");
		if(j!=0)
		{
			printf("------Employee data------\n");
			if(a[j].gender==0)
				printf("%d / %s / Male / %s / %02d / %.2lf\n",a[j].employee_id,a[j].name,a[j].department.dept_name,a[j].department.dept_no,a[j].salary);
			else printf("%d / %s / Female / %s / %02d / %.2lf\n",a[j].employee_id,a[j].name,a[j].department.dept_name,a[j].department.dept_no,a[j].salary);
			printf("------Update Information------\n");
			printf("Input the department number : ");
			scanf("%d",&q);
			a[j]=update(a[j],q);
			printf("------Updated employee data------\n");
			if(a[j].gender==0)
			printf("%d / %s / Male / %s / %02d / %.2lf\n",a[j].employee_id,a[j].name,a[j].department.dept_name,a[j].department.dept_no,a[j].salary);
			else printf("%d / %s / Female / %s / %02d / %.2lf\n",a[j].employee_id,a[j].name,a[j].department.dept_name,a[j].department.dept_no,a[j].salary);
		}
		printf("Continue? (y/n) : ");
		scanf("\n%c",&whether);
	}while(whether=='y');
}

		


