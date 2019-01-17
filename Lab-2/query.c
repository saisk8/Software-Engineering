#include <stdio.h>
#include <stdlib.h>

int getRecordByRoll(int roll, FILE *in, int n) {
    struct Student *student;
    for (int i = 0; i < n; i++) {
        fread(student, sizeof(struct Student), 1, in);
        if (student->rollNumber == roll) {
            printf("Record Found!\n*********************\n");
            printf("Name: %s", student->name);
            printf("Age: %d\nRoll Number: %d", student->age,
                   student->rollNumber);
            printf("Address:\n-------------------------------\n");
            printf("Street: %s\nCity: %s\nState: %s\n", student->address.street,
                   student->address.city, student->address.state);
            printf("\n\n");
            return 1;
        }
    }
    printf("There is no record with the given roll number\n");
    return 0;
}

int getRecordByGrade(char grade, FILE *in, int n) {
    int found = 0;
    struct Student *student;
    for (int i = 0; i < n; i++) {
        fread(student, sizeof(struct Student), 1, in);
        if (student->grade == grade) {
            found = 1;
            printf("Record Found!\n*********************\n");
            printf("Name: %s", student->name);
            printf("Age: %d\nRoll Number: %d", student->age,
                   student->rollNumber);
            printf("Address:\n-------------------------------\n");
            printf("Street: %s\nCity: %s\nState: %s\n", student->address.street,
                   student->address.city, student->address.state);
            printf("\n\n");
        }
    }
    if (!found) {
        printf("No record found!\n");
    } else {
        return 1;
    }
    return 0;
}

int updateRecordByRoll(int roll, FILE *in, int n) {
    struct Student *student;
    for (int i = 0; i < n; i++) {
        fread(student, sizeof(struct Student), 1, in);
        if (student->rollNumber == roll) {
            printf("Record Found!\n*********************\n");
            printf("Enter the name: ");
            scanf("%s", student->name);
            printf("Enter the age and roll number: ");
            scanf("%d %d", student->age, student->rollNumber);
            printf("Enter the marks in two subjects: ");
            scanf("%f %f", student->m1, student->m2);
            printf("Enter the street name: ");
            scanf("%s", student->address.street);
            printf("Enter the City: ");
            scanf("%s", student->address.city);
            printf("Enter the State: ");
            scanf("%s", student->address.state);
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
            fseek(in, -sizeof(struct Student), SEEK_CUR);
            fwrite(student, sizeof(struct Student), 1, in);
            printf("Record Updated!\n*********************\n");
            printf("Name: %s", student->name);
            printf("Age: %d\nRoll Number: %d", student->age,
                   student->rollNumber);
            printf("Address:\n-------------------------------\n");
            printf("Street: %s\nCity: %s\nState: %s\n", student->address.street,
                   student->address.city, student->address.state);
            printf("\n\n");
            return 1;
        }
    }
    printf("There is no record with the given roll number\n");
    return 0;
}