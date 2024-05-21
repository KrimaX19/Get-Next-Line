#include <stdio.h>

int	main(void)
{
	char	*s;
	int		i;
	int		fd;
	i = 0;
	fd = open ("./text/Texto1.txt", O_RDONLY);
	s = get_next_line(fd);
	while (i < 10)
	{
		printf("Line: %d, \n%s", i, s);
		s = get_next_line(fd);
		i++;
	}
	return (0);
}
