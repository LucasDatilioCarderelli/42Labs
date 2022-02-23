/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:48:59 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/23 16:26:45 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mongoose/mongoose.h"

void log_message(const char *filename, const char *message, int status)
{
    time_t curtime;
    FILE *fp = fopen(filename, "a");

    time(&curtime);
    if (fp != NULL)
    {
        fprintf(fp, "Status: %d\n", status);
        fprintf(fp, "Ultima requisição: %s", ctime(&curtime));
        fprintf(fp, "%s", message);
        fclose(fp);
    }
}

static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
    int aux;
    if (ev == MG_EV_HTTP_MSG)
    {
        struct mg_http_message *hm = (struct mg_http_message *)ev_data;
        if (mg_http_match_uri(hm, "/4"))
        {
            aux = rand() % 4;
            mg_http_reply(c, 200, "dado de 4 lados\r\n", "{\"valor\":%d}", aux);
			log_message("LOG.log", hm->message.ptr, 200);
        }
        else if(mg_http_match_uri(hm, "/6"))
        {
            aux = rand() % 6;
            mg_http_reply(c, 200, "dado de 6 lados\r\n", "{\"valor\":%d}", aux);
			log_message("LOG.log", hm->message.ptr, 200);
        }
         else if(mg_http_match_uri(hm, "/10"))
        {
            aux = rand() % 10;
            mg_http_reply(c, 200, "dado de 10 lados\r\n", "{\"valor\":%d}", aux);
			log_message("LOG.log", hm->message.ptr, 200);
        }
         else if(mg_http_match_uri(hm, "/20"))
        {
            aux = rand() % 20;
            mg_http_reply(c, 200, "dado de 20 lados\r\n", "{\"valor\":%d}", aux);
			log_message("LOG.log", hm->message.ptr, 200);
        }
        else
		{
            mg_http_reply(c, 404, NULL, "Dado não encontrado\n");
			log_message("LOG.log", hm->message.ptr, 404);
		}
    }
}

int main(int argc, char *argv[]) {
  struct mg_mgr mgr;
  mg_log_set("4");
  mg_mgr_init(&mgr);                                        // Init manager
  mg_http_listen(&mgr, "http://localhost:8000", fn, &mgr);  // Setup listener
  for (;;) mg_mgr_poll(&mgr, 1000);                         // Event loop
  mg_mgr_free(&mgr);                                        // Cleanup
  return 0;
}