#include "libft.h"

char *ft_strrchr(const char *s, int c) {
    int i;
    int len;

    len = ft_strlen(s);
    i = len;
    while (i >= 0) {
        if (s[i] == (char)c) {
            return (char *)&s[i];
        }
        i--;
    }
    return 0;
}
