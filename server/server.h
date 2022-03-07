/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:48:43 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/07 09:02:22 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libs/mongoose/mongoose.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <curl/curl.h>
# include <sqlite3.h>
# include <json-c/json.h>

typedef struct s_MemoryStruct
{
	char	*memory;
	size_t	size;
}	t_MemoryStruct;

sqlite3	*g_db;

# define LOG_FILE "./logs/LOG.log"

/**
 * @brief	Redirect the route requesting from another API and save the LOG.
 *
 * @param	c		A connection that received an event.
 * @param	hm		Parsed HTTP response
 * @param	route	Route name that matches the URI.
 */
static void
change_route(struct mg_connection *c, struct mg_http_message *hm, char *route);

/**
 * @brief	An event handler function that request another API depends
 * 			from the route and write in the log a message.
 *
 * @param	c		A connection that received an event.
 * @param	ev		An event number, defined in mongoose.h. For example,
 * 					when data arrives on an inbound connection
 * @param	ev_data	Points to the event-specific data
 * @param	fn_data	A user-defined pointer for the connection, which is a
 * 			placeholder for application-specific data
 */
static void
fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data);

/**
 * @brief	Do a request utilizing libcurl to an external API and
 * 			Store its response to utilize to reply further.
 *
 * @param	coin	Coin name route to request in an external API.
 * @return	char*	Chunk of Memory that store the JSON response.
 */
char
*ft_curl(char *coin);

/**
 * @brief	Download data into a chunk of memory instead of storing it in a file
 *
 * @param	contents
 * @param	size		Size of array.
 * @param	nmemb		Size of memory of n bytes.
 * @param	userp
 * @return	size_t		Real size of memory chunk.
 */
static size_t
write_memory_call_back(void *contents, size_t size, size_t nmemb, void *userp);

/**
 * @brief	Open a Log.log file and receive params to write in it.
 *
 * @param	filename	The path of Log file to write a message.
 * @param	message		HTTP message from the event data.
 * @param	status		Status code from request.
 */
void
log_message(const char *filename, const char *message, int status);

void
*open_db(sqlite3 *db);

void
parse_json(char *body);

#endif
