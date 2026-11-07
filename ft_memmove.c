/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:07:39 by aybouarg          #+#    #+#             */
/*   Updated: 2026/10/27 11:07:41 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*sr;
	char		*ds;
	size_t		i;

	sr = (const char *)src;
	ds = (char *)dest;
	i = 0;
	if (ds < sr)
	{
		while (i < n)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	else if (ds > sr)
	{
		while (n--)
			ds[n] = sr[n];
	}
	return (dest);
}
