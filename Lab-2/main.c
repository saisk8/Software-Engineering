#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "definations.h"
#include "query.c"
#include "storage.c"

int main() {
    while (1) {
        printf("1.Add records\n");
        printf("2.List all records\n");
        printf("3.Get record by roll number\n");
        printf("4.Get record(s) by Grade\n");
        printf("5.Modify record\n");
        printf("0. exit\n");
        printf("Enter your choice: ");
        char choice = getchar();
        FILE *in, *out, *temp;
        int n, roll;
        char grade;
        printf("Enter the number of records: ");
        scanf("%d", &n);
        switch (choice) {
            case '1':
                in = fopen("in.txt", "r");
                out = fopen("student.dat", "w");
                getRecords(in, out, n);
                fclose(in);
                fclose(out);
                printf("Records added\n");
                break;

            case '2':
                in = fopen("student.dat", "r");
                printRecords(in, n);
                break;

            case '3':
                in = fopen("student.dat", "r");
                printf("Enter the roll number: ");
                scanf("%d", &roll);
                getRecordByRoll(roll, in, n);
                break;
            case '4':
                in = fopen("student.dat", "r");
                printf("Enter the grade: ");
                scanf("%c", &grade);
                grade = toupper(grade);
                getRecordByGrade(grade, in, n);
                break;
            case '5':
                in = fopen("student.dat", "r");
                printf("Enter the roll number for the record to be updated: ");
                scanf("%d", &roll);
                updateRecordByRoll(roll, in, n);
                break;
            case '0':
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
}