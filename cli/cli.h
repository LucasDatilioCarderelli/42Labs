/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:32:01 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/26 17:07:24 by ldatilio         ###   ########.fr       */
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

void	show_log(void);

#endif
