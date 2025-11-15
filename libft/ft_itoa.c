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

static int	get_n_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	n_len;
	long	n_long;

	n_len = get_n_len(n);
	ptr = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!ptr)
		return (NULL);
	ptr[n_len] = '\0';
	n_long = (long)n;
	if (n_long < 0)
	{
		ptr[0] = '-';
		n_long *= -1;
	}
	else if (n_long == 0)
		ptr[0] = '0';
	while (n_long > 0)
	{
		n_len--;
		ptr[n_len] = (n_long % 10) + '0';
		n_long /= 10;
	}
	return (ptr);
}
