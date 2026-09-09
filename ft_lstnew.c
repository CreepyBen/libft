#include "libft.h"

t_list *ft_1stnew(void *content)
{
    t_list  *new_node;
    
    new_node = malloc(sizeof(t_list));
    if (!new_node)
	    return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}