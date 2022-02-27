/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:32:01 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/27 12:19:32 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define MG_VERSION "7.6"

# define LOG_FILE "./logs/LOG.log"

typedef struct s_get
{
	int	root;
	int	btc;
	int	eth;
	int	bat;
	int	gods;
}	t_get;

typedef struct s_data
{
	t_get	get;
	int		error;
}	t_data;

/**
 * @brief In case of without or wrong argument, print a formated helper.
 *
 */
static void	print_help(void);

/**
 * @brief	Read the Log.log file and print the summary of API requests.
 *
 */
void		show_log(void);

/**
 * @brief	Initialize the counts with 0.
 *
 * @param	method	Contains the count of requests.
 */
static void	init_variables(t_data *method);

/**
 * @brief	Counts depend on a request in each event.
 *
 * @param	method	Contains the count of requests.
 * @param	fd		File Descriptor.
 */
static void	count_requests(t_data *method, int fd);

/**
 * @brief	Verify if exists and prints.
 *
 * @param	method	Contains the count of requests.
 */
static void	print_summary(t_data *method);

#endif
