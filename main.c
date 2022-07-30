/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: littlefrog <littlefrog@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 05:07:41 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/30 07:02:34 by littlefrog       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int	fd;
	char	*line;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
//	printf("main: fd = %i\n", fd);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
