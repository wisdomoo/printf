#include "main.h"
/**
 * app_hash - Applies the hash flag to the buffer
 * @pattern: Pattern to follow
 * @len_p: Lenght of patter
 * @buffer: Buffer where to made the changes
 *
 * Return: The final length of the buffer
 */
int app_hash(const char *pattern, int len_p, char *buffer)
{
	int i, len_buff = _strlen(buffer), start, per;
	char cs = pattern[len_p - 1];

	if ((cs == 'o' || cs == 'x' || cs == 'X') && check_flag(pattern, len_p, '#'))
	{
		per = len_buff - effective_length(buffer);
		if (cs == 'o' && (per >= 1 || (per == 0 && buffer[per] == '0')))
		{
			buffer[per] != '0' ? buffer[per - 1] = '0' : 1;
		}
		else if (per >= 2 || (per == 0 && buffer[per] == '0'))
		{
			if (per >= 2)
				buffer[per - 1] = cs, buffer[per - 2] = '0';
		}
		else
		{
			start = (cs == 'o' ? 1 : 2);
			for (i = len_buff + start; i >= 0; i--)
			{
				if (i == 0)
					buffer[i] = '0';
				else if (i == 1 && cs != 'o')
					buffer[i] = cs;
				else
					buffer[i] = buffer[i - start];
			}
		}
	}
	return (_strlen(buffer));
}

/**
 * app_plus_space - Applies the plus or space flag to the biffer
 * @pattern: Pattern to follow
 * @len_p: Length of the pattern
 * @buffer: Buffer where to made the changes
 *
 * Return: The final length of the buffer
 */
int app_plus_space(const char *pattern, int len_p, char *buffer)
{
	int i, len_buff = _strlen(buffer), per;
	char cs = pattern[len_p - 1];

	if (cs == 'd' || cs == 'i')
	{
		per = len_buff - effective_length(buffer);
		if (check_flag(pattern, len_p, '+'))
		{
			if (buffer[per] == '-')
				return (len_buff);
			if (per >= 1)
				buffer[per - 1] = '+';
			else
				for (i = len_buff + 1; i >= 0; i--)
					buffer[i] = (i == 0 ? '+' : buffer[i - 1]);
		}
		else if (check_flag(pattern, len_p, ' '))
		{
			if (buffer[per] == '-')
				return (len_buff);
			if (per >= 1)
				buffer[per - 1] = ' ';
			else
				for (i = len_buff + 1; i >= 0; i--)
					buffer[i] = (i == 0 ? ' ' : buffer[i - 1]);
		}
	}
	return (_strlen(buffer));
}
