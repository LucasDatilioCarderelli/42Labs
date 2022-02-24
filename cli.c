/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:45 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/23 20:37:31 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		request_4;
	int		request_6;
	int		request_10;
	int		request_20;
	int		fd;
	char	*tmp_line;

	request_4 = 0;
	request_6 = 0;
	request_10 = 0;
	request_20 = 0;
	fd = open("./LOG.log", O_RDONLY);
	if (fd == -1)
		printf("Error.");
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		if (strstr(tmp_line, "GET /4"))
			request_4++;
		if (strstr(tmp_line, "GET /6"))
			request_6++;
		if (strstr(tmp_line, "GET /10"))
			request_10++;
		if (strstr(tmp_line, "GET /20"))
			request_20++;
	}
	printf("|----------------------------------------------|\n");
	printf("|Total Requests|  HTTP Method  |      Path     |\n");
	printf("|--------------|---------------|---------------|\n");
	printf("|      %d       |      GET      |      /4       |\n", request_4);
	printf("|      %d       |      GET      |      /6       |\n", request_6);
	printf("|      %d       |      GET      |      /10      |\n", request_10);
	printf("|      %d       |      GET      |      /20      |\n", request_20);
	printf("|--------------|---------------|---------------|\n");
}
