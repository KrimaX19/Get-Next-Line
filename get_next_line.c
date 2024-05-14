/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:17:01 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/14 13:53:32 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left = read_function (fd, left);
	if (!left)
		return (NULL);
	line = ft_getline(left);
	left = ft_getleft(left);
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
	char	*s;
	int		i;
	int		fd;

	i = 0;
	fd = open ("./text/Texto1.txt", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("Line: %d, \n%s", i, s);
		s = get_next_line(fd);
		i++;
	}
	return (0);
}
*/