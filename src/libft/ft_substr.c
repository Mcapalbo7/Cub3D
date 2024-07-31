/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:53:58 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/08 20:49:28 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if ((start + len) >= ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		return (ptr);
	}
	while (index != len)
	{
		ptr[index] = s[index + start];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
