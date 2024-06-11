#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../get_next_line.h"

int	main(void)
{
	char	*s;
	int		i;
	int		fd;
	i = 0;
	fd = open ("./Teste/text/Texto1.txt", O_RDONLY);
	s = get_next_line(fd);
	while (i < 10)
	{
		printf("Line: %d:\n%s\n", i, s);
		s = get_next_line(fd);
		i++;
	}
	return (0);
}
