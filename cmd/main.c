#include "storage-device.h"
#include "input.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

const size_t capacity = 1;
const size_t size = 0;


int main() {
	Storage *s = storage_constructor(capacity, size);

	char *command = "0";

    do
    {
        if(!strcmp(command, "0")) {
            printf("0. about\n");
            printf("1. show all\n");
            printf("2. add new storage device\n");
            printf("3. find all storage devices by size\n");
            printf("4. exit\n");
            continue;
        }

        if(!strcmp(command, "1")) {
            print_storage(s);
            continue;
        }

        if(!strcmp(command, "2")) {
            bool sd_overwrite;
            size_t sd_number;
            size_t sd_capacity;

            printf("\ninput type of storage device: ");
            char *sd_type = gstr();

            if (sd_type == NULL) {
                printf("\nfailed to allocate memory to type *char");
                break;
            }

            printf("\ninput storage device overwrite possibility(1, 0): ");
            sd_overwrite = 1;

            printf("\ninput inv. number of storage device: ");
            if(!scanf("%lu", &sd_number)) {
                printf("\nfailed to allocate memory to inv. number");
                break;
            }

            printf("\ninput capacity of storage device: ");
            if(!scanf("%lu", &sd_capacity)) {
                printf("\nfailed to allocate memory to capacity");
                break;
            }

            Storage_device *sd = storage_device_constructor(sd_type, sd_overwrite, sd_capacity, sd_number);

            if (!add_storage_device(s, sd)) {
                printf("\nfailed to add sd to storage");
                break;
            }

            continue;
        }

        if(!strcmp(command, "3")) {
            continue;
        }

        if(!strcmp(command, "4")) {
            printf("\ngoodbye!\n");
            break;
        }

        printf("unknown command: %s\n", command);
    } while(printf("\ninput command number (0 - help): "), command = gstr(), command != NULL);

    delete_storage(s);

    return 0;
}