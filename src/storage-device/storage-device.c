#include "storage-device.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

Storage_device * storage_device_constructor(char *type, bool overwrite, size_t capacity, size_t inventory_number) {
    Storage_device *sd = malloc(sizeof(Storage_device));

    if(!sd) {
        return NULL;
    }

    sd->capacity = capacity;
    sd->inventory_number = inventory_number;
    sd->type = type;
    sd->overwrite = overwrite;

    return sd;
}

Storage * storage_constructor(size_t capacity, size_t size) {
    Storage *s = malloc(sizeof(Storage));

    if(!s) {
        return 0;
    }

    s->capacity = capacity;
    s->size = size;
    s->data = (Storage_device *)malloc(sizeof(Storage_device) * capacity);

    if(!s->data) {
        return NULL;
    }

    return s;
}

bool add_storage_device(Storage *s, Storage_device *sd) {
    if(sd == NULL) {
        return 0;
    }

    if(s->size + 1 >= s->capacity) {
        s->capacity *= 2;
        s->data = (Storage_device *)realloc(s->data, sizeof(Storage_device) * s->capacity);

        if(!s->data) {
            return 0;
        }
    }

    s->data[s->size] = *sd;
    s->size += 1;
    return 1;
}

bool print_storage_device(Storage_device *sd) {
    if(printf("%s\t%zu\t%d\t%zu\n", sd->type, sd->capacity, sd->overwrite, sd->inventory_number)) {
        return 1;
    }
    return 0;
}

bool print_storage(Storage *s) {
    return 1;
}

bool delete_storage(Storage *s) {
	return 1;
}