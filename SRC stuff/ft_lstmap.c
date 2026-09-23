/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:50:11 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/23 14:52:49 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_list;
	t_list	*n_node;
	void	*content;

	res_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		N_node = ft_lstnew(content);
		if (!N_node)
		{
			del(content);
			ft_lstclear(&res_list, del);
			return (NULL);
		}
		ft_lstadd_back(&res_list, N_node);
		lst = lst->next;
	}
	return (res_list);
}
