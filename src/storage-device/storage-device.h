#ifndef STORAGE_DEVICE_H
#define STORAGE_DEVICE_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
	char *type;
	bool overwrite;
	size_t capacity;
	size_t inventory_number;
} Storage_device;
Storage_device * storage_device_constructor(char *type, bool overwrite, size_t capacity, size_t inventory_number);

typedef struct {
	Storage_device *data;
	size_t size;
	size_t capacity;
} Storage;
Storage * storage_constructor(Storage_device *data, size_t size, size_t capacity);

bool add_storage_device(Storage *s, Storage_device sd);
bool print_storage(Storage *s);
bool delete_storage(Storage *s);

#endif 
