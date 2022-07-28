/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:38:57 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/26 16:50:01 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s == '\n' || *s == '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1)
		{
			if (i < j)
			{
				dst[i] = src[i];
			}
			else if (i == j && dst[i] != '\0')
			{
				dst[i] = '\0';
				return (j);
			}
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t	i;

	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (dest <= source && src)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

char	*chop(char *line, size_t *i)
{
	size_t	j;
	char	*chop_line;
	j = 0;
	while (line[j] != '\n' && line[j] )
		j++;
	chop_line = (char *) malloc((j + 2) *sizeof(char));
	if (!chop_line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(chop_line, line, j);
	*i = BUFFER_SIZE - j;
	ft_memmove(line, (line + j), *i);
	return (line);
}
