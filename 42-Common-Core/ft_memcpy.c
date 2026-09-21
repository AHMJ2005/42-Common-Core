/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:29:37 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/20 16:34:31 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#incldue "libft.h"
void *ft_memcpy(void *dest, const void *src, int n){
      
       if (!dest && !src)
	       return 0;
       unsigned char *d = dest;
       const unsigned char 	*s = src;
       while (n--)
       {
              *d = *s;
              s++;
              d++; 
       }
       return (dest);
}
