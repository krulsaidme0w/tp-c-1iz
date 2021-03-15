#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char get_char() {
    char c = '\0';
    int result = 0;
    do {
        result = scanf("%c", &c);
    } while (result != 1);
    return c;
}

char *get_s() {
    struct buffer {
        char *string;
        size_t size;
        size_t capacity;
    } buf = {NULL, 0, 0};
    char c = '\0';
    while (c = get_char(), c != EOF && c != '\n') {
        if (buf.size + 1 >= buf.capacity) {
            size_t new_capacity = !buf.capacity ? 1 : buf.capacity * 2;
            char *tmp = (char *)malloc((new_capacity + 1) * sizeof(char));
            if (!tmp) {
                if (buf.string) {
                    free(buf.string);
                }
                return NULL;
            }
            if (buf.string) {
                tmp = strcpy(tmp, buf.string);
                free(buf.string);
            }
            buf.string = tmp;
            buf.capacity = new_capacity;
        }
        buf.string[buf.size] = c;
        buf.string[buf.size + 1] = '\0';
        ++buf.size;
    }
    return buf.string;
}

size_t get_size_t() {
    char ch = '\0';
    size_t result = 0;
    while (ch = get_char(), ch != EOF && ch != '\n') {
        if (!(ch >= '0' && ch <= '9')) {
            char *buf = get_s();
            if (buf) {
                free(buf);
            }
            return 0;
        }
        result = result * 10 + ch - '0';
    }
    return result;
}

int get_int() {
    char c = '\0';
    int result = 0;
    while (c = get_char(), c != EOF && c != '\n') {
        if (!(c >= '0' && c <= '9')) {
            char *buf = get_s();
            if (buf) {
                free(buf);
            }
            return 0;
        }
        result = result * 10 + c - '0';
    }
    return result;
}

int get_bool() {
    int c = get_int();
    if(c == 0)
        return 0;
    else if(c == 1)
        return 1;
    else
        return -1;
}
