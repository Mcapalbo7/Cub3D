/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:04:35 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/10 16:54:45 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int count)
{
	size_t	a;

	a = 1 + ft_strlen((char *) str);
	while (a-- > 0)
	{
		if (str[a] == (char)count)
		{
			return ((char *)(str + a));
		}
	}
	return (NULL);
}
