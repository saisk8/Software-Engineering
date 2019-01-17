#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "definations.h"
#include "query.c"
#include "storage.c"

int main() {
    FILE *in, *out, *temp;
    int n, roll, choice;
    char grade;
    while (1) {
        printf("1.Add records\n");
        printf("2.List all records\n");
        printf("3.Get record by roll number\n");
        printf("4.Get record(s) by Grade\n");
        printf("5.Modify record\n");
        printf("0. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                in = fopen("in.txt", "r");
                fscanf(in, "%d", &n);
                out = fopen("student", "w");
                getRecords(in, out, n);
                fclose(in);
                fclose(out);
                printf("Records added\n");
                break;

            case 2:
                in = fopen("student", "r");
                printRecords(in, n);
                fclose(in);
                break;

            case 3:
                in = fopen("student", "r");
                printf("Enter the roll number: ");
                scanf("%d", &roll);
                getRecordByRoll(in, roll, n);
                fclose(in);
                break;
            case 4:
                in = fopen("student", "r");
                printf("Enter the grade:");
                scanf(" %c", &grade);
                grade = toupper(grade);
                getRecordByGrade(grade, in, n);
                fclose(in);
                break;
            case 5:
                in = fopen("student", "r+");
                printf("Enter the roll number for the record to be updated: ");
                scanf("%d", &roll);
                updateRecordByRoll(roll, in, n);
                fclose(in);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}