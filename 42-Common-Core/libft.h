/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 14:05:25 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/20 14:16:30 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_H
#define LIBFT_H
int ft_isalpha(int c);
int ft_isdigit(int c);
void *ft_memcpy(void *dest, const void *src, int n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int	ft_strncmp(char *s1, char *s2, unsigned int n);

#endif
