/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:38:57 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/09/06 00:07:06 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

/*void	ft_bzero(void *s, size_t n)
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
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_dst;
	size_t	j;
	size_t	size_src;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (dstsize < size_dst)
		return (dstsize + size_src);
	j = 0;
	while (src[j] && j + 1 + size_dst < dstsize)
	{
		if ((dstsize - size_dst >= 1))
		{
			*(dst + size_dst + j) = *(src + j);
		}
		j++;
	}
	dst[size_dst + j] = '\0';
	return (size_dst + size_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	str_join = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_join)
		return (NULL);
	ft_strlcpy(str_join, (char *) s1, ft_strlen(s1) + 1);
	ft_strlcat(str_join, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str_join);
}
