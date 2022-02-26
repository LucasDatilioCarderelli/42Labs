/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:48:43 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/26 18:23:38 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../mongoose/mongoose.h"
# include <stdio.h>
# include <stdlib.h>
# include <curl/curl.h>
# include <unistd.h>
# include <string.h>

typedef struct s_MemoryStruct
{
	char	*memory;
	size_t	size;
}	t_MemoryStruct;

# define LOCAL_HOST "http://localhost:8000"
# define API_URL "https://www.mercadobitcoin.net/api/"
# define END_URL "/ticker"
# define LOG_FILE "./logs/LOG.log"

char	*ft_curl(char *coin);
void	log_message(const char *filename, const char *message, int status);

#endif
