/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlatt <hlatt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 11:04:58 by hlatt             #+#    #+#             */
/*   Updated: 2026/08/27 11:54:05 by hlatt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_length;
	char	*dup;

	s_length = ft_strlen(s);
	dup = malloc(s_length + 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, s_length);
	return (dup);
}
