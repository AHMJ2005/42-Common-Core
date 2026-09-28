/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:15:54 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/28 19:11:58 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*bzero;

	if (n == 0 || size == 0)
		return (malloc(0));
	if (size > ((size_t) - 1) / n)
		return (NULL);
	bzero = (void *)malloc(n * size);
	if (!bzero)
		return (0);
	ft_bzero (bzero, n * size);
	return (bzero);
}
