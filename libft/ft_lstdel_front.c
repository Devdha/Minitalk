/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:30:35 by dha               #+#    #+#             */
/*   Updated: 2022/02/13 15:59:29 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_front(t_list **lst)
{
	t_list	*tmp;

	if (lst == 0 || *lst == 0)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = NULL;
	*lst = tmp;
}
