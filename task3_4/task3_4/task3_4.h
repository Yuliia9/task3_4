#ifndef TASK3_4_H_
#define TASK3_4_H_
/*
*@file		task3_4.h
*@brief		header file that defines prototypes of functions used in file task3_4.cpp
*/
#include "stdafx.h"

/*
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface(void);

/*
* @brief					Function for presenting integer number 
* @param	[in]			int number - number needed to be presented in numeral
*
*@return	unsigned char	Return ERROR if number isn't two-digit
							Return SUCCESS if number was presented in numeral 
*/
unsigned char Conversion(int number);

#endif