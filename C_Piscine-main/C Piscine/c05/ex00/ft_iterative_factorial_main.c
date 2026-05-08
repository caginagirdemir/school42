#include <stdio.h>

int ft_atoi(char *str)
{
	int i = 0;
	int result;

	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - 48;
		i++;
	}
	return(result);
}

int	ft_iterative_factorial(int	nb)
{
	unsigned int	result;

	result = 1;
	while (nb > 0)
	{
		 result *= nb;
		nb--;
	}
	if (nb < 0)
	{
		return (0);
	}
	return (result);
}

int main (int argc, char **argv)
{
	int a = ft_atoi(argv[1]);
	printf("%i", ft_iterative_factorial(a));
}
