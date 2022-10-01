/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:55:35 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/09/15 00:47:34 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char	*init_line(char *line)
{
	if (!line)
	{
		line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	return (line);
}

static char	*chop(char *line)
{
	size_t	j;
	char	*chop_line;
	size_t	i;
	size_t	s_len;

	j = 0;
	while (line[j] != '\n' && line[j])
		j++;
	chop_line = (char *) malloc((j + 2));
	if (!chop_line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(chop_line, line, j + 2);
	i = 0;
	s_len = ft_strlen(line);
	while (i + (j + 1) < s_len)
	{
		line[i] = line[j + 1 + i];
		i++;
	}
	line[i] = '\0';
	return (chop_line);
}

static char	*join_line_buffer(char *line, char *buffer, ssize_t j)
{
	char	*temp;

	buffer[j] = '\0';
	temp = line;
	line = ft_strjoin(line, buffer);
	if (!line)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (line);
}
/*
static char	*read_to_line(char *r_line, int fd)
{
	char	*r_buffer;
	ssize_t	j;

	r_buffer = (char *) malloc(BUFFER_SIZE + 1);
	r_buffer[BUFFER_SIZE] = '\0';
	if (!r_buffer)
	{
		free(r_line);
		return (NULL);
	}
	j = read(fd, r_buffer, BUFFER_SIZE);
	while (check_new_line(r_buffer) < 0)

}
*/
char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	ssize_t		j;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	line = init_line(line);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	while (1)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		if (j > 0)
		{
			buffer[j] = '\0';
			line = join_line_buffer(line, buffer, j);
			if (!line)
			{
				free(buffer);
				return (NULL);
			}
			if (check_new_line(line) >= 0)
				break ;
			continue ;
		}
		else if (j < 0 || !ft_strlen(line))
		{
			free(line);
			free(buffer);
			line = NULL;
			return (NULL);
		}
		else
			break ;
	}
	free(buffer);
	return (chop(line));
}
