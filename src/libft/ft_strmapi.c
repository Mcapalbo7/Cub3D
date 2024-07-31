/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:30 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/09 18:30:26 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstring;
	size_t	index;

	if (!s || !f)
	{
		return (NULL);
	}
	index = 0;
	newstring = (char *)malloc(ft_strlen(s) + 1);
	if (!newstring)
	{
		return (NULL);
	}
	while (s[index])
	{
		newstring[index] = f(index, s[index]);
		index++;
	}
	newstring[index] = '\0';
	return (newstring);
}
