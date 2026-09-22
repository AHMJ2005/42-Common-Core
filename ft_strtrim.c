/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:21:33 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 13:06:49 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int check(char a, char *s)
{
	int i;
	int b = 0;

	i = 0;
	while(s[i] != '\0')
	{
		if (a == s[i])
			b = 1;
		else 
			b = 0;
		i++;
	}
	return (b);
}
char *ft_strtrim(char const *s1, char const *set)
{
	char *res;
	char *s1U;
	char *setU;
	unsigned int i;
	int a;
	int size;

	a = 0;
	s1U = ft_strdup(s1);
	setU = ft_strdup(set);
	size = ft_strlen(s1) - ft_strlen(set);
	res = (char *)malloc(size + 1);
	i = 0;
	if (!res)
		return 0;
	while (s1U[i++] != '\0')
	{
		if(!check(s1U[i] , setU))
		{
			res[a] = s1U[i];
			a++;
		}
	}
	res[i] = '\0';
	return res;
}
int main()
{
	char *a;
	a = ft_strtrim("::::ahm:::ad" , ":");
	printf("%s" , a);
	return 0;
}
