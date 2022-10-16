#include "main.h"

/**
 * gen_x - Generates an hexadecimal conversion written to a string in lowercase
 * @pattern: Pattern to follow to print the hexadecimal
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates a hexadecimal written to a string, following
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_x(const char *pattern, int len_p, va_list list, int *len)
{
	int w, p;
	unsigned long int i = 0, base = 16, n;
	char *str;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	n = get_param_u(pattern, len_p, list);
	/* Width + precision + length of number + # */
	if (n != 0)
		str = malloc((w + p + blen(n, base) + 2) + 1);
	else
		str = malloc((w + p + 1) + 1), str[i] = '0', i++;
	if (str == 0)
		return (0);

	for (; n > 0; i++)
	{
		if ((n % base) < 10)
			str[i] = (n % base) + '0';
		else
			str[i] = (n % base) + 'W';
		n = n / base;
	}
	str[i] = '\0';
	rev_str(str);

	app_flags(pattern, len_p, str, len, w, p);
	return (str);
}
/**
 * gen_X - Generates an hexadecimal conversion written to a string in Uppercase
 * @pattern: Pattern to follow to print the hexadecimal
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates a hexadecimal written to a string, following
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_X(const char *pattern, int len_p, va_list list, int *len)
{
	int w, p;
	unsigned long int i = 0, base = 16, n;
	char *str;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	n = get_param_u(pattern, len_p, list);
	/* Width + precision + length of number + # */
	if (n != 0)
		str = malloc((w + p + blen(n, base) + 2) + 1);
	else
		str = malloc((w + p + 1) + 1), str[i] = '0', i++;
	if (str == 0)
		return (0);

	for (; n > 0; i++)
	{
		if ((n % base) < 10)
			str[i] = (n % base) + '0';
		else
			str[i] = (n % base) + '7';
		n = n / base;
	}
	str[i] = '\0';
	rev_str(str);

	app_flags(pattern, len_p, str, len, w, p);
	return (str);
}
/**
 * gen_p - Generates an hexadecimal conversion of an adress written to a string
 * @pattern: Pattern to follow to print the adress
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates a hexadecimal written to a string, following
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_p(const char *pattern, int len_p, va_list list, int *len)
{
	int w;
	unsigned long int i = 0, j, base = 16, n;
	char *str, *p;

	w = get_width(pattern, len_p, list);
	p =  va_arg(list, void *);
	if (p == 0)
	{
		p = "(nil)";
		str = malloc(w + 6);
		if (str == 0)
			return (0);
		for (j = 0; j <= 5; j++)
			str[j] = p[j];
		app_flags(pattern, len_p, str, len, w, 0);
		return (str);
	}
	n = (unsigned long int)p;
	if (n != 0)
		str = malloc(w + blen(n, base) + 1 + 2);
	else
		str = malloc(w + 1 + 1 + 2), str[i] = '0', i++;
	if (str == 0)
		return (0);

	for (; n > 0; i++)
	{
		if ((n % base) < 10)
			str[i] = (n % base) + '0';
		else
			str[i] = (n % base) + 'W';
		n = n / base;
	}
	str[i] = 'x', str[i + 1] = '0';
	str[i + 2] = '\0';
	rev_str(str);
	app_flags(pattern, len_p, str, len, w, 0);
	return (str);
}
/**
 * gen_u - Generates an unsigned number conversion written to a string
 * @pattern: Pattern to follow to print the adress
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates an unsigned int written to a string, following
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_u(const char *pattern, int len_p, va_list list, int *len)
{
	int len_int, w, p;
	unsigned long int number, base = 10;
	char *str;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	number = get_param_u(pattern, len_p, list);
	len_int = blen(number, base);
	/* Width + precision + length of number + sign */
	str = malloc((w + p + len_int + 1) + 1);
	if (str == NULL)
		return (0);

	print_number_str_u(number, str);

	app_flags(pattern, len_p, str, len, w, p);
	return (str);
}
/**
 * gen_S - Generates an string with no special characters written to a buffer
 * @pattern: Pattern to follow to print the adress
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates an string with no special characters
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Non printable characters (0 < ASCII < 32 or >= 127) are printed this way:
 * \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_S(const char *pattern, int len_p, va_list list, int *len)
{
	int w, p;
	char *str, *s, *hx;
	int i, j, l, count = 0;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	s = va_arg(list, char *);
	if (s == 0)
		s = "(null)";
	l = _strlen(s);
	for (i = 0; i <= l; i++)
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
			count += 1;
	l = l + (count * 3);

	str = malloc((w + l) + 1);
	if (str == 0)
		return (0);

	for (i = 0, j = 0; s[j] != 0; i++, j++)
	{
		if ((s[j] > 0 && s[j] < 32) || s[j] >= 127)
		{
			hx = hexS(s[j]);
			str[i] = '\\', i++;
			str[i] = 'x', i++;
			str[i] = hx[0], i++;
			str[i] = hx[1];
			free(hx);
		}
		else
		{
			str[i] = s[j];
		}
	}
	str[i] = '\0';

	app_flags(pattern, len_p, str, len, w, p);
	return (str);
}
