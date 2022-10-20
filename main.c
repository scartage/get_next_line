
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char *get_next_line(int fd);

int main()
{
	int file_d;
	int i;
	char *line;

	i = 0;
	file_d = open("chuletilla.txt", O_RDONLY);
	/*while (i < 10)
	{
		printf("ln %s (%d)\n", get_next_line(file_d), i);
		i++;
	}*/
	line = get_next_line(file_d);
	printf("%s\n", line);
	return (0);
}
