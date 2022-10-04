/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 05:07:41 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/09/14 23:33:27 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;
	char	*line;
	double time_spent = 0.0;

	clock_t	begin = clock();
	(void) argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	i = 0;
	while (line != NULL)
	{
		++i;
/*		line = get_next_line(1000);
		printf("In main (%d): %s", i, line);
		line = get_next_line(-1);
		printf("In main (%d): %s", i, line);
		close(fd);
*/
		line = get_next_line(fd);
		printf("In main (%d): %s", i, line);
		free(line);
	}
	fd = close(fd);
	clock_t end = clock();
	time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
	printf("\ntime spent = %f\n", time_spent);
	return (0);
}
