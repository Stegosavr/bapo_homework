#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "json.h"

typedef uint32_t bool;
#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))
#define JSON_DELIM " \n\r\t"
uint32_t string_hash(char *str);

void map_insert(map *map, char *key, void *value, VALUE_TYPE value_type)
{
    uint32_t hash = string_hash(key);
    int ind = hash % ArrayCount(map->buckets);

    map_node *node = malloc(sizeof(map_node));
    *node = (map_node){key, hash, value_type, value, NULL};

    map_node **find = map_find(map, key);
    if (*find != NULL)
    {
        free(*find);
    }
    *find = node;
}

map_node **map_find(map *map, char *key)
{
    uint32_t hash = string_hash(key);
    int ind = hash % ArrayCount(map->buckets);

    map_node **node = &map->buckets[ind];
    while (*node != NULL)
    {
        if (strcmp(key, (*node)->key) == 0)
            break;
        node = &((*node)->next);
    }
    return node;
}

uint32_t string_hash(char *str)
{
    uint32_t hash = 5381;
    while (*str)
    {
        hash = ((hash << 5) + hash) + *str++;
    }
    return hash;
}

char json1[] = "{ \"ip\" : \"94.140.147.142\", \"pi\": 12}";
char json2[] = "{\"status\":\"success\",\"country\":\"Russia\",\"countryCode\":\"RU\",\"region\":\"SVE\",\"regionName\":\"Sverdlovsk Oblast\",\"city\":\"Yekaterinburg\",\"zip\":\"620028\",\"lat\":56.8577,\"lon\":60.6113,\"timezone\":\"Asia/Yekaterinburg\",\"isp\":\"MTS EKB B2C 2\",\"org\":\"PJSC MTS Sverdlovsk region\",\"as\":\"AS8359 MTS PJSC\",\"query\":\"94.140.147.142\"}";

bool is_num(char c)
{
    return (c >= '0' && c <= '9') || c == '.';
}

// TODO:nesting nodes
int parse_json(map *map, char* json)
{
    int i = 0;

    while (json[i] != '{') {++i;}
    for (;;)
    {
        while (json[i] != '\"') 
        {
            if (json[i] == '}')
                return 0;
            ++i;
        }
        if (json[i] == '\"') ++i;
        char *key_start = json + i;
        while (json[i] != '\"') {++i;}
        char *key_end = json + i;
        if (json[i] == '\"') ++i;

        while (json[i] != ':') {++i;}

        while (json[i] != '\"' && !is_num(json[i])) {++i;}
        if (json[i] == '\"') ++i;
        char *val_start = json + i;
        // TODO: comma handling in string
        while (json[i] != '\"' && json[i] != ',' && json[i] != '}') {++i;}
        char *val_end = json + i;
        if (json[i] == '\"') ++i;

        int key_len = (uint64_t)key_end - (uint64_t)key_start;
        int val_len = (uint64_t)val_end - (uint64_t)val_start;
        char *key = malloc(key_len + 1);
        char *val = malloc(val_len + 1);
        memcpy(key, key_start, key_len);
        memcpy(val, val_start, val_len);
        key[key_len] = '\0';
        val[val_len] = '\0';

        //printf("key=%s\nvalue=%s\n\n", key, val);

        map_insert(map, key, val, STRING);
    }
    return 0;
}

/*
int main()
{
    map map = {};
    parse_json(&map, json1);
    parse_json(&map, json2);
}
*/
