/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:19:45 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 14:20:38 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	s_list a;

	a = (t_list *)malloc(sizeof(t_list) * 1);
	if (!a)
		return (0);

	a->content = *content;
	a->next = 0;
	return (a);
}
