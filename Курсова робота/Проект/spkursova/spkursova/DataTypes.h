#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "malloc.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

#define MAX_LEXEMS 1000
#define MAX_IDENT 100
#define MAX_BUF_SIZE 100
#define STACK_SIZE 200
#define MAX_LENGTH_TYPES 20

enum TypeOfLex
{
	LProgram,		// MAINPROGRAM
	LStart,			// START
	LData,			// DATA
	LVarType,		// Integer32
	LIdentifier,	// NameVar
	LEnd,			// END
	
	LScan,			// Scan
	LPrint,			// Print

	LIf,			// IF
	LThen,			// THEN
	LElse,			// ELSE
	LEndIf,			// EndIf

	LNewValue,		// ->
	LAdd,			// +
	LSub,			// -
	LMul,			// *
	LDiv,			// DIV
	LMod,			// MOD
	LEqu,			// ==
	LNotEqu,		// !=
	LGreate,		// >=
	LLess,			// <=
	LNot,			// NOT
	LAnd,			// AND
	LOr,			// OR

	LLBraket,		// (
	LRBraket,		// )
	LNumber,		// number
	LSeparator,		// ;
	LComma,			// ,
	LEOF,			// EndFile
	LUnknown
};

//DATA
typedef struct Lexem
{
	char name[50];
	int value;
	int line;
	TypeOfLex type;
}Lexema;

typedef struct ID
{
	char name[50];
	int value;
}Identificator;

typedef struct L
{
	Lexema LexTable[MAX_LEXEMS];			//Таблиця лексем
	int LexNum;								//

	Identificator IdTable[MAX_IDENT];		//Таблиця ідентифікаторів
	int IdNum;								//

	bool IsPresentInput,					//Ознаки присутності операторів
	IsPresentOutput,
	IsPresentMod,
	IsPresentAnd,
	IsPresentOr,
	IsPresentNot,
	IsPresentEqu,
	IsPresentGreate,
	IsPresentLess;

	int numberErrors;

	char InputFileName[50];
	char OutputFileName[50];

	int bufExprPostfixForm[MAX_BUF_SIZE];	//Буфер для виразу в постфіксній формі
}DataType;

typedef struct Stacks
{
	int st[STACK_SIZE];
	int top;
}StackType;

typedef class stack
{
public:
	StackType S;
	void Init(StackType* s)
	{
		s->top = -1;
	}

	void Push(int i, StackType* s)
	{
		if (IsFull(s))
		{
			puts("Stack error (is full)");
			exit(0);
		}
		else
		{
			++s->top;
			s->st[s->top] = i;
		}
	}
	int Pop(StackType* s)
	{
		int i;
		if (IsEmpty(s))
		{
			puts("Stack error (is empty)");
			exit(0);
		}
		else
		{
			i = s->st[s->top];
			--s->top;
		}
		return i;
	}
	bool IsEmpty(StackType* s)
	{
		if (s->top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsFull(StackType* s)
	{
		if (s->top == 199)return true;
		else return false;
	}
	void prints(StackType s)
	{
		int i = 0;
		for (; i < 10; ++i)
		{
			printf("%d_", s.st[i]);
		}
	}
}StackT;

StackT Stack, StackIf;						//Стек

DataType Data;						//Структура-реєстр в якій зберігаються всі дані програми

FILE* InF, * OutF, * ErrorF;