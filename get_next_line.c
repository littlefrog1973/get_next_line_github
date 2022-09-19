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

static char	*init_line(int fd, char *line)
{
	if (fd < 0)
	{
		line = NULL;
		return (NULL);
	}
	if (!line)
	{
		line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line)
			return (NULL);
		ft_bzero(line, BUFFER_SIZE + 1);
	}
	return (line);
}

static ssize_t	check_new_line(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		i++;
	}
	if (buffer[i] == '\n')
		return (i);
	else
		return (-1);
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

static char	*join_line_buffer(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
//	free(buffer);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(line);
	line = (char *) malloc(ft_strlen(temp) + 1);
	if (!line)
	{
		free(temp);
		return (NULL);
	}
	ft_strlcpy(line, temp, ft_strlen(temp) + 1);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	ssize_t		j;

	if (fd < 0 || !line)
		line = init_line(fd, line);
	if (!line)
		return (NULL);
	while (1)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		buffer = (char *) malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(line);
			return (NULL);
		}
		ft_bzero(buffer, BUFFER_SIZE + 1);
		j = read(fd, buffer, BUFFER_SIZE);
		if (j > 0)
		{
			line = join_line_buffer(line, buffer);
			if (!line)
			{
				free(buffer);
				return (NULL);
			}
			if (check_new_line(line) >= 0)
				break ;
			free(buffer);
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
