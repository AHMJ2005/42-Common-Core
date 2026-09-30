
#include "ft_printf.h"
//#include "libft.h"
#include <stdio.h>
int	ft_printf(const char *s, ...)
{
	int i = 0;
	va_list ptr;
	va_start(ptr, s);
	while(s[i])
	{
		if (s[i] == 'i') {
			int a = va_arg(ptr, int);
			ft_putnbr_fd(a ,1);
		}
		if (s[i] == 'c') {
			char c = va_arg(ptr, int);
			ft_putchar_fd(c, 1);
		}
		if (s[i] == 's') {
			char *v = va_arg(ptr, char *);
			ft_putstr_fd(v, 1);
		}
		if (s[i] == 'd') {
			int a = va_arg(ptr, int);
			ft_putnbr_fd(a ,1);
		}
		if (s[i] == '\n') {

			ft_putchar_fd('\n', 1);
		}
		if (s[i] == 'x') {
			int a = va_arg(ptr, int);
			ft_printhex(a ,1);
		}
		i++;
	}
	va_end(ptr);
	return (0);
}
int main() {
	int i = 0;
	int a = ft_printf("%d\n%s\n%c" , 42, "ahmad", 'c');
	//printf("%i", a);
}