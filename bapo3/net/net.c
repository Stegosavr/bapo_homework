#include <stdlib.h>
#include <stdio.h>

#include "curl/curl.h"
#include "net.h"

map *output_json;
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);

STATUS http_get_request(char *url, map *out_json)
{
	curl_global_init(CURL_GLOBAL_ALL);

	CURL *handle = curl_easy_init();
	curl_easy_setopt(handle, CURLOPT_URL, url);
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_data);

    output_json = out_json;
	CURLcode success = curl_easy_perform(handle);
	if (success != CURLE_OK)
	{
        return ERROR;
	}
    return OK;
}

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
    map map = {};
    if (parse_json(output_json, buffer) == 0)
		return nmemb;
    return 0;
}
