#include<math.h>

double **matrixMul(double **a, double **b, double **c,
			int p, int q, int r) {
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < q; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}
