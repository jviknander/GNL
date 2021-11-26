#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *str;
//	size_t		buffer = 100;
//	ssize_t		ret;

/*
//	printf("%zu", buffer);
	fd = open("ricardo.txt", O_CREAT | O_RDWR);
//	printf("%s\n", get_next_line(fd));
//	ret = read (fd, str, buffer);
	read (fd, str, buffer);
	printf("%s", str);
	fd = open("ricardo.txt", O_CREAT | O_RDWR);
	read (fd, str, buffer);
	printf("%s", str);
	//printf("%s\n",get_next_line(fd));
*/
	fd = open("ricardo.txt", O_CREAT | O_RDWR);
	str = get_next_line(fd);
	printf("linha: %s\n", str);
	str = get_next_line(fd);
	printf("linha 2 %s\n", str);
	printf("linha 3 %s\n", get_next_line(fd));
	printf("linha 4 %s\n", get_next_line(fd));
	printf("linha 5 %s\n", get_next_line(fd));
	printf("linha 6 %s\n", get_next_line(fd));
	printf("linha 7 %s\n", get_next_line(fd));
	printf("linha 8 %s\n", get_next_line(fd));
	printf("linha 9 %s\n", get_next_line(fd));
	/*
	while (str)
	{
		printf("%s\n", str);
		str = get_next_line(fd);
	}*/
}
