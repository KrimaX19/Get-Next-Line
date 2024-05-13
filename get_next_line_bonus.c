/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:13:48 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/13 13:45:59 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char     *bag;
	char			*line;
	char			*tmp;
	int				bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = read(fd, bag,BUFFER_SIZE);
	if (bytes == -1)
	{
		free (tmp);
		return (NULL);
	}
	tmp[bytes] = '\0';
	
	
}
