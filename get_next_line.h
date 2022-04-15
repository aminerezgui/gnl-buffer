/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezgui <arezgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:37:01 by arezgui           #+#    #+#             */
/*   Updated: 2022/04/21 00:43:07 by arezgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen( char *str);
char	*ft_strchr(char *string, int searched_char);
char	*ft_strjoin(char *s1, char *s2);

void	*ft_calloc(size_t element_count, size_t element_size);
char	*ft_substr(char *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

#endif