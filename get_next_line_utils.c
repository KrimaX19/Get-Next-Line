/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:17:01 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/21 22:55:10 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s, char c)
{
	char	*i;

	i = s;
	if (!s)
		return (0);
	while (*i && *i != c)
		i++;
	return (i - s);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*r;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(str1, '\0');
	len2 = ft_strlen(str2, '\0');
	r = (char *)malloc(len1 + len2 + 1);
	if (!r)
		return (NULL);
	i = -1;
	while (++i < len1)
		r[i] = str1[i];
	j = -1;
	while (++j < len2)
		r[i + j] = str2[j];
	r[i + j] = '\0';
	free(str1);
	return (r);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (0);
}
