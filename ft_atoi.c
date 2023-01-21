#include <unistd.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
    int i;
    int number;
    int sign;

    sign = 1;
    i = 0;
    number = 0;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        number *= 10;
        number += (str[i] - '0');
        i++;
    }
    return (number * sign);
}

int main()
{
    char number[] = "1234";

    printf("%i\n", ft_atoi(number));
}