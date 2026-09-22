/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:19:06 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 10:19:14 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c) {
    int i;
    int len;

    len = ft_strlen(s);
    i = len;
    while (i >= 0) {
        if (s[i] == (char)c) {
            return (char *)&s[i];
        }
        i--;
    }
    return 0;
}
