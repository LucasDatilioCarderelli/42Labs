/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:01:48 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/25 20:35:34 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>
#include <string.h>

int	main(int argc, char **argv)
{
	CURL		*curl;
	CURLcode	res;
	char		s_url[100];

	curl = curl_easy_init();
	if (!curl)
	{
		fprintf(stderr, "[-] Failed Initializing Curl\n");
		exit(-1);
	}
	strcpy(s_url, "https://www.mercadobitcoin.net/api/");
	strcat(s_url, argv[1]);
	strcat(s_url, "/ticker");
	curl_easy_setopt(curl, CURLOPT_URL, s_url);
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
	return (0);
}
