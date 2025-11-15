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

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	src_len;
	size_t	inputed_dst_len;
	size_t	i;

	inputed_dst_len = 0;
	while (inputed_dst_len < dsize && dst[inputed_dst_len] != '\0')
		inputed_dst_len++;
	src_len = ft_strlen(src);
	if (dsize == 0 || inputed_dst_len >= dsize)
		return (inputed_dst_len + src_len);
	i = 0;
	while (src[i] != '\0' && inputed_dst_len + i < dsize - 1)
	{
		dst[inputed_dst_len + i] = src[i];
		i++;
	}
	dst[inputed_dst_len + i] = '\0';
	return (inputed_dst_len + src_len);
}
