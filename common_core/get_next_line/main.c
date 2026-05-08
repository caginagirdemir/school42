#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int 	fd;
	char	*str;
	int 	i;

	i = -1;
	fd = open("test.txt", O_RDONLY);
	while(++i < 9)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	close(fd);
	return (0);
}
