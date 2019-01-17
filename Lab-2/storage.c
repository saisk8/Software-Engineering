#include <stdio.h>
#include <stdlib.h>

void getRecords(FILE *in, FILE *out, int n) {
    for (int i = 0; i < n; i++) {
        struct Student *student = malloc(sizeof(struct Student));
        fscanf(in, "%s", student->name);
        fscanf(in, "%d %d", &student->age, &student->rollNumber);
        fscanf(in, "%f %f", &student->m1, &student->m2);
        fscanf(in, "%s", student->address.street);
        fscanf(in, "%s", student->address.city);
        fscanf(in, "%s", student->address.state);
        student->total = student->m1 + student->m2;
        student->avg = student->total / 200;
        if (student->avg >= 0.85) {
            student->grade = 'A';
        }
        if (student->avg < 0.85 && student->avg >= 0.65) {
            student->grade = 'B';
        }
        if (student->avg < 0.65 && student->avg >= 0.55) {
            student->grade = 'C';
        }
        if (student->avg < 0.55 && student->avg >= 0.35) {
            student->grade = 'D';
        }
        if (student->avg < 0.35) {
            student->grade = 'F';
        }
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
        printf("Name: %s\n", student->name);
        printf("Age: %d\nRoll Number: %d\n", student->age, student->rollNumber);
        printf("Address:\n-------------------------------\n");
        printf("Street: %s\nCity: %s\nState: %s\n", student->address.street,
               student->address.city, student->address.state);
        printf("M1 = %f, M2 = %f, Avg = %f, Total = %f, Grade: %c\n",
               student->m1, student->m2, student->avg, student->total,
               student->grade);
        printf("\n\n");
    }
}