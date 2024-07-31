/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:32:35 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/08 16:32:55 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmem, size_t size)
{
	void	*result;

	if (nmem == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	result = malloc(nmem * size);
	if (!result)
	{
		return (0);
	}
	ft_bzero(result, nmem * size);
	return (result);
}
