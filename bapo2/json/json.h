#include <stdint.h>

// TODO: array handling
typedef enum VALUE_TYPE
{
    STRING,
    NUMBER,
    NODE,
    VALUE_TYPE_COUNT
} VALUE_TYPE;

typedef struct map_node
{
    char *key;
    uint32_t hash;

    VALUE_TYPE value_type;
    void *value;

    struct map_node *next;
} map_node;

typedef struct map
{
    map_node *buckets[10];
} map;

map_node **map_find(map *map, char *key);
void map_insert(map *map, char *key, void *value, VALUE_TYPE value_type);
int parse_json(map *map, char* json);
