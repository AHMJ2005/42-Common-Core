/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:25:09 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 10:25:11 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
    size_t				i;
    unsigned char		*d;
    const unsigned char	*s;

    if (!dest && !src)
        return (0);
    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    if (d > s)
    {
        while (n > 0)
        {
            d[n - 1] = s[n - 1];
            n--;
        }
    }
    else
    {
        i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (dest);
}
