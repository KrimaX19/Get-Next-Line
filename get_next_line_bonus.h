/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:13:54 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/14 13:08:01 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*Librarias*/
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*Funcoes*/
char	*get_next_line(int fd);
size_t	ft_strlen(char *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*read_function(int fd, char *str);
char	*ft_getline(char *left);
char	*ft_getleft(char *left);
void	ft_strlcpy(char *dst, char *src);

#endif
