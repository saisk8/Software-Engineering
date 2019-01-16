#include <stdio.h>
#include <stdlib.h>
#include "definations.h"

void getRecords(FILE *in, FILE *out, int n) {
    for (int i = 0; i < n; i++) {
        struct Student *student = malloc(sizeof(struct Student));
        fscanf(in, "%s", student->name);
        fscanf(in, "%d %d", student->age, student->rollNumber);
        fscanf(in, "%f %f", student->m1, student->m2);
        fscanf(in, "%s", student->address.street);
        fscanf(in, "%s", student->address.city);
        fscanf(in, "%s", student->address.state);

        // Write the info to a file
        fwrite(student, sizeof(struct Student), 1, out);
        free(student);
    }
}

void printRecords(FILE *in, int n) {
    for (int i = 0; i < n; i++) {
        struct Student *student = malloc(sizeof(struct Student));
        fread(student, sizeof(struct Student), 1, in);
        printf(
            "Record %d\n**************************************************\n",
            i + 1);
        printf("Name: %s", student->name);
        printf("Age: %d\nRoll Number: %d", student->age, student->rollNumber);
        printf("Address:\n-------------------------------\n");
        printf("Street: %s\nCity: %s\nState: %s\n", student->address.street,
               student->address.city, student->address.state);
        printf("\n\n");
    }
}