/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:15:15 by aybouarg          #+#    #+#             */
/*   Updated: 2026/10/27 11:15:17 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end == 0 || start >= end)
		return (ft_strdup(""));
	end--;
	while (end > start && ft_in_set(s1[end], set))
		end--;
	new = malloc((end - start + 2) * sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, &s1[start], (end - start + 1));
	new[end - start + 1] = '\0';
	return (new);
}
