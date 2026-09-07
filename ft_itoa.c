#include "libft.h"

static size_t count_digits(int n)
{
	long	temp;
	size_t	count;
	temp = n;
	if (n < 0)
		temp = -temp;

	if (n == 0)
		count = 1;
	else
	{
		count = 0;
		while (temp > 0)
		{
			temp = temp / 10;
			count++;
		}
	}
	if (n < 0)
		count++;

	return count;
}

char *ft_itoa(int n)
{
	size_t	count;
	size_t	pos;
	long	num;
	char	*str;

	num = n;
	if (n < 0)
		num = -num;
	count = count_digits(n);
	str = malloc(count + 1);
	if(str == NULL)
		return NULL;
	
	pos = count - 1;
	while (num > 0)
	{
		str[pos] = num % 10 + '0';
		num = num / 10;
		pos--;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[count] = '\0';
	return (str);
}
