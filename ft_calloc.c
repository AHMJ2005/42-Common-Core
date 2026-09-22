/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:15:54 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 10:16:14 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void    *ft_calloc(size_t n, size_t size) {
    void	*bzero;

    bzero = (void *)malloc(n * size);
    if (!bzero)
        return (0);
    ft_bzero (bzero, n * size);
    return (bzero);
}
