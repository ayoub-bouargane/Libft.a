/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:10:23 by aybouarg          #+#    #+#             */
/*   Updated: 2026/10/27 11:10:24 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			len++;
		i++;
	}
	return (len);
}

static size_t	ft_count_char(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_dup_word(char const *s, char c, size_t *i)
{
	size_t	len_char;
	char	*word;

	len_char = ft_count_char(&s[*i], c);
	word = malloc((len_char + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, &s[*i], len_char);
	word[len_char] = '\0';
	*i += len_char;
	return (word);
}

static char	**ft_fill_arr(char **new, char const *s, char c, size_t len_str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < len_str)
	{
		while (s[i] && s[i] == c)
			i++;
		new[j] = ft_dup_word(s, c, &i);
		if (!new[j])
		{
			while (j > 0)
				free(new[--j]);
			free(new);
			return (NULL);
		}
		j++;
	}
	new[j] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	len_str;

	if (!s)
		return (NULL);
	len_str = ft_count_words(s, c);
	new = malloc((len_str + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	return (ft_fill_arr(new, s, c, len_str));
}
