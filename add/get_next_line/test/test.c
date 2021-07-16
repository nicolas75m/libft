#include "../srcs/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("text.txt", 0);
	char *line;
	int i;
	while ((i = (get_next_line(fd, &line))) > 0)
	{
		printf("i = %i\n", i);
		printf("|%s|\n", line);
		free(line);
	}
	printf("i = %i\n", i);
	printf("|%s|\n", line);
	free(line);
	close(fd);
	// pause();
	return (0);
}
