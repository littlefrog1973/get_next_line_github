/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:55:35 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/08/27 11:54:47 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"


static ssize_t	read_buffer(int fd, char *buffer)
{
	ssize_t	j;

	j = read(fd, buffer, BUFFER_SIZE);
	return (j);
}

static size_t	check_new_line(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n')
	{
		if (buffer[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}

static char	*chop(char *line)
{
	size_t	j;
	char	*chop_line;
	size_t	i;

	j = 0;
	while (line[j] != '\n' && line[j])
		j++;
	chop_line = (char *) malloc((j + 2) * sizeof(char));
	if (!chop_line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(chop_line, line, j + 2);
	i = 0;
	while (i < ft_strlen(line) - (j + 1))
	{
		line[i] = line[j + 1 + i];
		i++;
	}
//	ft_memmove(line, (line + j + 1), i);
	ft_bzero((line + i), (j + 1));
	return (chop_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	j;

	if (!line)
	{
		line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line)
			return (NULL);
		ft_bzero(line, BUFFER_SIZE + 1);
	}
	while (1)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		j = read_buffer(fd, buffer);
		if (!check_new_line(buffer) && (j == BUFFER_SIZE))	//In case of no new line in read buffer (full read)
		{
			temp = ft_strjoin(line, buffer);
			if (!temp)
			{
				free(line);
				return (NULL);
			}
			free(line);
			line = (char *) malloc(ft_strlen(temp));
			if (!line)
			{
				free(temp);
				return (NULL);
			}
			ft_strlcpy(line, temp, ft_strlen(temp) + 1);
			continue;
		}
		else if (j == 0 && !ft_strlen(line))
		{
			free(line);
			return(NULL);
		}
		else if (j < 0)
		{
			free(line);
			return(NULL);
		}
		else
		{
			if (ft_strlen(line) == 0)		// In case of no data in line
			{
				ft_strlcpy(line, buffer, BUFFER_SIZE + 1);
				break;
			}
			temp = ft_strjoin(line, buffer);
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
			break;
		}
	}
	return (chop(line));
}
