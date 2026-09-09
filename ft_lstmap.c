#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_node;
    void    *new_content;
    t_list  *new_head;
    t_list  *last;

    new_head = NULL;
    while(lst)
    {
        new_content = f(lst->content);
        new_node = ft_lstnew(new_content);
        if(!new_node)
        {
            ft_lstclear(&new_head, del);
            return (NULL);
        }
        if (!new_head)
            new_head = new_node;
        else
            last->next = new_node;
        last = new_node;
        lst = lst->next;
    }
    return (new_head);
}
