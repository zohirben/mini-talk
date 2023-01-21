#include <stdio.h>

int main()
{
    int i  = 7;
    char c = '9';
    while (i >= 0)
    {
        if ((c & (1 << i)) != 0)
            printf("1");
        else
            printf("0");
        i--;
    }
    printf("\n");
}