#include "storage-device.h"
#include "input.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
	Storage_device *sd1, *sd2;
	Storage *s;
	sd1 = storage_device_constructor("asd", true, 123, 123);
    sd2 = storage_device_constructor("zxc", false, 1, 222);
    s = storage_constructor(1,0);
    add_storage_device(s, sd2);
    add_storage_device(s, sd1);
}