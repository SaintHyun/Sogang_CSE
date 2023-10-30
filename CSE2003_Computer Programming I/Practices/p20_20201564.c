#include<stdio.h>

int main()
{
    int n,sum=0,a,cnt=0;
    int c;
    printf("Number of class: ");
    scanf("%d",&n);
    printf("Cutline: ");
    scanf("%d",&c);
    for(int i=0; i<n; i++)
    {
        printf("Input score #%d: ",i);
        scanf("%d",&a);
        sum+=a;
        if(a<c) cnt++;
    }
    printf("Average score: %.2f\n",(float)sum/n);
    printf("Number of failures: %d",cnt);

}
