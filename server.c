/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:48:59 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/24 17:04:19 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mongoose/mongoose.h"

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>
#include <string.h>

typedef struct s_MemoryStruct
{
	char	*memory;
	size_t	size;
}	t_MemoryStruct;

# define LOG_FILE "LOG.log"

static size_t	write_memory_call_back(void *contents, size_t size, size_t nmemb, void *userp)
{
	size_t			realsize;
	t_MemoryStruct	*mem;
	char			*ptr;

	realsize = size * nmemb;
	mem = (t_MemoryStruct *)userp;
	ptr = realloc(mem->memory, mem->size + realsize + 1);
	if (!ptr)
	{
		printf("not enough memory (realloc returned NULL)\n");
		return (0);
	}
	mem->memory = ptr;
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;
	return (realsize);
}

char	*ft_curl(char *coin)
{
	CURL			*curl;
	CURLcode		res;
	t_MemoryStruct	chunk;

	chunk.memory = malloc(1);
	chunk.size = 0;
	curl = curl_easy_init();
	if (!curl)
	{
		fprintf(stderr, "[-] Failed Initializing Curl\n");
		exit(-1);
	}
	char s_url[100] = "https://www.mercadobitcoin.net/api/";
	strcat(s_url, coin);
	strcat(s_url, "/ticker");
	curl_easy_setopt(curl, CURLOPT_URL, s_url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_memory_call_back);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
	res = curl_easy_perform(curl);
	if (res != CURLE_OK)
	{
		fprintf(
			stderr,
			"[-] Could Not Fetch Webpage\n[+] Error : %s\n",
			curl_easy_strerror(res));
		exit(-2);
	}
	curl_easy_cleanup(curl);
	return (chunk.memory);
}

void	log_message(const char *filename, const char *message, int status)
{
	time_t	curtime;
	FILE	*fp;

	fp = fopen(filename, "a");
	time(&curtime);
	if (fp != NULL)
	{
		fprintf(fp, "Status: %d\n", status);
		fprintf(fp, "Last Request: %s", ctime(&curtime));
		fprintf(fp, "%s", message);
		fclose(fp);
	}
}

static void	fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
	struct mg_http_message	*hm;
	int						aux;
	char 					*body;

	hm = (struct mg_http_message *)ev_data;
	if (ev == MG_EV_HTTP_MSG)
	{
		if (mg_http_match_uri(hm, "/BTC"))
		{
			ft_curl("BTC");
			mg_http_reply(c, 200, "BTC\r\n", "%s\n", body);
			log_message(LOG_FILE, hm->message.ptr, 200);
		}
		else if (mg_http_match_uri(hm, "/ETH"))
		{
			ft_curl("ETH");
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

int	main(int argc, char *argv[])
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
