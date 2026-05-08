#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		result *= 10;
		result = result + str[i] - 48;
		i++;
	}
	return (result * sign);
}

int	*ft_range(int min, int max)
{
	int	*size;
	int	diff;
	int	i;

	i = 0;
	diff = max - min;
	if (diff <= 0)
		write (1, "null", 4);
	size = (int *)malloc(diff * sizeof(int));
	while (diff > 0)
	{
		size[i] = min;
		min++;
		i++;
		diff--;
	}
	return (size);
}
#include <stdio.h>
int main()
{
	int *array;
	int i;

	array = ft_range(-4,4);
	i = 0;
	while (i<8)
	{
		printf("%d", array[i]);
		i++;
	}
}
