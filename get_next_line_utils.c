/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezgui <arezgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:43:38 by arezgui           #+#    #+#             */
/*   Updated: 2022/04/21 00:44:26 by arezgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen( char *str)
{
	size_t		index;

	index = 0;
	while (str && str[index] != '\0')
	{
		index = index + 1;
	}
	return (index);
}

char	*ft_strchr( char *str, int searched_char)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == (unsigned char)searched_char)
		{
			return ((char *)str + i);
		}
		i = i + 1;
	}
	if (searched_char == '\0')
		return ((char *)str + i);
	return (((char *)0));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	k;
	size_t	str_len;

	i = 0;
	k = 0;
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(str_len + 1);
	if (!str)
		return ((char *)0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (i < str_len)
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[str_len] = '\0';
	free(s1);
	return (str);
}

void	*ft_calloc(size_t element_count, size_t element_size)
{
	unsigned char	*ptr;
	size_t			bytes_to_allocate;
	size_t			i;

	bytes_to_allocate = element_count * element_size;
	ptr = (unsigned char *) malloc(bytes_to_allocate);
	i = 0;
	if (!ptr)
		return ((void *)0);
	while (i < bytes_to_allocate)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		s_len;
	size_t		i;
	size_t		k;
	size_t		max_substr_len;

	s_len = ft_strlen(s);
	i = start;
	k = 0;
	if (start > s_len - 1 || len == 0)
		return (NULL);
	max_substr_len = s_len - start;
	if (len > max_substr_len)
		sub_str = ft_calloc(max_substr_len + 1, 1);
	else
		sub_str = ft_calloc(len + 1, 1);
	if (!sub_str)
		return ((char *) 0);
	while (i < start + len && i < s_len)
	{
		sub_str[k] = s[i];
		i++;
		k++;
	}
	return (sub_str);
}
