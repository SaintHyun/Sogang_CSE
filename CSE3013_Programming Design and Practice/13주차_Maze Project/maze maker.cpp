#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

typedef struct
{
   int num;
   int right;
   int down;
}Maze;

int n,m;
int starty,startx;
int *key,*temp; //key: 아래로 확장할 때 쓰임.
Maze **maze;
int set;

int check()
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(maze[i][j].num!=maze[1][1].num) return 0;
        }
    }
    return 1;
}

int findcnt(int y)
{
    int i,count=1;
    for(i=2; i<=m; i++)
    {
        if(maze[y][i].num!=maze[y][i-1].num) count++;
    }
    return count;
}

void process1(int y)
{
    int i,j,l,k,cnt=0,q,r;
    for(i=1; i<=m; i++)
    {
        temp[i]=maze[y][i].num;
    }
    for(i=1; i<=m-1; i++)
    {
        k=rand()%2;
        if(k && maze[y][i].num!=maze[y][i+1].num && temp[i]!=temp[i+1])
        {
            //set--;
            maze[y][i].right=0;
            q=maze[y][i].num<maze[y][i+1].num ? maze[y][i].num : maze[y][i+1].num;
            r=maze[y][i].num>=maze[y][i+1].num ? maze[y][i].num : maze[y][i+1].num;
            for(j=1; j<=n; j++)
            {
                for(l=1; l<=m; l++)
                {
                    if(maze[j][l].num==r) maze[j][l].num=q;
                }
            }
            //maze[y][i].num=maze[y][i+1].num;

            //maze[y][i+1].num=maze[y][i].num;
            //maze[y][i].num=cnt;
            //maze[y][i+1].num=maze[y][i].num;
        }
        else if(!k && maze[y][i].num!=maze[y][i+1].num)
        {
            key[++cnt]=i;
        }
    }
    //if(maze[y][i-1].right==1) maze[y][i].num=cnt;
    key[cnt+1]=m;
    /*printf("process1 \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            printf("%d ",maze[i][j].num);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("cnt: %d, key: ",cnt);
    for(i=1; i<=cnt+1; i++) printf("%d ",key[i]);
    printf("\n");*/
}

void process2(int y, int cnt)
{
    int i,j,x;
    for(i=1; i<=cnt; i++)
    {
        x=rand()%(key[i]-key[i-1])+key[i-1]+1;
        maze[y][x].down=0;
        maze[y+1][x].num=maze[y][x].num;
    }
    for(i=1; i<=m; i++)
    {
        if(rand()%2 && maze[y][i].down)
        {
            maze[y][i].down=0;
            maze[y+1][i].num=maze[y][i].num;
        }
    }
    /*printf("process2 \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            printf("%d ",maze[i][j].num);
        }
        printf("\n");
    }
    printf("\n\n");*/
}

void process3(int y)
{
    int i,j;
    for(i=1; i<=m; i++)
    {
        if(!maze[y+1][i].num)
        {
            maze[y+1][i].num=++set;
        }
    }
    /*printf("process3 \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            printf("%d ",maze[i][j].num);
        }
        printf("\n");
    }
    printf("\n\n");*/
}

void print()
{
    FILE *fp=fopen("output.maz","w");
    int i,j;
    for(i=1; i<=m; i++)
    {
        fprintf(fp,"+-");
    }
    fprintf(fp,"+\n");
    for(i=1; i<=n; i++)
    {
        fprintf(fp,"|");
        for(j=1; j<=m; j++)
        {
            fprintf(fp," ");
            if(maze[i][j].right==1) fprintf(fp,"|");
            else fprintf(fp," ");
        }
        fprintf(fp,"\n");
        for(j=1; j<=m; j++)
        {
            fprintf(fp,"+");
            if(maze[i][j].down==1) fprintf(fp,"-");
            else fprintf(fp," ");
        }
        fprintf(fp,"+\n");
    }
    //fclose(fp);
}

int main()
{
    srand(time(0));
    int i,j,l,q,r;
    scanf("%d%d",&m,&n);
    maze=(Maze**)malloc(sizeof(Maze*)*(n+2));
    key=(int*)malloc(sizeof(int)*(m+2));
    temp=(int*)malloc(sizeof(int)*(m+2));
    for(i=0; i<=n+1; i++)
    {
        maze[i]=(Maze*)malloc(sizeof(Maze)*(m+2));
    }

    startx=rand()%m+1;
    starty=rand()%n+1;

    do
    {
        set=0;
        for(i=1; i<=n+1; i++)
        {
            for(j=1; j<=m+1; j++)
            {
                maze[i][j].num=0;
                if(i==1) maze[1][j].num=++set;
                maze[i][j].right=1;
                maze[i][j].down=1;
            }
        }
        for(i=1; i<=n-1; i++)
        {
            for(j=0; j<=m; j++) key[j]=0;
            process1(i);
            process2(i,findcnt(i));
            process3(i);
        }
        for(i=1; i<=m; i++)
        {
            temp[i]=maze[n][i].num;
        }
        for(i=1; i<=m-1; i++)
        {
            if(maze[n][i].num!=maze[n][i+1].num && temp[i]!=temp[i+1])
            {
                maze[n][i].right=0;
                q=maze[n][i].num<maze[n][i+1].num ? maze[n][i].num : maze[n][i+1].num;
                r=maze[n][i].num>=maze[n][i+1].num ? maze[n][i].num : maze[n][i+1].num;
                for(j=1; j<=n; j++)
                {
                    for(l=1; l<=m; l++)
                    {
                        if(maze[j][l].num==r) maze[j][l].num=q;
                    }
                }
            }
        }
    }while(!check());
    print();
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            printf("%d ",maze[i][j].num);
        }
        printf("\n");
    }

    for(i=0; i<=n+1; i++)
    {
        free(maze[i]);
    }
    free(maze);
    return 0;
}
