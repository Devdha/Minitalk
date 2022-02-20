/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:42 by dha               #+#    #+#             */
/*   Updated: 2021/11/29 14:13:51 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;

	if (lst == 0)
		return (0);
	tmp = ft_lstnew(f(lst -> content));
	lst = lst -> next;
	if (tmp == 0)
		return (0);
	ret = tmp;
	while (lst)
	{
		ft_lstadd_back(&tmp, ft_lstnew(f(lst -> content)));
		tmp = tmp -> next;
		if (tmp == 0)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		lst = lst -> next;
	}
	return (ret);
}
