/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:13:48 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/14 13:53:27 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*left[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left[fd] = read_function (fd, left[fd]);
	if (!left[fd])
		return (NULL);
	line = ft_getline(left[fd]);
	left[fd] = ft_getleft(left[fd]);
	return (line);
}

char	*read_function(int fd, char *str)
{
	char	*tmp;
	int		bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && (bytes != 0))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_getline(char *left)
{
	int		i;
	char	*line;

	i = 0;
	if (!left[i])
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		line[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		line[i] = left[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getleft(char *left)
{
	char	*rest;
	int		i;
	int		j;

	i = ft_strlen(left, '\n');
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(left, '\0') - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (left[i])
		rest[j++] = left[i++];
	rest[j] = '\0';
	free(left);
	return (rest);
}
/*
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
*/