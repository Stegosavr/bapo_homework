#include <stdio.h>
#include <stdlib.h>

#include "net/net.h"


int main(int argc, char *argv[])
{
	char *url = getenv("TYPE");
	if (!url || url[0] == '\0')
	{
		printf("url in $TYPE not provided!\n");
		return 1;
	}

    map json = {};
    if (http_get_request(url, &json) == ERROR)
    {
        printf("Error: Request failed\n");
        return 1;
    }

    map_node **field = map_find(&json, "ip");
    if (*field == NULL)
        field = map_find(&json, "query");

	if (*field != NULL)
	{
		printf("{\"myIP\": \"%s\"}\n", (char *)(*field)->value);
	}
    else
    {
        printf("Error: IP field not present in response\n");
        return 1;
    }

	return 0;
}
