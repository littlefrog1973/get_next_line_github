/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:55:35 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/25 05:25:35 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*read_line;
	size_t	i;
	static ssize_t	j;

	read_line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_line)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
		*(read_line + i++) = 0;
	j = read(fd, read_line, BUFFER_SIZE);
	if (j < 0)
		return (NULL);
	return (read_line);
}
