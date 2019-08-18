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
    int finished_parsing = 0;

    buffer_len = 1;
    buffer = (char *) malloc(sizeof(char));
    buffer[buffer_len-1] = '\0';
    n_elements = 0;
    i = 0;
    while (!finished_parsing) {
        c = string[i];
	if (c == delimiter || c == EOF) {
	    printf("hellu %c\n", c);
	    fflush(stdout);
	    n_elements++;
	    elements = (char **) realloc(elements, sizeof(char *) * n_elements);
	    elements[n_elements-1] = (char *) malloc(sizeof(char) * buffer_len);
	    for (j = 0; j <= buffer_len; j++) {
		    elements[n_elements-1][j] = buffer[j];
	    }
	    buffer_len = 1;
            buffer = (char *) malloc(sizeof(char));
	    buffer[buffer_len-1] = '\0';
	    finished_parsing = c == EOF;
	} else {
	    buffer_len++;
	    buffer = (char *) realloc(buffer, sizeof(char) * buffer_len);
	    buffer[buffer_len-1] = '\0';
	    buffer[buffer_len-2] = c;
	}
	i++;
    }

    split_struct->string_list = elements;
    split_struct->n_elements = n_elements;
    return split_struct;
}
