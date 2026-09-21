#include "libft.h"
void    *ft_calloc(size_t n, size_t size) {
    void	*bzero;

    bzero = (void *)malloc(n * size);
    if (!bzero)
        return (0);
    ft_bzero (bzero, n * size);
    return (bzero);
}
