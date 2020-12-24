#pragma once
#include "DataTypes.h"
#include "Analizer.h"
#include "ErrorsCheck.h"
#include "Generator.h"

int main(int argc, char* argv[])
{
	printf("=================================================================================================\n");
	printf("TRANSLATOR (y23 -> ASSEMBLER)\n");
	printf("KI-38 \n");
	printf("=================================================================================================\n");

	// Checking the number of arguments to be passed from the command line
	if (argc != 2)
	{
		printf("Warning! Invalid parameter list!\n");
		printf("Example: spkursova.exe inputFile.y23");
		getchar();
		exit(1);
	}

	// Obtaining and formation names of incoming and outgoing files
	strcpy(Data.InputFileName, argv[1]);

	printf("Start translating file: %s\n", Data.InputFileName);

	if ((InF = fopen(Data.InputFileName, "r")) == 0)
	{
		printf("Error: Can not open file: %s\n", Data.InputFileName);
		getchar();
		exit(1);
	}

	strncpy(Data.OutputFileName, Data.InputFileName, strlen(Data.InputFileName) - 3);
	strcat(Data.OutputFileName, "asm");
	printf("Output file: %s\n", Data.OutputFileName);
	printf("=================================================================================================\n");
	
	if ((OutF = fopen(Data.OutputFileName, "w")) == 0)
	{
		printf("Error: Can not create file: %s\n", Data.OutputFileName);
		getchar();
		exit(1);
	}

	// Breaking into tokens and printing into file
	printf("Breaking into lexems are starting...\n");
	Data.LexNum = AnalisisLexems(InF);
	PrintLexemsInFile();
	printf("Breaking into lexems completed. There are %d lexems.\nReport file: lexems.txt\n", Data.LexNum);
	printf("=================================================================================================\n");


	printf("Error checking are starting...\n");
	Data.numberErrors = ErrorChecking();
	printf("Error checking is complete. There is(are) %d errors.\nReport file: errors.txt\n", Data.numberErrors);
	printf("=================================================================================================\n");

	// If there are no errors, go to a translation stage
	if (Data.numberErrors != 0)
	{
		printf("Translation can not be continued. Errors were found. Please correct the errors and try again.\n");
	}
	else
	{
		printf("Code generation is starting...\n");
		GenerateCode(OutF);
		printf("Code generation is finish.\n");
		printf("=================================================================================================\n");
		printf("Done!\n");
	}
	return 0;
}