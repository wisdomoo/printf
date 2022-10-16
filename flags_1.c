#include "main.h"

/**
 * get_width - Obtains the width for the corresponding format
 * @pattern: Pattern where to search the width value
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 *
 * Description: Check if exist a width to apply to the format and return it's
 * value
 * Check if the width is explicit in the pattern
 * If not, get the next argument of the list that refer the corresponding value
 *
 * Return: 0 if did not find a value for width field.
 * A positive number otherwise
 */
unsigned int get_width(const char *pattern, int len_p, va_list list)
{
	char actual;
	int i, zerocheck = 0, pointcheck = 0, _isdig = 0;
	unsigned int width = 0;

	for (i = 0; i < len_p; i++)
	{
		actual = pattern[i];
		_isdig = actual < '1' || actual > '9' ? 0 : 1;
		if (!zerocheck && (_isdig || actual == '*'))
			zerocheck = 1;
		if (!pointcheck && actual == '.')
			pointcheck = 1;
		if (actual == '*' && zerocheck && !pointcheck)
		{
			width = va_arg(list, unsigned int);
			break;
		}
		if ((_isdig || actual == '0') && zerocheck && !pointcheck)
		{
			width *= 10;
			width += actual - '0';
		}
		if (pointcheck)
			break;
	}
	return (width);
}

/**
 * get_precision - Obtains the precision for the corresponding format
 * @pattern: Pattern where to search the precision value
 * @len_p: Length of the pattern
 * @list: list of arguments of the pattern
 *
 * Description: Check if exist a precision to apply to the format and return
 * it's value
 * Check if the precision is explicit in the pattern
 * If not, get the next argument of the list that refer the corresponding value
 *
 * Return: 0 if did not find a value for precision field.
 * A positive number otherwise
 */
unsigned int get_precision(const char *pattern, int len_p, va_list list)
{
	char actual;
	int i, pointcheck = 0, _isdig = 0;
	unsigned int prec = 0;

	for (i = 0; i < len_p; i++)
	{
		actual = pattern[i];
		_isdig = actual < '0' || actual > '9' ? 0 : 1;

		if (!pointcheck && actual == '.')
			pointcheck = 1;

		if (actual == '*' && pointcheck)
		{
			prec = va_arg(list, unsigned int);
			break;
		}
		if (_isdig && pointcheck)
		{
			prec *= 10;
			prec += actual - '0';
		}
		if (pointcheck && !_isdig && actual != '.')
			break;
	}
	return (prec);
}

/**
 * get_param - Returns the parameter with the cast
 * @pattern: Pattern where to search the precision value
 * @len_p: Length of the pattern
 * @list: List of arguments of the pattern
 *
 * Description: Returns the paramater with the corresponding cast
 * If there's a length field on the pattern, make the cast to the corresponding
 * type.
 *
 * Return: The parameter with the corresponfing cast.
 */
long int get_param(const char *pattern, int len_p, va_list list)
{
	char l_field;
	long int param;

	l_field = pattern[len_p - 2];
	switch (l_field)
	{
	case 'h':
		param = (short int)va_arg(list, int);
		break;
	case 'l':
		param = (long int)va_arg(list, long int);
		break;
	default:
		param = va_arg(list, int);
		break;
	}

	return (param);
}

/**
 * get_param_u - Returns the parameter with the unsigned cast
 * @pattern: Pattern where to search the precision value
 * @len_p: Length of the pattern
 * @list: List of arguments of the pattern
 *
 * Description: Returns the paramater with the corresponding cast
 * If there's a length field on the pattern, make the cast to the corresponding
 * type. Always return an unsigned cast
 *
 * Return: The parameter with the corresponfing cast.
 */
unsigned long int get_param_u(const char *pattern, int len_p, va_list list)
{
	char l_field;
	unsigned long int param;

	l_field = pattern[len_p - 2];
	switch (l_field)
	{
	case 'h':
		param = (unsigned short int)va_arg(list, unsigned int);
		break;
	case 'l':
		param = (unsigned long int)va_arg(list, unsigned long int);
		break;
	default:
		param = (unsigned int)va_arg(list, unsigned int);
		break;
	}

	return (param);
}
