#include <stdio.h>
#include <stdlib.h>
#include "inout.c"
#include "matrixMul.c"

int main() {
	FILE *fileIn = fopen("in.txt", "r");
	FILE *fileOut = fopen("out.txt", "w");
	int testCases;
	fscanf(fileIn, "%d", &testCases);
	for (int t = 0; t < testCases; t++) {
		fprintf(fileOut, "Test Case %d:\n\n", t + 1);
		int m, n, p, q;
		fscanf(fileIn, "%d %d", &m, &n);
		double **matrix1 = inputMatrix(m, n, fileIn);
		fscanf(fileIn, "%d %d", &p, &q);
		double **matrix2 = inputMatrix(p, q, fileIn);

		if (n != p) {
			fprintf(fileOut, "The matrices cannot be multiplied\n\n");
			continue;
		}

		double **result = (double **)malloc(sizeof(double *) * m);
		for (int i = 0; i < m; i++) {
			result[i] = (double *)malloc(sizeof(double) * q);
		}
		result = matrixMul(matrix1, matrix2, result, m, p, q);
		if (!result) {
			fprintf(fileOut, "Invalid input received!\n\n");
			continue;
		}
		printMatrix(result, p, q, fileOut);
		fprintf(fileOut, "\n");
	}
	return 0;
}
