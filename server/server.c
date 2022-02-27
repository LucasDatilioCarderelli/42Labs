/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:48:59 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/26 22:35:27 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	struct mg_mgr	mgr;

	mg_log_set("3");
	mg_mgr_init(&mgr);
	mg_http_listen(&mgr, "http://localhost:8000/", fn, &mgr);
	while (1)
		mg_mgr_poll(&mgr, 2000);
	mg_mgr_free(&mgr);
	return (0);
}

static void	fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
	struct mg_http_message	*hm;

	hm = (struct mg_http_message *)ev_data;
	if (ev == MG_EV_HTTP_MSG)
	{
		if (mg_http_match_uri(hm, "/"))
		{
			mg_http_reply(c, 200, "HomePage\r\n",
				"{\"CoinsAvailables\":[\"BTC\", \"ETH\", \"BAT\", \"GODS\"]}");
			log_message(LOG_FILE, hm->message.ptr, 200);
		}
		else if (mg_http_match_uri(hm, "/BTC"))
			change_route(c, hm, "BTC");
		else if (mg_http_match_uri(hm, "/ETH"))
			change_route(c, hm, "ETH");
		else if (mg_http_match_uri(hm, "/BAT"))
			change_route(c, hm, "BAT");
		else if (mg_http_match_uri(hm, "/GODS"))
			change_route(c, hm, "GODS");
		else
		{
			mg_http_reply(c, 404, NULL, "{\"message\":\"Page not Found\"}");
			log_message(LOG_FILE, hm->message.ptr, 404);
		}
	}
}

static void	change_route(
	struct mg_connection *c, struct mg_http_message *hm, char *route)
{
	char	*body;

	body = ft_curl(route);
	mg_http_reply(c, 200, "Coin Status\r\n", "%s\n", body);
	log_message(LOG_FILE, hm->message.ptr, 200);
}
