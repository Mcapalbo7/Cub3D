/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:44:21 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/08 22:48:39 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	dstlen;

	if (!src && !dst)
	{
		return (0);
	}
	if (s == 0)
	{
		return (ft_strlen(src));
	}
	dstlen = ft_strlen(dst);
	if (s <= dstlen)
	{
		return (ft_strlen(src) + s);
	}
	ft_strlcpy((dst + dstlen), src, (s - dstlen));
	return (dstlen + ft_strlen(src));
}
