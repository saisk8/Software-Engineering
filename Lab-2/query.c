#include <stdio.h>
#include <stdlib.h>
#include "definations.h"

struct Student *getNextRecord(FILE **in) {
    struct Student *student;
    fread(student, sizeof(struct Student), 1, *in);
    return student;
}

int compareNextRecord(int option, void *data, FILE **in) {
    // A fuction to execute the query...
}