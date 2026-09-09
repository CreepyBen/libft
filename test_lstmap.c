#include "libft.h"

t_list *test_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
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

#include <stdio.h>

void	*to_upper(void *content)
{
	char	*str;
	char	*result;
	int		i;

	str = (char *)content;
	result = malloc(strlen(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = ft_toupper(str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*tmp;

	lst = ft_lstnew(strdup("hello"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("world")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("42")));

	new = ft_lstmap(lst, to_upper, free);

	tmp = new;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	printf("Original:\n");
	tmp = lst;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	ft_lstclear(&new, free);
	ft_lstclear(&lst, free);
}
