/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:55:35 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/08/24 18:08:15 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	static size_t	i;
	ssize_t	j;

	if (!line)
	{
		line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line)
			return (NULL);
		ft_bzero(line, BUFFER_SIZE + 1);
	}
	j = read(fd, (line + i), BUFFER_SIZE - i);
	printf("     In GNL : nbyte = %lu\n", j);
//	printf("read OK: &line = %p, line point to %p, j = %lu, static i = %lu\n", &line, line, j, i);
	if (j <= 0)
	{
		free(line);
		return (NULL);
	}
	else
	{
		printf("     In GNL: ft_strlen(line) = %lu\n", ft_strlen(line));
		return (chop(line, &i));
	}
}
