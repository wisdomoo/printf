#include "main.h"

/**
 * hexS - Makes hexadecimal conversion for non printable characters
 * @n: Number to conver
 *
 * Return: Pointer with conversion
 */
char *hexS(int n)
{
	int i = 0;
	char *r;

	if (n > 255)
		return (0);

	r = malloc(3);
	if (r == 0)
		return (0);

	if (n == 0)
		r[0] = '0', r[1] = '0';

	if (n < 16)
		r[1] = '0';
	for (; n > 0; i++)
	{
		if ((n % 16) < 10)
			r[i] = (n % 16) + '0';
		else
			r[i] = (n % 16) + '7';
		n = n / 16;
	}
	r[2] = '\0';
	rev_str(r);
	return (r);
}
/**
 * rot13 - encodes string to rot13
 * @s: string to encode
 *
 * Return: pointer to string encoded
 */
char *rot13(char *s)
{
	int i, j;
	char rot13a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (j = 0; s[j] != 0; j++)
	{
		for (i = 0; i < 52; i++)
		{
			if (s[j] == rot13a[i])
			{
				s[j] = rot13b[i];
				break;
			}
		}
	}
	return (s);
}

/**
 * effective_length - Computes the real length without spaces
 * @buffer: Buffer to determine the real length
 *
 * Return: The effective length of the buffer
 */
int effective_length(char *buffer)
{
	int i, eff;

	i = 0, eff = 0;
	while (buffer[i])
	{
		if (buffer[i] != ' ')
			eff++;
		i++;
	}

	return (eff);
}
