#include<stdio.h>

float a,b,c,d;
float avgFunc();
float gradeFunc();

int main()
{

    printf("Input: ");
    scanf("%f%f%f",&a,&b,&c);
    avgFunc();
}

float avgFunc()
{
    d=(a+b+c)/3.0;
    gradeFunc();
}

float gradeFunc()
{
    if(d>=50)
    {
        if(d>=90) printf("Grade: A");
        else
        {
            if(d>=80) printf("Grade: B");
            else
            {
                if(d>=70) printf("Grade: C");
                else printf("Grade: D");
            }
        }

    }
    else printf("Grade: F");
}
