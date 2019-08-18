#include <stdio.h>
#include "estring.h"

int main(int argc, char **argv) {
    SplitStringStruct *split_string_struct =  split_string("123,456,789", ',');
    printf("string list 1: %s\n", split_string_struct->string_list[0]);
    printf("string list 2: %s\n", split_string_struct->string_list[1]);
    printf("string list 3: %s\n", split_string_struct->string_list[2]);
    printf("number of elements %d\n", split_string_struct->n_elements);
}
