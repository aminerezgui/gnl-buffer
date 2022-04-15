/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezgui <arezgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:45:00 by arezgui           #+#    #+#             */
/*   Updated: 2022/04/21 13:36:27 by arezgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	len_current_line(char *stock)
{
	size_t	i;

	i = 0;
	while (stock && (stock[i] != '\n' && stock[i] != '\0'))
	{
		i++;
	}
	if (stock[i] == '\n')
		i++;
	return (i);
}

static char	*expend_stock(int fd, char *stock)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb_bytes_read;
	char	*stock_to_free;

	nb_bytes_read = 1;
	while (!ft_strchr(stock, '\n') && nb_bytes_read > 0)
	{
		stock_to_free = stock;
		nb_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes_read == -1)
		{
			free(stock_to_free);
			return (NULL);
		}
		buffer[nb_bytes_read] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (!stock)
		{
			free(stock_to_free);
			return (NULL);
		}
	}
	return (stock);
}

static char	*remove_line_from_stock(char *stock, size_t len_stock,
				char *line, size_t len_line)
{
	char	*stock_to_free;
	char	*new_stock;

	stock_to_free = stock;
	new_stock = ft_substr(stock, len_line, len_stock - len_line);
	if ((len_line <= len_stock - 1 && len_stock - len_line != 0) && !new_stock)
	{
		free(stock_to_free);
		free(line);
		return (NULL);
	}
	return (new_stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*stock_to_free;
	char		*line;
	size_t		len_line;
	size_t		len_stock;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	stock = expend_stock(fd, stock);
	if (!stock)
		return (NULL);
	stock_to_free = stock;
	len_line = len_current_line(stock);
	line = ft_substr(stock, 0, len_line);
	len_stock = ft_strlen(stock);
	if ((0 <= (long)len_stock - 1 && len_line != 0) && !line)
	{
		free(stock_to_free);
		return (NULL);
	}
	stock = remove_line_from_stock(stock, len_stock, line, len_line);
	if ((len_line <= len_stock - 1 && len_stock - len_line != 0) && !stock)
		return (NULL);
	free(stock_to_free);
	return (line);
}
