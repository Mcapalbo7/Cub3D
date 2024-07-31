/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:24:15 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 19:01:09 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (0);
	matrix = malloc(sizeof (char *) * (ft_word(s, c) + 1));
	if (!matrix)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			matrix[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	matrix[i] = 0;
	return (matrix);
}
