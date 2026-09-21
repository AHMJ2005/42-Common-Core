#include "libft.h"

int	get_total_len(int size, char **strs, char *sep)
{
    int	total;
    int	sep_len;
    int	i;

    sep_len = ft_strlen(sep);
    total = 0;
    i = 0;
    while (i < size)
    {
        total += ft_strlen(strs[i]);
        if (i < size - 1)
            total += sep_len;
        i++;
    }
    return (total + 1);
}

void	append_str(char *dest, int *c, char *src)
{
    int	i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[*c] = src[i];
        (*c)++;
        i++;
    }
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
    char	*res;
    int		total_len;
    int		c;
    int		i;

    if (size <= 0)
    {
        res = malloc(sizeof(char));
        if (res)
            res[0] = '\0';
        return (res);
    }
    total_len = get_total_len(size, strs, sep);
    res = malloc(sizeof(char) * total_len);
    if (!res)
        return (0);
    c = 0;
    i = 0;
    while (i < size)
    {
        append_str(res, &c, strs[i]);
        if (i < size - 1)
            append_str(res, &c, sep);
        i++;
    }
    res[c] = '\0';
    return (res);
}

