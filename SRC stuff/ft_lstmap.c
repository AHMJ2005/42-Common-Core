#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list	*res_list;
    t_list	*N_node;
    void	*content;

    if (!lst || !f || !del)
        return (NULL);
    res_list = NULL;
    while (lst)
    {
        content = f(lst->content);
        N_node = ft_lstnew(content);
        if (!N_node)
        {
            del(content);
            ft_lstclear(&res_list, del);
            return (NULL);
        }
        ft_lstadd_back(&res_list, N_node);
        lst = lst->next;
    }
    return (res_list);
}
