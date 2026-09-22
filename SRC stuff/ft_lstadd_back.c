/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:46:23 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 14:32:37 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list tp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	
	tp = ft_lstlast(lst);
	tp->next = '\0';
}
