/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:45 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/25 16:32:28 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

static void	print_cli(t_data *method)
{
	printf("╔══════════════╦═══════════════╦═══════════════╗\n");
	printf("║Total Requests║  HTTP Method  ║      Path     ║\n");
	printf("╠══════════════╬═══════════════╬═══════════════╣\n");
	if (method->get.root)
		printf("║      %02d      ║      GET      ║      /        ║\n",
			method->get.root);
	if (method->get.btc)
		printf("║      %02d      ║      GET      ║      /BTC     ║\n",
			method->get.btc);
	if (method->get.eth)
		printf("║      %02d      ║      GET      ║      /ETH     ║\n",
			method->get.eth);
	printf("╚══════════════╩═══════════════╩═══════════════╝\n");
}

int	main(void)
{
	t_data	method;
	int		fd;
	char	*tmp_line;

	method.get.root = 0;
	method.get.btc = 0;
	method.get.eth = 0;
	fd = open(LOG_FILE, O_RDONLY);
	if (fd == -1)
		printf("Error.");
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		if (strstr(tmp_line, "GET / "))
			method.get.root++;
		if (strstr(tmp_line, "GET /BTC"))
			method.get.btc++;
		if (strstr(tmp_line, "GET /ETH"))
			method.get.eth++;
	}
	print_cli(&method);
}
