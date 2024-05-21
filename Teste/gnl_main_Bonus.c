#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;

	i = 1;
	fd1 = open ("./text/Texto1.txt", O_RDONLY);
	fd2 = open ("./text/Texto2.txt", O_RDONLY);
	fd3 = open ("./text/Texto3.txt", O_RDONLY);
	fd4 = open ("./text/Texto4.txt", O_RDONLY);
	fd5 = open ("./text/Texto5.txt", O_RDONLY);
	s1 = get_next_line(fd1);
	s2 = get_next_line(fd2);
	s3 = get_next_line(fd3);
	s4 = get_next_line(fd4);
	s5 = get_next_line(fd5);
	while (i <= 10)
	{
		printf("\nFD: %d\nLine: %d, \n%s\n",fd1, i, s1);
		s1 = get_next_line(fd1);
		printf("FD: %d\nLine: %d, \n%s\n",fd2, i, s2);
		s2 = get_next_line(fd2);
		printf("FD: %d\nLine: %d, \n%s\n",fd3, i, s3);
		s3 = get_next_line(fd3);
		printf("FD: %d\nLine: %d, \n%s\n",fd4, i, s4);
		s4 = get_next_line(fd4);
		printf("FD: %d\nLine: %d, \n%s\n",fd5, i, s5);;
		s5 = get_next_line(fd5);
		i++;
	}
	return (0);
}
