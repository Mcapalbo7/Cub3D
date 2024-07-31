/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:06:32 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/09 20:27:01 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	c;

	if (!s1 || !s2)
		return (0);
	i = 0;
	c = 0;
	newstr = malloc((ft_strlen(s1) + ft_strlen(s2)+1) * sizeof(char));
	if (!newstr)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		newstr[i] = s2[c];
		i++;
		c++;
	}
	newstr[i] = '\0';
	return (newstr);
}
