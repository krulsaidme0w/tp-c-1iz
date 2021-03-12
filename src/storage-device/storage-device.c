#include "storage-device.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

Storage_device * storage_device_constructor(char *type, bool overwrite, size_t capacity, size_t inventory_number) {
    Storage_device *sd = malloc(sizeof(Storage_device));
    sd->capacity = capacity;
    sd->inventory_number = inventory_number;
    sd->type = type;
    sd->overwrite = overwrite;

    return sd;
}

Storage * storage_constructor(Storage_device *data) {
    if(data) {
        size_t new_size = sizeof(*data) / sizeof(Storage_device);
        Storage *s = (Storage *)malloc(sizeof(Storage_device) * (new_size + 1) + 2 * sizeof(size_t));
        s->data = data;
        s->size = new_size;
        s->capacity = new_size + 1;
        return s;
    }
    else {
        Storage *s = NULL;
        s->data = NULL;
        s->capacity = 0;
        s->size = 0;
        return s;
    }
}

bool add_storage_device(Storage *s, Storage_device *sd) {
    if(sd == NULL) {
        return 0;
    }
    size_t new_capacity = s->capacity;
    if(s->size + 1 >= s->capacity) {
        new_capacity = !(s->capacity) ? 1 : s->capacity * 2;
    }
    Storage_device *tmp = (Storage_device *)malloc(sizeof(Storage_device) * (new_capacity + 1));
    tmp = s->data;
    tmp[s->size] = *sd;
    s->data = tmp;
    s->size = s->size + 1;
    s->capacity = new_capacity;
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