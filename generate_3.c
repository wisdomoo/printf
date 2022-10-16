#include "main.h"

/**
 * gen_r - Generates a reversed string written to a buffer
 * @pattern: Pattern to follow to print the adress
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates an reverse string
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_r(const char *pattern, int len_p, va_list list, int *len)
{
	char *str, *s;
	int i, l = 0, w, p;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	s = va_arg(list, char *);
	if (s == 0)
		s = ")llun(";

	while (s[l])
		l++;

	str = malloc((w + l) + 1);
	if (str == 0)
		return (0);

	for (i = 0; i <= l; i++)
		str[i] = s[i];

	rev_str(str);

	app_flags(pattern, len_p, str, len, w, p);
	return (str);
}
/**
 * gen_R - Generates a Rot13 Encoded string written to a buffer
 * @pattern: Pattern to follow to print the adress
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 * @len: length
 *
 * Generates an Rot13 Encoded String
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_R(const char *pattern, int len_p, va_list list, int *len)
{
	char *str, *s;
	int i, l = 0, w, p;

	w = get_width(pattern, len_p, list);
	p = get_precision(pattern, len_p, list);
	s = va_arg(list, char *);
	if (s == 0)
		s = "(ahyy)";

	l = _strlen(s);
	str = malloc(w + l + 1);
	if (str == 0)
		return (0);

	for (i = 0; i <= l; i++)
		str[i] = s[i];

	rot13(str);
	app_flags(pattern, len_p, str, len, w, p);
	return (str);
}
/**
 * gen_per - Generates a percentage % symbol to a malloec string
 * @pattern: Not used
 * @len_p: Not used
 * @list: Not used
 * @len: Not used
 *
 * Generates a symbol %
 * the pattern inserted by parameter.
 * The pattern was already checked.
 * The next argument in list corresponds to the argument to print
 *
 * Return: A pointer to the string
 * NULL if could not allocate the memory for the operation
 */
char *gen_per(const char *pattern, int len_p, va_list list, int *len)
{
	char *str;

	(void) pattern;
	(void) len_p;
	(void) list;
	(void) len;

	str = malloc(2);
	if (str == 0)
		return (0);

	str[0] = '%';
	str[1] = '\0';
	return (str);
}
