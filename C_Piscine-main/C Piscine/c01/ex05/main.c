#include <stdio.h>

void	ft_putstr(char *str);

int	main()
{
	char str[] = "Hello";
	char *p_str;

	p_str = str;
	ft_putstr(p_str);
}
