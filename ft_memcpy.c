/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:07:29 by aybouarg          #+#    #+#             */
/*   Updated: 2026/10/27 11:07:31 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*sr;
	char		*ds;
	size_t		i;

	sr = (const char *)src;
	ds = (char *)dest;
	i = 0;
	while (n > i)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dest);
}
