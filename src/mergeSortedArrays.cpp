/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int date_checker(char *, char *);
int toint(char*, int, int);


struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if ((A == NULL) || (B == NULL))
	{
		return NULL;
	}
	int i, j, k = 0;
	struct transaction *res = (struct transaction *)calloc((ALen + BLen),sizeof(struct transaction));
	for (i = 0, j = 0, k = 0; (i < ALen) && (j < BLen);)
	{
		//printf("\nresut--%d", date_checker(A[i].date, B[j].date));
		if ((date_checker(A[i].date, B[j].date) == 0) || (date_checker(A[i].date, B[j].date) == 1))
		{
			//printf("\nA<=B");
			res[k] = A[i];
			i += 1;
			k += 1;
		}
		else
		{
			res[k] = B[j];
			j += 1;
			k += 1;
		}
	}
	for (; i < ALen;)
	{
		res[k] = A[i];
		k += 1;
		i += 1;
	}
	for (; j < BLen;)
	{
		res[k] = B[j];
		k += 1;
		j += 1;
	}
	for (i = 0; i < (ALen + BLen); i++)
	{
		printf("\n%s", res[i].date);
	}
	return res;
}

int date_checker(char *d1, char *d2)
{
	int day1, day2, month1, month2, year1, year2;
	year1 = toint(d1, 6, 9);
	year2 = toint(d2, 6, 9);
	if (year1 == year2)
	{
		month1 = toint(d1, 3, 4);
		month2 = toint(d2, 3, 4);
		if (month1 == month2)
		{
			day1 = toint(d1, 0, 1);
			day2 = toint(d2, 0, 1);
			if (day1 < day2)
			{
				return 1;
			}
			else if (day2 < day1)
			{
				return 2;
			}
			else
			{
				return 0;
			}
		}
		else if (month1 < month2)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (year1 < year2)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int toint(char *str, int begin, int end)
{
	int i, sum = 0;
	for (i = begin; i <= end; i++)
	{
		if (str[i] != '-')
		{
			sum = sum * 10 + str[i] - '0';
		}
	}
	return sum;
}



