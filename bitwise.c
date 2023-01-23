#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int binarytodecimal(char *num)
{
    int i = ft_strlen(num);
    int deci_num = 0;
    int mul = 1;
    while (--i >= 0)
    {
        deci_num = deci_num + (num[i] - 48) * mul;
        mul *= 2;
    }
    return (deci_num);
}

int main()
{
    // int i  = 7;
    // char c = '9';
    // while (i >= 0)
    // {
    //     if ((c & (1 << i)) != 0)
    //         printf("1");
    //     else
    //         printf("0");
    //     i--;
    // }
    // printf("\n");
    // convert from binary to decimal
    char num[] = "01100001";
    printf("%s\n", num);
    printf("the binary %s in decimal is : %c", num, binarytodecimal(num));
}