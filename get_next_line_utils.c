/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:38:57 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/10/04 23:27:37 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "get_next_line.h"

ssize_t	check_new_line(char *buffer)
/* Check whether new_line in buffer or not, if yes: return its position */
{
	ssize_t	i;

	i = 0;
	while (*(buffer + i) != '\n' && *(buffer + i))
		i++;
	if (*(buffer + i) == '\n')
		return (i);
	else
		return (-1);
}

size_t	ft_strlen(const char *s)
/* Measure string length */
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
/* Copy string from src to dst with dstsize */
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
/* malloc new memory to join s1 and s2 */
{
	char	*str_join;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_join = (char *) malloc(s1_len + s2_len + 1);
	if (!str_join)
		return (NULL);
	i = 0;
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			*(str_join + i) = *(s1 + i);
		if (i >= s1_len)
			*(str_join + i) = *(s2 + i - s1_len);
		i++;
	}
	*(str_join + s1_len + s2_len) = '\0';
	return (str_join);
}
