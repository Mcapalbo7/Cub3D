/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:50:22 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/09 18:44:49 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (!list)
	{
		return ;
	}
	if (!*list)
	{
		*list = new;
	}
	else
	{
		last = ft_lstlast (*list);
		last->next = new;
	}
}
