/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:45 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/27 11:02:07 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

static void	print_help(void);

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
		{
			print_help();
			exit(0);
		}
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
}
