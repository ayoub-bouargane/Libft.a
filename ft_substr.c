/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:15:24 by aybouarg          #+#    #+#             */
/*   Updated: 2026/10/27 11:15:25 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	l_str;
	size_t	i;

	if (!s)
		return (NULL);
	l_str = ft_strlen(s);
	i = 0;
	if (start >= l_str)
		return (ft_strdup(""));
	if (len > (l_str - start))
		len = (l_str - start);
	sub = malloc((len * sizeof(char) + 1));
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
