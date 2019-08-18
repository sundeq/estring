#ifndef ESTRING_H
#define ESTRING_H

struct SplitStringStruct {
    char **string_list;
    int n_elements;
};

typedef struct SplitStringStruct SplitStringStruct;

SplitStringStruct *split_string(char *string, char delimiter);

#endif
