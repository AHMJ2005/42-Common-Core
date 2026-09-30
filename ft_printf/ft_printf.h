#ifndef PRINTF_H
# define PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int     ft_printf(const char * s, ...);

void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	ft_printhex(char *s, int fd);











#endif

