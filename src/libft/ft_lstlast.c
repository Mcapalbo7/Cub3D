/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:33:03 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/07 20:38:26 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lista)
{
	if (!lista)
	{
		return (NULL);
	}
	while (lista->next != NULL)
	{
		lista = lista->next;
	}
	return (lista);
}
