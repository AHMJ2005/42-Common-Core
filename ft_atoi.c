/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:12:27 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 10:12:30 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int ft_atoi(const char *nptr) {
    int i;
    int res;
    int sign;
    int count;

    i = 0;
    sign = 1;
    count = 1;
    res = 0;
    while (nptr[i] == ' ') {
        if (nptr[i] <= '0' && nptr[i] >= '9')
            return (0);

        i++;
    }


    while (nptr[i] != '\0') {
        if (nptr[i] == '-') {
            count++;
        }
        else if (nptr[i] == '+') {
            count  ++;
            sign = 1;
        }
        i++;
    }

    if (count > 1)
        return (0);

    while (nptr[i] >= '0' && nptr[i] <= '9') {
        res = res * 10 + nptr[i] - 48;
        i++;
    }
    return (sign * res);
}
