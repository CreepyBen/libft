#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen(s);
	i = 0;
	str = malloc(len + 1);
	if(str == NULL)
		return (NULL);
	while(s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

#include <stdio.h>

static char	to_upper(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

int	main(void)
{
	char	*result;
	char	*original;

	original = "hello";
	result = ft_strmapi(original, to_upper);

	printf("original: %s\n", original);
	printf("result:   %s\n", result);

	free(result);
}