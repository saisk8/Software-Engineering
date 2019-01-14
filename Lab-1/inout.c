#include<stdio.h>
#include<stdlib.h>

double **inputMatrix(int m, int n, FILE* file) {
	double **matrix = (double **)malloc(sizeof(double *) * m);
	for (int i = 0; i < m; i++)
		matrix[i] = (double *)malloc(sizeof(double) * n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if(!fscanf(file, "%lf", &matrix[i][j])) {
				return NULL;
			}
		}
	}
	return matrix;
}

void printMatrix(double **matrix, int m, int n, FILE *out) {
	fprintf(out, "The resultant matrix is: \n");
	for (int i = 0; i < m; i++ ) {
		for (int j = 0; j < n; j++) {
			fprintf(out, "%.3lf ", matrix[i][j]);
		}
		fprintf(out, "\n");
	}
}

