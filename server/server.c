/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:48:59 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/25 10:21:55 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
	struct mg_http_message	*hm;
	char					*body;

	hm = (struct mg_http_message *)ev_data;
	if (ev == MG_EV_HTTP_MSG)
	{
		if (mg_http_match_uri(hm, "/BTC"))
		{
			body = ft_curl("BTC");
			mg_http_reply(c, 200, "BTC\r\n", "%s\n", body);
			log_message(LOG_FILE, hm->message.ptr, 200);
		}
		else if (mg_http_match_uri(hm, "/ETH"))
		{
			body = ft_curl("ETH");
			mg_http_reply(c, 200, "ETH\r\n", "%s\n", body);
			log_message(LOG_FILE, hm->message.ptr, 200);
		}
		else
		{
			mg_http_reply(c, 404, NULL, "Coin not found, try BTC or ETH\n");
			log_message(LOG_FILE, hm->message.ptr, 404);
		}
	}
}

int	main(void)
{
	struct mg_mgr	mgr;

	mg_log_set("4");
	mg_mgr_init(&mgr);
	mg_http_listen(&mgr, "http://localhost:8000", fn, &mgr);
	while (1)
		mg_mgr_poll(&mgr, 2000);
	mg_mgr_free(&mgr);
	return (0);
}
