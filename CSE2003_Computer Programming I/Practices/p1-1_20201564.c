#include<stdio.h>

//20201564 김성현

int main()
{
    char ch;  //ch는 문자형 변수
    int integer; //integer는 정수형 변수
    float real;  //real은 실수형 변수

    printf("Input one character, one integer, one real number : ");
    scanf("%c%d%f",&ch,&integer,&real);  //scanf() 함수를 통해 값을 입력 받는다. 이때 변수 이름 앞에 &를 붙인다.
    printf("%c %d %f\n",ch,integer,real); //printf()함수를 통해 값을 출력한다. 값을 입력받고 출력할 때 type에 따라 다른 형식문자(%c,%d,%f)를 사용한다.
    return 0;
}

