#include<stdio.h>

int *merge(int *ary1, int size1, int *ary2, int size2, int *ary3, int size3)
{
    int *a;
    int i,j,tmp;
    a=(int *)calloc(12,sizeof(int));
    j=0;
    for(i=0; i<12; i++)
    {
        if(i<3) a[i]=ary1[j];
        else if(i<7) a[i]=ary2[j-3];
        else a[i]=ary3[j-7];
        j++;
    }
    for(i=0; i<11; i++)
    {
        for(j=i+1; j<12; j++)
        {
            if(a[j]<a[i])
            {
                tmp=a[j]; a[j]=a[i]; a[i]=tmp;
            }
        }
    }
    return a;
}

int main()
{
    int *a;
    int *ary1,*ary2,*ary3;
    int i,j;
    a=(int *)calloc(12,sizeof(int));
    ary1=(int *)calloc(3,sizeof(int));
    ary2=(int *)calloc(4,sizeof(int));
    ary3=(int *)calloc(5,sizeof(int));
    printf("Input 12 integer : ");
    for(i=0; i<12; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array 1\t: ");
    for(i=0; i<12; i++)
    {
        if(i<3)
        {
            ary1[i]=a[i];
            printf("%d ",ary1[i]);
            if(i==2) printf("\nArray 2\t: ");
        }
        else if(i<7)
        {
            ary2[i-3]=a[i];
            printf("%d ",ary2[i-3]);
            if(i==6) printf("\nArray 3\t: ");
        }
        else
        {
            ary3[i-7]=a[i];
            printf("%d ",ary3[i-7]);
        }
    }
    a=merge(ary1,3,ary2,4,ary3,5);
    printf("\nResult Array : ");
    for(i=0; i<12; i++)
    {
        printf("%d ",a[i]);
    }
}
