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


char	*s_extend(char *line)
{
	char	*new_line;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(line);
	new_line = (char *) malloc(s_len + BUFFER_SIZE + 1);
	if (new_line == NULL)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < s_len + BUFFER_SIZE + 1)
		new_line[i++] = '\0';
	ft_strlcpy(new_line, line, s_len + 1);
	free(line);
//	printf("In s_extend: after malloc\n");
	return (new_line);
}
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
		line[0] = '\0';
	}
	return (line);
}

static ssize_t	check_new_line(char *buffer)
{
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
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
	while (i < s_len)
		line[i++] = '\0';
	return (chop_line);
}
/*
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
*/
char	*get_next_line(int fd)
{
	static char	*line;
//	char		*buffer;
	ssize_t		j;

	if (fd < 0 || (line == NULL))
		line = init_line(fd, line);
	if (!line)
		return (NULL);
	while (1)
	{
/*		buffer = (char *) malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(line);
			return (NULL);
		}
*/
//		j = read(fd, buffer, BUFFER_SIZE);
		j = read(fd, (line + ft_strlen(line)), BUFFER_SIZE);
		if (j > 0)
		{
/*			line = join_line_buffer(line, buffer, j);
			if (!line)
			{
				free(buffer);
				return (NULL);
			}
*/
			if (check_new_line(line) >= 0)
				break ;
//			free(buffer);
			line = s_extend(line);
			if (line == NULL)
				return (NULL);
			continue ;
		}
		else if (j < 0 || !ft_strlen(line))
		{

			free(line);
//			free(buffer);
			line = NULL;
			return (NULL);
		}
		else
			break ;
	}

//	free(buffer);
	return (chop(line));
}
