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
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	/*while (str)
	{
		printf("%s\n", str);
		str = get_next_line(fd);
	}*/
}
