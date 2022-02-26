/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:45 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/26 17:06:41 by ldatilio         ###   ########.fr       */
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
		{
			printf("Options avaliable:\n version\n endpoints\n show");
			exit(0);
		}
	}
}
