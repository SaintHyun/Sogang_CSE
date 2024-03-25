#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char buf[64];
    read(0, buf, 128);
    printf(buf);
}