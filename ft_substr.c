/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:47:19 by hlatt             #+#    #+#             */
/*   Updated: 2026/08/31 13:01:00 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	if (len > 0)
		ft_strlcpy(substr, s + start, len + 1);
	else
		substr[0] = '\0';
	return (substr);
}
