#include<stdio.h>

int main()
{
    int a;
    int b;
    printf("���� : ");
    scanf("%d",&a);
    printf("���԰�����\t:%10d%10d\n",3,6);
    b=a*1.05*1.05*1.05;
    printf("�ѳ��Ա�\t:%10d%10d\n",a,b);
    printf("�������Ա�\t:%10.2f%10.2f\n",(float)a/3,(float)b/6);
}
