#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char number[8];
    int credit;
    double grade;
}subject;

typedef struct
{
    int id;
    int number_of_course;
    subject *courses;
}student;

double calcCGPA(student s)
{
    double sum=0;
    int i;
    int sumcredit=0;
    for(i=1; i<=s.number_of_course; i++)
    {
        sum+=(double)s.courses[i].credit*s.courses[i].grade;
        sumcredit+=s.courses[i].credit;
    }
    return (double)sum/sumcredit;
}

int main()
{
    int n;
    scanf("%d",&n);
    student *a=(student *)calloc(n+2,sizeof(student));
    int i,j;
    for(i=1; i<=n; i++)
    {
        scanf("%d%d",&a[i].id,&a[i].number_of_course);
        a[i].courses=(subject*)calloc(a[i].number_of_course+2,sizeof(subject));
        for(j=1; j<=a[i].number_of_course; j++)
        {
            scanf("%s%d%lf",a[i].courses[j].number,&a[i].courses[j].credit,&a[i].courses[j].grade);
        }
    }
    printf("==========\n");
    for(i=1; i<=n; i++)
    {
        printf("%d / %.6lf\n",a[i].id,calcCGPA(a[i]));
    }
}
