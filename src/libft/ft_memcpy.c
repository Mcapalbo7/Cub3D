/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:30:37 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/09 18:39:03 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t c)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			l;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	l = 0;
	while (c > l)
	{
		d[l] = s[l];
		d++;
		s++;
		c--;
	}
	return (dest);
}
