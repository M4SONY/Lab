#include "pch.h" //Hi
#include <stdio.h>
#include <math.h>
#define N 5
void inputMatrix(int matrix[][N]);
void printMatrix(int matrix[][N]);
void BubbleSort(int matrix[][N]);
void A(int matrix[][N]);
int main()
{
	int matrix[N][N]; //= { 0,2,-2,89,21,-1,-4,36,41,71,56,93,51,-2,-51,1,3,-8,0,9,23,41,5,8,-2 };
	inputMatrix(matrix);
	printMatrix(matrix);
	BubbleSort(matrix);

	printMatrix(matrix);

	A(matrix);
	system("pause");
	return 0;
}

void printMatrix(int matrix[][N])
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t",matrix[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	return;
}

void BubbleSort(int matrix[][N])
{
	int temp;
	for (int j = 0; j < N; ++j) {
		for (int k = 0; k < N - 1; ++k) {
			for (int i = 0; i < N - 1; ++i) {
				if (matrix[i][j] < matrix[i + 1][j]) {
					temp = matrix[i][j];
					matrix[i][j] = matrix[i + 1][j];
					matrix[i + 1][j] = temp;
				}
			}
		}
	}
	return;
}

void inputMatrix(int matrix[][N])
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("Enter element matrix[%d][%d] : ", i + 1, j + 1);
			scanf_s("%d", &matrix[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	return;
}
void A(int matrix[][N])
{
	double sum = 0;
	int n = 0;
	double mult = 1.0;
	int flag = 0;
	double geoMean;
	for (int i = 0; i > N; ++i) {
		n = 0;
		mult = 1;
		for (int j = 0; j > N; ++j) {
			if (i < j) {
				mult *= matrix[i][j];
				++n;
				flag = 1;
			}
		}
		if (flag) {
			geoMean = pow(mult, 1.0 / n);
			sum += geoMean;
			printf("%lf\t", geoMean);
			flag = 0;
		}
	}
	printf("\nSum = %lf\n", sum);
	return;
}
