#include "main.h"
/**
 * gen_c - Generates a character written to a string
 * @pattern: Pattern to follow to print the character
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates a character to a string, following
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_c(const char *pattern, int len_p, va_list list, int *len)
{
	char *str;
	unsigned char c;
	int w;

	w = get_width(pattern, len_p, list);
	c = (unsigned char)va_arg(list, int);
	/* Width + char */
	str = malloc(sizeof(char) * (2 + w));

	if (str == 0)
		return (0);

	str[0] = c;
	str[1] = '\0';
	*len = 1;
	app_flags(pattern, len_p, str, len, w, 0);
	return (str);
}
/**
 * gen_s - Generates a string written to a malloc buffer
 * @pattern: Pattern to follow to print the string
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates a character to a string, following
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_s(const char *pattern, int len_p, va_list list, int *len)
{
	char *str, *s;
	int i, l = 0, w, p;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	s = va_arg(list, char *);
	if (s == 0)
		s = "(null)";

	while (s[l])
		l++;
	/* Width + length of the string */
	str = malloc((w + l) + 1);
	if (str == 0)
		return (0);

	for (i = 0; i <= l; i++)
		str[i] = s[i];
	app_flags(pattern, len_p, str, len, w, p);
	return (str);
}
/**
 * gen_i - Generates an integer written to a string
 * @pattern: Pattern to follow to print the integer
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates an integer wrote to a string, following
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_i(const char *pattern, int len_p, va_list list, int *len)
{
	int len_int, w, p;
	long int number, base = 10;
	char *str;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	number = get_param(pattern, len_p, list);

	len_int = blen10(number, base);
	/* Width + precision + length of integer + sign */
	str = malloc((w + p + len_int + 1) + 1);
	if (str == NULL)
		return (0);

	print_number_str(number, str);
	app_flags(pattern, len_p, str, len, w, p);
	return (str);

}
/**
 * gen_o - Generates an octal conversion written to a string
 * @pattern: Pattern to follow to print the octal
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates an octal written to a string, following
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_o(const char *pattern, int len_p, va_list list, int *len)
{
	int w, p;
	unsigned long int i = 0, base = 8, n;
	char *str;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	n = get_param_u(pattern, len_p, list);
	/* Width + precision + length of number + # */
	if (n != 0)
		str = malloc((w + p + blen(n, base) + 1) + 1);
	else
		str = malloc((w + p + 1) + 1), str[i] = '0', i++;

	if (str == 0)
		return (0);

	for (; n > 0; i++)
	{
		str[i] = (n % base) + '0';
		n = n / base;
	}
	str[i] = '\0';
	rev_str(str);

	app_flags(pattern, len_p, str, len, w, p);
	return (str);
}
/**
 * gen_b - Generates an binary conversion written to a string
 * @pattern: Pattern to follow to print the binary
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates an binary written to a string, following
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_b(const char *pattern, int len_p, va_list list, int *len)
{
	int w, p;
	unsigned long int i = 0, base = 2, n;
	char *str;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	n = get_param_u(pattern, len_p, list);
	/* Width + precision + length of number */
	if (n != 0)
		str = malloc((w + p + blen(n, base)) + 1);
	else
		str = malloc((w + p + 1) + 1), str[i] = '0', i++;

	if (str == 0)
		return (0);

	for (; n > 0; i++)
	{
		str[i] = (n % base) + '0';
		n = n / base;
	}
	str[i] = '\0';
	rev_str(str);

	app_flags(pattern, len_p, str, len, w, p);
	return (str);
}
