// To test the in out of a structure of type student
#include<stdio.h>
#include<stdlib.h>

struct Student {
	int roll, age;
	char grade;
	float m1, m2, total, avg;
	char name[50];
};

int main() {
    FILE *p = fopen("in.txt", "r");
	int n;
	// printf("Enter the number of students: ");
	fscanf(p, "%d", &n);
	struct Student records[n];
    for (int i = 0; i < n; i++) {
        // printf("Enter the name of the student (max 50 characters): ");
        fscanf(p, "%s", &records[i].name);
        // printf("Enter the roll number of the student: ");
        fscanf(p, "%d", &records[i].roll);
        // printf("Enter the age of the student: ");
        fscanf(p, "%d", &records[i].age);
        // printf("Enter the marks in subject 1 of the student: ");
        fscanf(p, "%f", &records[i].m1);
        // printf("Enter the marks in subject 2 of the student: ");
        fscanf(p, "%f", &records[i].m2);
        records[i].total = records[i].m1 + records[i].m2;
        records[i].avg = records[i].total[i] / 2;
    }
    for (int i = 0; i < n; i++) {
        // printf("Enter the name of the student (max 50 characters): ");
        fprintf(p, "%s", records[i].name);
        // printf("Enter the roll number of the student: ");
        fprintf(p, "%d", records[i].roll);
        // printf("Enter the age of the student: ");
        fprintf(p, "%d", records[i].age);
        // printf("Enter the marks in subject 1 of the student: ");
        fprintf(p, "%f", records[i].m1);
        // printf("Enter the marks in subject 2 of the student: ");
        fprintf(p, "%f", records[i].m2);
        fprintf(p, "%f", records[i].total, records[i].avg, records[i].grade);
         
    }
    return 0;
}