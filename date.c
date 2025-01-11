#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "date.h"
#include "general.h"
#define DATE_LEN 8

// Translates the string form of date to day, month and year in int format
void dateStrToInt(const char* date, int* day, int* month, int* year)
{
	*day = (date[0] - '0') * 10 + date[1] - '0';
	*month = (date[2] - '0') * 10 + date[3] - '0';
	*year = 0;
	for (int i = 0; i < 4; i++)
		*year += (date[i + 4] - '0') * (int)pow(10, 3 - i);
}

int checkDateValidity(const int day, const int month, const int year)
{
	const int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year < 2024 || year > 2030)
	{
		printf("\nYear should be between 2024-2030\n\n");
		return 0;
	}
	if (month < 1 || month > 12)
	{
		printf("\nMonth should be between 1-12\n\n");
		return 0;
	}
	if (day < 1 || day > daysInMonth[month - 1])
	{
		printf("\nDay in the chosen month should be between 1-%d\n\n", daysInMonth[month - 1]);
		return 0;
	}
	return 1;
}

int checkInputValidity(const char* date)
{
	if (strlen(date) < DATE_LEN)
	{
		printf("\nInput is too short\n\n");
		return 0;
	}
	for (int i = 0; i < DATE_LEN; i++)
	{
		if (date[i] - '0' < 0 || date[i] - '0' > 9)
		{
			puts("\nAll characters should be digits\n");
			return 0;
		}
	}
	return 1;
}

void initDate(Date* d)
{
	int day = 0;
	int month = 0;
	int year = 0;
	char temp[DATE_LEN + 1] = { 0 };
	do
	{
		puts("\nEnter the desired date by the the format ddmmyyyy (the year should be between 2024-2030):");
		fgets(temp, DATE_LEN + 1, stdin);
		dateStrToInt(temp, &day, &month, &year);
		clearBuffer(temp);
	} while (!checkInputValidity(temp) || !checkDateValidity(day, month, year));
	d->day = day;
	d->month = month;
	d->year = year;
}

void printDate(const Date d)
{
	printf("%d/%d/%d\n", d.day, d.month, d.year);
}