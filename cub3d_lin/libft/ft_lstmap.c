/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:19:15 by rbeach            #+#    #+#             */
/*   Updated: 2020/05/26 14:04:38 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*oldlist;
	t_list	*newelem;
	t_list	*newlist;

	if (!lst || !f)
		return (NULL);
	oldlist = lst;
	if ((newlist = ft_lstnew(f(oldlist->content))))
	{
		oldlist = (oldlist->next);
		while (oldlist)
		{
			if (!(newelem = ft_lstnew(f(oldlist->content))))
			{
				ft_lstclear(&newlist, del);
				return (NULL);
			}
			ft_lstadd_back(&newlist, newelem);
			oldlist = oldlist->next;
		}
	}
	return (newlist);
}
