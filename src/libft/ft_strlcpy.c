/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:47:45 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/08 20:47:14 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = ft_strlen(src);
	if (size != 0)
	{
		while (src[a] != '\0' && a < size -1)
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (b);
}
