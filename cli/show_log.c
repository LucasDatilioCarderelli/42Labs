/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:00:22 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/26 17:06:51 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

static void	init_variables(t_data *method);
static void	count_requests(t_data *method, int fd);
static void	print_cli(t_data *method);

void	show_log(void)
{
	t_data	method;
	int		fd;

	init_variables(&method);
	fd = open(LOG_FILE, O_RDONLY);
	if (fd == -1)
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}
	count_requests(&method, fd);
	print_cli(&method);
	exit(EXIT_SUCCESS);
}

static void	init_variables(t_data *method)
{
	method->get.root = 0;
	method->get.btc = 0;
	method->get.eth = 0;
	method->get.bat = 0;
	method->get.gods = 0;
	method->error = 0;
}

static void	count_requests(t_data *method, int fd)
{
	char	*tmp_line;

	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		if (strstr(tmp_line, "GET / "))
			method->get.root++;
		if (strstr(tmp_line, "GET /BTC"))
			method->get.btc++;
		if (strstr(tmp_line, "GET /ETH"))
			method->get.eth++;
		if (strstr(tmp_line, "GET /BAT"))
			method->get.bat++;
		if (strstr(tmp_line, "GET /GODS"))
			method->get.gods++;
		if (strstr(tmp_line, "Status: 404"))
			method->error++;
	}
}

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
	if (method->get.bat)
		printf("║      %02d      ║      GET      ║      /BAT     ║\n",
			method->get.bat);
	if (method->get.gods)
		printf("║      %02d      ║      GET      ║      /GODS    ║\n",
			method->get.gods);
	if (method->error)
		printf("║      %02d      ║     ERROR     ║       404     ║\n",
			method->error);
	printf("╚══════════════╩═══════════════╩═══════════════╝\n");
}

