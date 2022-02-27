/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:50:36 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/26 22:35:16 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*ft_curl(char *coin)
{
	CURL			*curl;
	CURLcode		res;
	t_MemoryStruct	chunk;
	char			s_url[100];

	chunk.memory = malloc(1);
	chunk.size = 0;
	curl = curl_easy_init();
	if (!curl)
		exit(-1);
	strcpy(s_url, "https://www.mercadobitcoin.net/api/");
	strcat(s_url, coin);
	strcat(s_url, "/ticker");
	curl_easy_setopt(curl, CURLOPT_URL, s_url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_memory_call_back);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
	res = curl_easy_perform(curl);
	if (res != CURLE_OK)
	{
		fprintf(stderr, "Could Not Fetch Webpage\nError : %s\n",
			curl_easy_strerror(res));
		exit(-2);
	}
	curl_easy_cleanup(curl);
	return (chunk.memory);
}

static size_t	write_memory_call_back(
	void *contents, size_t size, size_t nmemb, void *userp)
{
	size_t			realsize;
	t_MemoryStruct	*mem;
	char			*ptr;

	realsize = size * nmemb;
	mem = (t_MemoryStruct *)userp;
	ptr = realloc(mem->memory, mem->size + realsize + 1);
	if (!ptr)
		return (0);
	mem->memory = ptr;
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;
	return (realsize);
}
