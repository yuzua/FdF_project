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

static void	copy_forward(
	unsigned char *dest, const unsigned char *src, size_t n
	)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	copy_backward(
	unsigned char *dest, const unsigned char *src, size_t n
	)
{
	size_t	i;

	if (n == 0)
		return ;
	i = n - 1;
	while (true)
	{
		dest[i] = src[i];
		if (i == 0)
			break ;
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_char;
	const unsigned char	*src_char = (unsigned char *)src;

	dest_char = (unsigned char *)dest;
	if ((dest_char == NULL || src_char == NULL) && n == 0)
		return (dest);
	else if (dest_char == NULL || src_char == NULL)
		return (NULL);
	if (dest_char < src_char)
		copy_forward(dest_char, src_char, n);
	else if (dest_char > src_char)
		copy_backward(dest_char, src_char, n);
	return (dest);
}
