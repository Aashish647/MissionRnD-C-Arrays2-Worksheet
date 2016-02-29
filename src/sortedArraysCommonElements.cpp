/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int date_check(char *t, char *s);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if ((A == NULL) || (B == NULL))
	{
		return NULL;
	}
	struct transaction *res = NULL;
	int i, j, m = 0, index = 0;
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			if (date_check(A[i].date, B[j].date))
			{
				index += 1;
				res = (struct transaction *)realloc(res, index*sizeof(struct transaction));
				res[index - 1] = B[j];
			}
		}
	}
	return res;
}
int date_check(char *t, char *s)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (t[i] != s[i])
		{
			return 0;
		}
	}
	return 1;
}
