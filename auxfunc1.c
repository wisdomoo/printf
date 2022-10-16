#include "main.h"


/**
 * print_number_str - Prints a number to the string inserted
 * @n: Number to print
 * @str: String where to print the number
 *
 * Return: Nothing
 */
void print_number_str(long int n, char *str)
{
	int i = 0;
	int sign;
	unsigned long int d = 1;

	n < 0 ? *str = '-' : 1;
	sign = n < 0 ? 1 : 0;
	n *= n < 0 ? -1 : 1;
	while (n / d > 9)
		d *= 10;

	while (d >= 1)
	{
		*(str + i + sign) = (n / d + '0');
		n %= d;
		d /= 10;
		i++;
	}
	*(str + i + sign) = '\0';
}
/**
 * print_number_str_u - Prints an unsigned number to the string inserted
 * @n: Number to print
 * @str: String where to print the number
 *
 * Return: Nothing
 */
void print_number_str_u(unsigned long int n, char *str)
{
	int i = 0;
	int s = 0;
	unsigned long int d = 1;

	while (n / d > 9)
		d *= 10;
	while (d >= 1)
	{
		*(str + i + s) = (n / d + '0');
		n %= d;
		d /= 10;
		i++;
	}
	*(str + i + s) = '\0';
}
/**
 * rev_str - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
void rev_str(char *s)
{
	int i = 0, j = 0, l;
	char tmp;

	while (s[i])
		i++;
	l = i / 2, i = i - 1;
	while (i >= l)
	{
		tmp  = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i--, j++;
	}
}
/**
 * blen - obtains length of number in base
 *
 * @n: number
 * @base: base of number
 *
 * Return: length of number
 */
int blen(unsigned long int n, unsigned long int base)
{
	unsigned long int i, neg = 0;

	for (i = 0; n > 0; i++)
		n = n / base;
	return (i + neg);
}
/**
 * blen10 - obtains length of number in base
 *
 * @n: number
 * @base: base of number
 *
 * Return: length of number (+1 if negative)
 */
int blen10(long int n, long int base)
{
	long int i, neg = 0;

	if (n < 0)
		n *= -1, neg = 1;
	for (i = 0; n > 0; i++)
		n = n / base;
	return (i + neg);
}
