#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

void GetRowsColumns1(int* rows, int* columns)
{
	while (true)
	{
		printf_s("Enter rows: ");
		scanf_s("%d", rows);
		if (*rows > 0)
			break;
		printf_s("Invalid value!\n");
	}

	while (true)
	{
		printf_s("Enter columns: ");
		scanf_s("%d", columns);
		if (*columns > 0)
			break;
		printf_s("Invalid value!\n");
	}
}

void inline GetMemory(int** array, int* num1, int* num2)
{
	*array = (int*)malloc(sizeof(int) * (*num1) * (*num2));
	if (!(*array))
	{
		printf_s("Can't malloc memory!\n");
		system("pause");
	}
}

void GetArray(int* array, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("Array[%d][%d] = ", i + 1, j + 1);
			scanf("%d", &array[i * columns + j]);
		}
	}
}

void PrintArray(int* array, int rows, int columns)
{
	int max = INT_MIN;
	for (int i = 0; i < rows; i++)
	{
		int sum = 0;
		for (int j = 0; j < columns; j++)
		{
			printf_s("%d\t", array[columns * i + j]);
			sum += array[columns * i + j];
		}
		printf_s("It's sum: %d", sum);
		if (sum > max)
			max = sum;
		printf_s("\n");
	}
	printf_s("max sum = %d", max);

}


void task_1()
{
	int* array = NULL;
	int rows = 0, columns = 0;

	GetRowsColumns1(&rows, &columns);

	GetMemory(&array, &rows, &columns);

	GetArray(array, rows, columns);

	PrintArray(array, rows, columns);

	if(array)
		free(array);
}