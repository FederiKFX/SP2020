#include <stdio.h>

extern "C" void printResult(int value)
{
	printf("Result is : %x\n", value);
	return;
}
