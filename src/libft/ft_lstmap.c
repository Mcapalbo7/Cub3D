/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:17:49 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/09 20:22:13 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void(*del)(void *))
{
	t_list	*new;
	t_list	*now;

	if (!lst || !f)
		return (NULL);
	now = ft_lstnew(f(lst->content));
	if (!now)
		return (NULL);
	new = now;
	lst = lst->next;
	while (lst != NULL)
	{
		now->next = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new, del);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		now = now->next;
		lst = lst->next;
	}
	return (new);
}
