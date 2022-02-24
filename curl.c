/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:01:48 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/23 16:56:06 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

int	main(void)
{
	CURL		*curl;
	CURLcode	res;

	curl = curl_easy_init();
	if (!curl)
	{
		fprintf(stderr, "[-] Failed Initializing Curl\n");
		exit(-1);
	}
	curl_easy_setopt(curl, CURLOPT_URL, "localhost:8000/6");
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
