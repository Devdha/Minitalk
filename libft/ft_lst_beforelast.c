/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_beforelast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:04:54 by dha               #+#    #+#             */
/*   Updated: 2022/02/05 21:34:45 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_beforelast(t_list *lst)
{
	while (lst && lst -> next && lst -> next -> next)
		lst = lst -> next;
	if (lst -> next)
		return (lst);
	else
		return (NULL);
}
