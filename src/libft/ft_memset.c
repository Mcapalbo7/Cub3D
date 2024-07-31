/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:02:02 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/10 18:34:35 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t count)
{
	size_t	c;
	char	*char_dest;

	c = 0;
	char_dest = dest;
	while (count > c)
	{
		char_dest[c] = val;
		c++;
	}
	return (dest);
}
