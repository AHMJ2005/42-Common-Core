/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:37:38 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 12:18:07 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
char *ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char *ss;
	char *res;
	unsigned int i;

	ss = ft_strdup(s);
	i = 0;
	if(!res)
		return (0);
	while(i < len)
	{
		res[i] = ss[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
int main()
{
	char *a;
	a = ft_substr("ahmad riyad salme" , 5 , 5);
	printf("%s" , a);
    return 0;

}
