#include <stdio.h>
#include <stdlib.h>
#include "estring.h"

SplitStringStruct *split_string(char *string, char delimiter) {
    SplitStringStruct *split_struct = (SplitStringStruct *) malloc(sizeof(SplitStringStruct));
    int i, j;
    char c;
    char *buffer;
    int buffer_len;
    char **elements = NULL;
    int n_elements;

    buffer_len = 1;
    buffer = (char *) malloc(sizeof(char));
    buffer[buffer_len-1] = '\0';
    n_elements = 0;
    for (i = 0; c != EOF; i++) {
        c = string[i];
	if (c == delimiter) {
	    n_elements++;
	    elements = (char **) realloc(elements, sizeof(char *) * n_elements);
	    elements[n_elements-1] = (char *) malloc(sizeof(char) * buffer_len);
	    for (j = 0; j <= buffer_len; j++) {
		    elements[n_elements-1][j] = buffer[j];
	    }
	    buffer_len = 1;
            buffer = (char *) malloc(sizeof(char));
	    buffer[buffer_len-1] = '\0';
	} else {
	    buffer_len++;
	    buffer = (char *) realloc(buffer, sizeof(char) * buffer_len);
	    buffer[buffer_len-1] = '\0';
	    buffer[buffer_len-2] = c;
	}
    }
    return split_struct;
}
