/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:21:31 by hlatt             #+#    #+#             */
/*   Updated: 2026/08/30 23:22:35 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}

#include <stdio.h>

int main(void)
{
	char *result;

	result = ft_strtrim("   Hello, World!   ", " ");
	printf("[%s]\n", result); // [Hello, World!]
	free(result);

	result = ft_strtrim("###42Born2Code###", "#");
	printf("[%s]\n", result); // [42Born2Code]
	free(result);

	result = ft_strtrim("xxxx", "x");
	printf("[%s]\n", result); // []
	free(result);

	return (0);
}