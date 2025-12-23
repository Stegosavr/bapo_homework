#include "json/json.h"

typedef enum STATUS
{
    OK,
    ERROR
} STATUS;

STATUS http_get_request(char *url, map *out_json);
