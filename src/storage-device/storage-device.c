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
        s->capacity = !(s->capacity) ? 1 : s->capacity * 2;
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
    if(sd == NULL) {
        return 0;
    }
    printf("\t{\n");
    printf("\t\ttype: %s;\n", sd->type);
    printf("\t\toverwrite: %d;\n", sd->overwrite);
    printf("\t\tcapacity: %lu;\n", sd->capacity);
    printf("\t\tinventory_number: %lu;\n", sd->inventory_number);
    printf("\t},\n");
    return 1;
}

bool print_storage(Storage *s) {
    if(!s) {
        return 0;
    }

    printf("storage_devices:\n{\n");

    for(size_t i = 0; i < s->size; ++i) {
        printf("\tstorage_device-%lu:",i);
        print_storage_device(&s->data[i]);
    }

    printf("}\n");

    return 1;
}

bool delete_storage(Storage *s) {
    if(s == NULL) {
        return 1;
    }

    if(s->data == NULL) {
        free(s);
        s = NULL;
        return 1;
    }

    free(s->data);
    free(s);
    s = NULL;

    return 1;
}