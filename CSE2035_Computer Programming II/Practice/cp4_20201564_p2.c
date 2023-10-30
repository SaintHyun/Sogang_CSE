#include<stdio.h>

void swap(int *a, int *b);
void sort(int *a, int m);
void all_sort(int a[][100], int n, int m);
int binary_search(int *a, int *endPtr, int key, int **findPtr);
int all_binary_search(int a[][100], int n, int m, int key, int **findPtr);

int main()
{
    int a[100][100];
    int n,m,k;
    int i,j;
    int *f;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    all_sort(a,n,m);
    printf("%d\n",all_binary_search(a,n,m,k,&f));
    if(all_binary_search(a,n,m,k,&f)==1)
    {
        printf("%#x",f);
    }
}

void swap(int *a, int *b)
{
    int t;
    t=*a; *a=*b; *b=t;
}
void sort(int *a, int m)
{
    int i,j;
    for(i=0; i<m-1; i++)
    {
        for(j=i+1; j<m; j++)
        {
            if(a[i]>a[j]) swap(&a[j],&a[i]);
        }
    }
}
void all_sort(int a[][100], int n, int m)
{
    int i;
    for(i=0; i<n; i++)
    {
        sort(a[i],m);
    }
}
int binary_search(int *a, int *endPtr, int key, int **findPtr)
{
    int *first,*middle,*last;
    first=a; last=endPtr;
    while(first<=last)
    {
        middle=first+(last-first)/2;
        if(key>*middle) first=middle+1;
        else if(key<*middle) last=middle-1;
        else first=last+1;
    }
    if(key==*middle)
    {
        *findPtr=middle;
        return 1;
    }
    else return 0;
}
int all_binary_search(int a[][100], int n, int m, int key, int **findPtr)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(binary_search(a[i],&a[i][m-1],key,findPtr)==1)
        {
            return 1;
        }
    }
    return 0;
}
