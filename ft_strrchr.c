/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:14:16 by aybouarg          #+#    #+#             */
/*   Updated: 2026/10/27 11:14:18 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last;

	last = 0;
	while (s[last])
		last++;
	while (last >= 0)
	{
		if (s[last] == (char)c)
			return ((char *)&s[last]);
		last--;
	}
	return (NULL);
}
