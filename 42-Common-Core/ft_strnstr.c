#include "libft.h"
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
    int 	little_len;
    int	i;

    if (*little == '\0')
        return ((char *)big);
    little_len = ft_strlen(little);
    i = 0;
    while (big[i] != '\0' && (i + little_len) <= len)
    {
        if (big[i] == little[0])
        {
            if (ft_strncmp(&big[i], little, little_len) == 0)
                return ((char *)&big[i]);
        }
        i++;
    }
    return (0);
}
