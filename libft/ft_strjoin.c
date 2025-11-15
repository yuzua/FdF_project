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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*ptr;

	s1_len = 0;
	while (s1 && s1[s1_len] != '\0')
		s1_len++;
	s2_len = 0;
	while (s2 && s2[s2_len] != '\0')
		s2_len++;
	total_len = s1_len + s2_len;
	ptr = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ptr)
		return (NULL);
	if (s1_len >= 1)
		ft_memcpy(ptr, s1, s1_len);
	if (s2_len >= 1)
		ft_strlcpy(ptr + s1_len, s2, s2_len + 1);
	else
		ptr[s1_len] = '\0';
	return (ptr);
}
