/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 05:07:41 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/08/27 12:03:42 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;
	char	*line;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
//	printf("main: fd = %i\n", fd);
	line = "";
	i = 0;
	while (line != NULL)
	{
		++i;
		line = get_next_line(fd);
		printf("In main (%d): %s", i, line);
//		printf("In main : call %d times\n", i);
	}
	fd = close(fd);
	return (0);
}
