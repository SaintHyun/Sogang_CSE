#include<stdio.h>

//20201564 �輺��

int main()
{
    char ch;  //ch�� ������ ����
    int integer; //integer�� ������ ����
    float real;  //real�� �Ǽ��� ����

    printf("Input one character, one integer, one real number : ");
    scanf("%c%d%f",&ch,&integer,&real);  //scanf() �Լ��� ���� ���� �Է� �޴´�. �̶� ���� �̸� �տ� &�� ���δ�.
    printf("%c %d %f\n",ch,integer,real); //printf()�Լ��� ���� ���� ����Ѵ�. ���� �Է¹ް� ����� �� type�� ���� �ٸ� ���Ĺ���(%c,%d,%f)�� ����Ѵ�.
    return 0;
}

