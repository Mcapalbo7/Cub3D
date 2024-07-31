/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:12:59 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/10 18:46:18 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = (t_list *)malloc(sizeof (t_list));
	if (!n)
	{
		return (NULL);
	}
	n->content = content;
	n->next = NULL;
	return (n);
}
