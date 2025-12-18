#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//apt update
//sudo apt install curl=7.81.0-1ubuntu1.21
// NOTE: redundant
//sudo apt install libcurl4-gnutls-dev
#include <curl/curl.h>

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
	char *field = strtok((char *)buffer, "\"");
	char *ip = NULL;
	while (field != NULL)
	{
		//printf("%s\n", field);
		field = strtok(NULL, "\"");
		if (strcmp("ip", field) == 0 || strcmp("query", field) == 0)
		{
			strtok(NULL, "\"");
			ip = strtok(NULL, "\"");
			break;
		}
	}

	if (ip)
	{
		printf("{\"myIP\": \"%s\"}\n", ip);
		return nmemb;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char *url = getenv("TYPE");
	if (!url || url[0] == '\0')
	{
		printf("url in $TYPE not provided!\n");
		return 1;
	}

	curl_global_init(CURL_GLOBAL_ALL);

	CURL *handle = curl_easy_init();
	curl_easy_setopt(handle, CURLOPT_URL, url);
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_data);

	CURLcode success = curl_easy_perform(handle);
	if (success != CURLE_OK)
	{
		printf("Error!\n");
	}

	return 0;
}
