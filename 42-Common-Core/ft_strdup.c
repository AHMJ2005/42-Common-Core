#include "libft.h"

char    *ft_strdup(const char *s)
{
    char	*p;
    int		i;

    i = 0;
    if (!s)
        return (0);
    p = (char *)malloc(1 * (ft_strlen(s) + 1));
    if (!p)
        return (0);
    while (s[i] != '\0')
    {
        p[i] = s[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}
