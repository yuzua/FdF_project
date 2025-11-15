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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_start_i;
	size_t	s_end_i;
	char	*ptr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s_start_i = 0;
	while (s1[s_start_i] != '\0' && ft_strchr(set, s1[s_start_i]))
		s_start_i++;
	s_end_i = ft_strlen(s1);
	while (s_end_i > s_start_i && ft_strchr(set, s1[s_end_i - 1]))
		s_end_i--;
	ptr = (char *)malloc(sizeof(char) * (s_end_i - s_start_i + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[s_start_i], s_end_i - s_start_i + 1);
	return (ptr);
}
