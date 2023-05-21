#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

void GetRows(int* rows)
{
	while (true)
	{
		printf_s("Enter rows: ");
		scanf_s("%d", rows);
		if (*rows > 0)
			break;
		printf_s("Invalid value!\n");
	}
}

void GetMemoryRows(int*** array, int** arrayOfColumns, int* rows)
{
	*array = (int**)malloc(sizeof(int*) * (*rows));
	*arrayOfColumns = (int*)malloc(sizeof(int) * (*rows));
	if (!(*array))
	{
		printf_s("Can't get memory!\n");
		system("pause");
	}

	if (!(*arrayOfColumns))
	{
		printf_s("Can't get memory!\n");
		system("pause");
	}
}

void GetColumns(int* i, int* arrayOfColumns)
{
	while (true)
	{
		printf_s("Enter columns in %d line: ", (*i) + 1);
		scanf_s("%d", &arrayOfColumns[*i]);
		if (arrayOfColumns[*i] > 0)
			break;
		printf_s("invalid value!\n");
	}
}


void GetArray2(int** array, int* arrayOfColumns, int* rows)
{
	for (int i = 0; i < *rows; i++)
	{
		GetColumns(&i, arrayOfColumns);

		array[i] = (int*)malloc(sizeof(int) * arrayOfColumns[i]);

		for (int j = 0; j < arrayOfColumns[i]; j++)
		{
			printf_s("Array[%d][%d] = ", i + 1, j + 1);
			scanf_s("%d", &array[i][j]);
		}
	}
}

void PrintArray2(int** array, int* arrayOfColumns, int* rows )
{
	int max = INT_MIN;
	for (int i = 0; i < *rows; i++)
	{
		int sum = 0;
		for (int j = 0; j < arrayOfColumns[i]; j++)
		{
			printf_s("%d\t", array[i][j]);
			sum += array[i][j];
		}
		printf_s("It's sum = %d", sum);
		if (sum > max)
			max = sum;
		printf_s("\n");
	}
	printf_s("max sum = %d", max);

}

void FreeMemory(int** array, int* arrayOfColumns, int* rows)
{
	for (int i = 0; i < *rows; i++)
		free(array[i]);
	free(array);
	free(arrayOfColumns);
}

void task_2()
{
	int rows = 0;
	int** array = NULL;
	int* arrayOfColumns = NULL;

	GetRows(&rows);

	GetMemoryRows(&array, &arrayOfColumns, &rows);

	GetArray2(array, arrayOfColumns, &rows);

	PrintArray2(array, arrayOfColumns, &rows);

	FreeMemory(array, arrayOfColumns, &rows);
}