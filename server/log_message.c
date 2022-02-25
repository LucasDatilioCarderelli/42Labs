/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:51:39 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/25 11:08:39 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	log_message(const char *filename, const char *message, int status)
{
	time_t	curtime;
	FILE	*fp;

	fp = fopen(filename, "a");
	if (fp < 0)
	{
		printf("Error: file not Opened");
		exit(-3);
	}
	time(&curtime);
	if (fp != NULL)
	{
		fprintf(fp, "Status: %d\n", status);
		fprintf(fp, "Last Request: %s", ctime(&curtime));
		fprintf(fp, "%s", message);
		fclose(fp);
	}
}
