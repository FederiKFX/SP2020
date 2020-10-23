#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern "C" int  calc(short, char, int);

extern "C"
{
	int K = 0x7AA02023;
};

int main(void)
{
	short A = 0;
	char C = 0;
	int D = 0;

	int res = 0;
	printf("Enter numbers:\n");
	printf("A = ");
	scanf("%hd", &A);
	printf("C = ");
	scanf("%hhd", &C);
	printf("D = ");
	scanf("%d", &D);
	res = calc(A, C, D);

	printf("Result is: %x\n", res);
}
