/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: littlefrog <littlefrog@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:38:57 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/30 10:58:21 by littlefrog       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*chr;
	size_t			i;

	chr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		chr[i] = 0;
		i++;
	}
}

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

//	j = ft_strlen(src);
	j = 0;
//	printf("              In ft_strlcpy: src = %s\n", src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1)
		{
//			if (i < j)
//			{
				dst[i] = src[i];
//			}
//			else if (i == j && dst[i] != '\0')
//			{
//				dst[i] = '\0';
//				return (j);
//			}
			i++;
		}
		dst[i] = '\0';
	}
//	printf("              In ft_strlcpy: dst = %s\n", dst);
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
//	printf("     In chop: j = %lu\n", j);
	chop_line = (char *) malloc((j + 2) * sizeof(char));
	if (!chop_line)
	{
		free(line);
		return (NULL);
	}
//	printf("     In chop: malloc for chop_line OK: chop_line = %p\n", chop_line);
	ft_strlcpy(chop_line, line, j + 2);
//	printf("     In chop: after ft_strlcpy: chop_line = %s\n", chop_line);
	*i = BUFFER_SIZE - (j + 1);
	ft_memmove(line, (line + j + 1), *i);
	ft_bzero((line + j + 1), *i);
	return (chop_line);
}
