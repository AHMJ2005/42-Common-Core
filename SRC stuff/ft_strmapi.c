#include <stdlib.h>

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) {
    char *res;
    unsigned int i;

    i = 0;
	if (!s || !f)
		return (0);
    res = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!res)
        return (0);
    while (s[i] != '\0')
    {
        res[i] = (*f)(i,s[i]);
        i++;
    }
    res[i] = '\0';
    return (res);
}