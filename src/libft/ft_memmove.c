/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:40:50 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/08 22:41:17 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t c)
{
	unsigned char	*tempd;
	unsigned char	*temps;

	tempd = (unsigned char *)dest;
	temps = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		while (c--)
		{
			tempd[c] = temps[c];
		}
	}
	else
	{
		while (c--)
		{
			*tempd++ = *temps++;
		}
	}
	return (dest);
}
