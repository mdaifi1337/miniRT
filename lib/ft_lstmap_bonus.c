/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:43:30 by mdaifi            #+#    #+#             */
/*   Updated: 2019/11/02 14:33:06 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*head;
	void	*tmp2;

	if (lst == NULL)
		return (lst);
	tmp = lst->next;
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	head = new;
	while (tmp != NULL)
	{
		tmp2 = tmp->content;
		if (!(new->next = ft_lstnew(f(tmp2))))
		{
			ft_lstclear(&head, del);
			break ;
		}
		new = new->next;
		tmp = tmp->next;
	}
	return (head);
}
