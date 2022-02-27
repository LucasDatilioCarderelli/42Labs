/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:45 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/27 12:18:24 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

int	main(int argc, char **argv)
{
	while (argc--)
	{
		if (strcmp(argv[argc], "version") == 0)
		{
			printf("Mongoose Version: %s\n", MG_VERSION);
			exit(0);
		}
		else if (strcmp(argv[argc], "endpoints") == 0)
		{
			printf("BTC, ETH, BAT, GODS\n");
			exit(0);
		}
		else if (strcmp(argv[argc], "show") == 0)
			show_log();
		else
			print_help();
	}
}

static void	print_help(void)
{
	printf(" 								\n\
Options avaliable:							\n\
║ 											\n\
╠══ endpoints:	List all coins supported. 	\n\
╠══ version:	Show Mongoose Version. 		\n\
╚══ show:	Show the log's summary. 	\n\n");
	exit(0);
}
