/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:39:41 by dha               #+#    #+#             */
/*   Updated: 2022/02/05 21:22:26 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_back(t_list **lst)
{
	t_list	*tmp;

	if (lst == 0 || *lst == 0)
		return ;
	tmp = ft_lst_beforelast(*lst);
	if (tmp -> next)
		tmp -> next = NULL;
	else
		*lst = NULL;
}
