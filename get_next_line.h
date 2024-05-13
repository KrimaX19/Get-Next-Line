/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:17:47 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/13 13:08:14 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*Librarias*/
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*Funcoes*/
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*read_function(int fd, char *str);
char	*ft_getline(char *left);
char	*ft_getleft(char *left);

#endif
