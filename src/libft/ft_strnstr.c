/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:44:39 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/08 20:14:57 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	if (to_find[i] == '\0')
	{
		return ((char *)str);
	}
	while (i < len && str[a] != '\0')
	{
		while (str[a + i] == to_find[i] && str[a + i] != '\0' && (a + i) < len)
		{
			i++;
		}
		if (to_find[i] == '\0')
		{
			return ((char *)str + a);
		}
		a++;
		i = 0;
	}
	return (0);
}
