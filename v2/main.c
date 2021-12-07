#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDWR);
	while ((str = get_next_line(fd)))
	{
		printf("%s\n", str);
	}
}
