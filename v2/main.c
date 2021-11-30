#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDWR);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(fd);
	}
}
