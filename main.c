/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 05:07:41 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/09/12 14:12:36 by sdeeyien         ###   ########.fr       */
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

//	(void) argv[1];
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
		free(line);
	}
	fd = close(fd);
//	free(line);
	return (0);
}
