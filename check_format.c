#include "main.h"
/**
 * whichflag - checks for flag type of a char
 *
 * @formspec: character
 *
 * Return: 1 = flag, 2 = width, 3 = precision, 4 = length
 */
int whichflag(char formspec)
{
	char *flags = " 0+-#";
	char *width = "123456789*";
	char *precision = ".";
	char *leng = "lh";
	int i, flagnumber = 0;

	for (i = 0; flags[i] != 0; i++)
		if (formspec == flags[i])
			return (1);

	for (i = 0; width[i] != 0; i++)
		if (formspec == width[i])
			return (2);

	if (formspec == precision[0])
		return (3);

	for (i = 0; leng[i] != 0; i++)
		if (formspec == leng[i])
			return (4);
	/* 1 = flag, 2 = width, 3 = precision, 4 = length */
	return (flagnumber);
}
/**
 * check_order - checks if order of flags is correct
 *
 * @formspec: flags %+50d format
 * @j: length of format
 *
 * Return: 1 if correct, 0 if incorrect
 */
int check_order(const char *formspec, int j)
{
	int h, flagtmp1, flagtmp2;

	for (h = 0; h < j - 2; h++)
	{
		flagtmp1 = whichflag(formspec[h]), flagtmp2 = whichflag(formspec[h + 1]);
		if (flagtmp1 == 2 && (flagtmp2 == 1 && formspec[h + 1] != '0'))
			return (0);
		if (flagtmp1 == 3 && (flagtmp2 == 1 && formspec[h + 1] != '0'))
			return (0);
		if (flagtmp1 == 4 && flagtmp2 >= 0)
			return (0);
	}
	return (1);
}
/**
 * check_format - checks if a flag format is correct
 *
 * @formspec: flags %+50d format
 * @j: length of format
 *
 * Return: 1 if correct, 0 if incorrect
 */
int check_format(const char *formspec, int j)
{
	int h, k, z, zeropass = 0, star1 = 1, star2 = 1;
	checkstr flagcheck[] = {
		{'c', ""},
		{'s', ""}, {'S', ""},
		{'d', ""}, {'i', ""},
		{'u', ""}, {'b', ""},
		{'o', ""}, {'x', ""}, {'X', ""},
		{'p', ""}, {'r', ""}, {'R', ""}, {'%', ""}
	};
	/* Check Specifier and if flag cannot go with it*/
	for (h = 0; h < 13; h++)
		if (formspec[j - 1] == flagcheck[h].flag)
			break;
	for (k = 0; k < j; k++)
	{
		for (z = 0; flagcheck[h].flagnot[z] != 0; z++)
		{
			if (whichflag(formspec[k]) == 2 || whichflag(formspec[k]) == 3)
				zeropass = 1;
			if ((formspec[k] == 2 || formspec[k] == '0') && star1 == 0)
				return (0);
			if (formspec[k] == '*' && (star1 == 0 || star2 == 0))
				return (0);
			if ((whichflag(formspec[k]) == 2 || formspec[k] == '0') && star1 == 0)
				return (0);
			if (formspec[k] == flagcheck[h].flagnot[z] && zeropass == 0)
				return (0);
			if (whichflag(formspec[k]) == 2 && formspec[k] == '*')
				star1 = 0;
			if ((whichflag(formspec[k]) == 2 && formspec[k] != '*')
			    || (formspec[k] == '0' && zeropass == 1))
				star2 = 0;
			if (whichflag(formspec[k]) == 3)
				star1 = 1, star2 = 1;
		}
	}
	return (check_order(formspec, j));
}
