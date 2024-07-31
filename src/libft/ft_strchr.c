/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:30:50 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/10 16:51:03 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int count)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == (char)count)
		{
			return ((char *)(str + a));
		}
		a++;
	}
	if (count == '\0')
	{
		return ((char *)(str + a));
	}
	return (NULL);
}
