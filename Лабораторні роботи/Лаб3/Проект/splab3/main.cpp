#define _CRT_SECURE_NO_WARNINGS  // for using scanf in VS

#include <stdio.h>

// X = K + A2*B2 - C1 - D1/E2 // K=0x7AA02023
extern "C" void calcLab3(double, double, float, float, double);

int main()
{
	float C, D;
	double A, B, E;

	printf("Enter values:\n");
	printf("A = ");
	scanf("%lf", &A);
	printf("B = ");
	scanf("%lf", &B);
	printf("C = ");
	scanf("%f", &C);
	printf("D = ");
	scanf("%f", &D);
	printf("E = ");
	scanf("%lf", &E);
	calcLab3(A, B, C, D, E);
	return 0;
}