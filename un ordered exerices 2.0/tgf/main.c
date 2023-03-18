#include <stdio.h>

int main()
{
    int ch;
    printf("please type in one character:\n");
    ch = getc(stdin);
    printf("The character you just entered is:%c\n",ch);
    return 0;

}
