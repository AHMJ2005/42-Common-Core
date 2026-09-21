
#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t dsize) {
    unsigned int	i;
    unsigned int	res_d;
    unsigned int	res_s;
    unsigned int	len;

    i = 0;
    res_s = ft_strlen(src);
    res_d = ft_strlen(dest);
    len = ft_strlen(dest);
    if (dsize < 1)
        return (res_s + dsize);
    while (src[i] && len < dsize - 1) {
        dest[len] = src[i];
        len++;
        i++;
    }
    dest[i] = '\0';
    if (dsize < res_d)
        return (res_s + dsize);
    else
        return (res_d + res_s);
    return (i);
}
