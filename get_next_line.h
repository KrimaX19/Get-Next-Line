/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:17:47 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/09 10:24:38 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_size
#  define BUFFER_SIZE 42
# endif

/*Librarias*/
# include <stdlib.h>

/*Funcoes*/
char	*get_next_line(int fd);

#endif
