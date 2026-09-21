/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:52:26 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/09 15:55:52 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#incldue "libft.h"
void *ft_memmove(void *dest, const void *src, unsigned int n) {
    unsigned char *d;
    unsigned char *s;
    size_t  i;
    i = 0;
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (!dest && !src)
        return (0);
    if (d > s) {
        while (n-- > 0) {
            d[n] = s[n];
        }
    }else {
        while (i < n) {
           d[i] = s[i];
            i++;
        }
    }
    return (dest);
}