/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:12:43 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 10:12:45 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void *ft_memchr(const void *s, int c, size_t n) {
    const unsigned char *p;
    size_t i;

    i = 0;
    p = (const unsigned char*)s;
    while (i < n) {
        if (p[i] == (unsigned char)c)
            return ((void *)&p[i]);
        i++;
    }
    return 0;
}
