#ifndef STORAGE_DEVICE_H
#define STORAGE_DEVICE_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
	char * type;
	bool overwrite;
	size_t capacity;
	size_t inventory_number;
} Storage_device;

#endif 
