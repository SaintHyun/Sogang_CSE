#include<stdio.h>

void func(int a[100][100], int b[100][100], int c[100][100], int N, int op)
{
    int i,j,k;
    if(op==0)
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                *(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
            }
        }
    }
    if(op==1)
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                *(*(c+i)+j)=*(*(a+i)+j)-*(*(b+i)+j);
            }
        }
    }
    if(op==2)
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                for(k=0; k<N; k++)
                {
                    *(*(c+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);
                }
            }
        }
    }
}

int main()
{
    int n,k;
    int i,j;
    int a[100][100]={0,},b[100][100]={0,},c[100][100]={0,};

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",(*(a+i)+j));
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",(*(b+i)+j));
        }
    }
    scanf("%d",&k);
    func(a,b,c,n,k);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",*(*(c+i)+j));
        }
        printf("\n");
    }
}
