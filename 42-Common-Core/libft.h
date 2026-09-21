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
#include <stdlib.h>

#ifndef	LIBFT_H
# define LIBFT_H
int ft_isalpha(int c);
int ft_isdigit(int c);
void *ft_memcpy(void *dest, const void *src, int n);
size_t	ft_strlcpy(char *dest, char *src, unsigned int size);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_bzero(void *s, int n);
int ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
void	*ft_memset(void *s, int c, int n);
int ft_strlen(const char *s);
int     ft_tolower(int c);
int	ft_toupper(int c);
void *ft_memmove(void *dest, const void *src, unsigned int n);
char    *ft_strdup(const char *s);
size_t strlcat(char *dst, const char *src, size_t dsize);
char *strchr(const char *s, int c);
void *memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);


#endif
