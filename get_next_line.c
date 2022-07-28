/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:55:35 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/28 10:09:27 by sdeeyien         ###   ########.fr       */
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
	}
	while (i < BUFFER_SIZE + 1)
		*(line + i++) = 0;
//	printf("BUFFER_SIZE =%lu\n", i);	// check BUFFER_SIZE
	j = read(fd, (line + i), BUFFER_SIZE - i);
	if (j < 0)
	{
		free(line);
		return (NULL);
	}
	else if (j == 0)
	{
		return (chop((line), &i));
	}
	else if (j > 0 && j < BUFFER_SIZE)
	{
		i = 0;
		return (line);
	}
	return (line);
}
