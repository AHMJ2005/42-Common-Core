/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:18:59 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 10:19:02 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t	i;
    size_t	little_len;

    if (*little == '\0')
        return ((char *)big);
    little_len = ft_strlen(little);
    i = 0;
    while (big[i] != '\0' && (i + little_len) <= len)
    {
        if (big[i] == little[0])
        {
            if (ft_strncmp(&big[i], little, little_len) == 0)
                return ((char *)&big[i]);
        }
        i++;
    }
    return (0);
}
