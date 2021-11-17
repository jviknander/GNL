#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	
	fd = open("ricardo.txt", O_CREAT | O_RDWR);
	printf("%s\n", get_next_line(fd));
}
