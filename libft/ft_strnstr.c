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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_i;
	size_t	match_i;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (len == 0 || little_len > len)
		return (NULL);
	big_i = 0;
	while (big_i < len && big[big_i] != '\0')
	{
		match_i = 0;
		while (
			big_i + match_i < len
			&& (unsigned char)big[big_i + match_i]
			== (unsigned char)little[match_i]
			&& little[match_i] != '\0'
		)
			match_i++;
		if (little[match_i] == '\0')
			return ((char *)(big + big_i));
		big_i++;
	}
	return (NULL);
}
