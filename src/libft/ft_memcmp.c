/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:49 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/08 20:23:44 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*stringa1;
	unsigned char	*stringa2;

	a = 0;
	stringa1 = (unsigned char *)s1;
	stringa2 = (unsigned char *)s2;
	while (a < n)
	{
		if (stringa1[a] != stringa2[a])
		{
			return (stringa1[a] - stringa2[a]);
		}
		a++;
	}
	return (0);
}
