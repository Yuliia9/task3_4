/*
* @file			task3_4.cpp
* @brief		Program choose defined quantity of numbers and show them in numeral presentation

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/

#include "stdafx.h"
#include "task3_4.h"	/*defines prototypes of used in this file functions*/
#include <stdlib.h>
#include <conio.h>
#include <time.h>

const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned char MAIN_SUCCESS = 0;

const unsigned int quantity = 14; /*the quantity of numbers needed to be shown*/


int main( )
{
	Interface();
	unsigned int number, i;
	unsigned char retCode;

	srand(time(NULL));
	for (i = 0; i < quantity; ++i)
	{
		number = rand() % 90 + 10;
		printf("%i - ", number);
		retCode = Conversion(number);
		if (retCode == ERROR)
		{
			--i;
		}
		printf("\n");
	}
		
	_getch();
	return MAIN_SUCCESS;
}

void Interface(void)
{
	printf("------------------------------------------------------------------\n");
	printf("Hi! Welcome to the genius number converter.\n");
	printf("Program done all for you, just enjoy the results ;). \n");
	printf("Program made by Yuliia Lyubchik.\n");
	printf("------------------------------------------------------------------\n\n");
}

unsigned char Conversion(int number)
{
	if (number < 10 || number > 99)
	{
		printf("Please check the number. It must be two-digit. \n");
		return ERROR;
	}

	char* numeral_unity[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char* numeral_ften[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char* numeral_tens[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	int copy;
	unsigned int digits;
	char* temp_numeral[2];
	unsigned int i , j;

	if (number >= 10 && number < 20)
	{
		temp_numeral[1] = NULL;
		digits = 1;
	}
	else
	{
		digits = 2;
	}
	j = digits - 1;

	for (i = 0, j = digits - 1; i < digits; ++i, --j)
	{
		copy = number;
		copy %= 10;
		if (digits == 1)
		{
			temp_numeral[j] = numeral_ften[copy];
			continue;
		}
		else if (i == 0)
		{
			if (copy == 0)
			{
				temp_numeral[j] = NULL;
			}
			else
			{
				temp_numeral[j] = numeral_unity[copy - 1];
			}
		}
		else
		{
			temp_numeral[j] = numeral_tens[copy - 2];
			 
		}
			number /= 10;
		}
	for (i = 0; i < digits; ++i)
	{
		if (temp_numeral[i] == NULL)
		{
			break;
		}
		printf("%s ", temp_numeral[i]);
	}
	return SUCCESS;
}

