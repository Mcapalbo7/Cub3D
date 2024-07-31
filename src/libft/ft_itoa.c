/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:30:37 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/11 18:39:36 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long int n)
{
	long int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	p;
	int			j;
	int			i;
	char		*res;

	i = -1;
	p = (long int)n;
	j = ft_count(p);
	res = (char *)malloc(sizeof(char) * (j + 1));
	if (!res)
		return (NULL);
	res[j--] = '\0';
	if (n < 0)
	{
		p *= -1;
		res[0] = '-';
		i = 0;
	}
	while (j > i)
	{
		((char *)res)[j--] = (p % 10) + 48;
		p /= 10;
	}
	return (res);
}
