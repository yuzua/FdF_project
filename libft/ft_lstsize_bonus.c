/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeita <skeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:11:27 by skeita            #+#    #+#             */
/*   Updated: 2025/05/11 16:11:28 by skeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	lst_node_count;
	t_list	*next_ptr;

	lst_node_count = 0;
	if (lst == NULL)
		return ((int)lst_node_count);
	next_ptr = lst;
	while (next_ptr != NULL)
	{
		lst_node_count++;
		next_ptr = next_ptr->next;
	}
	return ((int)lst_node_count);
}
