#include "main.h"

/**
 * app_flags - Applies the flags found in a pattern string
 * @pattern: Pattern that defines which flags should apply to the format
 * @len_p: Length of the pattern
 * @buffer: Buffer where to apply the flags
 * @len_b: Length of the buffer
 * @wi: Value for width field
 * @pr: Value for precision field
 *
 * Description: Applies the flags found on a string into a buffer that already
 * has a wroted string in it.
 * The flags differ depending on conversion specifier.
 *
 * Return: Nothing
 */
void app_flags(const char *pattern, int len_p, char *buffer, int *len_b, int wi, int pr)
{
	(void) wi;
	*len_b = pattern[len_p - 1] == 'c' ? *len_b : _strlen(buffer);
	/* Applies precision */
	if (pattern[len_p - 1] != 'c' && pattern[len_p - 1] != 'p')
		*len_b = app_precision(pattern, len_p, buffer, pr);
	/* Applies width */
	if (wi && wi > *len_b)
		*len_b = app_width(buffer, *len_b, wi);
	if (pattern[len_p - 1] != 'c')
	{
		/* Applies hash */
		*len_b = app_hash(pattern, len_p, buffer);
		/* Applies plus and space */
		*len_b = app_plus_space(pattern, len_p, buffer);
	}

/* Applies minus and 0 */
	/* if (p > 0) */
	/* {} */
}

/**
 * app_precision - Applies the precision field to the buffer
 * @pattern: Pattern where defines the flags
 * @len_p: Length of the pattern
 * @buffer: Buffer where to apply the precision length
 * @pr: Precision value to apply
 *
 * Return: The final length of the buffer
 */
int app_precision(const char *pattern, int len_p, char *buffer, int pr)
{
	int i, j, stop, len_buff = _strlen(buffer), val;
	char cs = pattern[len_p - 1];

	/* If is string, the precision truncates the length of the string*/
	if (cs == 's')
	{
		if (pr < len_buff)
			buffer[pr] = '\0', val = pr;
		else
			val = len_buff;
	}
	else if (cs == 'd' || cs == 'i' || cs == 'u' ||
			 cs == 'o' || cs == 'x' || cs == 'X')
	{
		if (pr == 0 && check_flag(pattern, len_p, '.') && buffer[0] == '0'
			&& len_buff == 1)
		{
			buffer[0] = '\0';
			return (0);
		}
		if (pr > len_buff)
		{
			stop = buffer[0] == '-' ? 1 : 0;
			for (i = pr + stop, j = len_buff; i >= stop; i--, j--)
				buffer[i] = j < stop ? '0' : buffer[j];
			val = (pr + stop);
		}
		else
		{
			val = (len_buff);
		}
	}

	return (val);
}

/**
 * app_width - Applies the width field to the buffer
 * @buffer: Buffer to modify
 * @len_b: Length of the buffer
 * @wi: Width to apply
 *
 * Return: the final length of the string
 */
int app_width(char *buffer, int len_b, int wi)
{
	int i, mov = wi - len_b;

	for (i = wi; i >= 0; i--)
		buffer[i] = (i < mov ? ' ' : buffer[i - (mov)]);

	return (wi);
}

/**
 * check_flag - Checks if a flag exists in a pattern
 * @pattern: Pattern where to check the flag
 * @len_p: Length of the pattern
 * @flag: Flag to be checked
 *
 * Return: 1 if the flag exists
 * 0 otherwise
 */
int check_flag(const char *pattern, int len_p, char flag)
{
	int i;

	for (i = 0; i < len_p; i++)
	{
		if (pattern[i] == flag)
			return (1);
	}
	return (0);
}
