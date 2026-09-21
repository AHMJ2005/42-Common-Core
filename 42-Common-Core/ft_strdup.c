#include "libft.h"

char    *ft_strdup(const char *s)
{
    char	*p;
    int		i;

    i = 0;
    if (src == NULL)
        return (0);
    p = malloc(1 * (ft_strlen(src) + 1));
    if (!p)
        return (NULL);
    while (src[i] != '\0')
    {
        p[i] = src[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}
