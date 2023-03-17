/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:53:00 by dsenatus          #+#    #+#             */
/*   Updated: 2022/11/23 19:11:48 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	t_word(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	*get_sp(char const *s, char c)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	while (s[y] && s[y] != c)
		y++;
	str = malloc(sizeof(char) * (y + 1));
	if (!str)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		word;
	int		y;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	word = t_word(s, c);
	str = malloc(sizeof(char *) * (word + 1));
	if (!str)
		return (NULL);
	str[word] = NULL;
	while (s[i])
	{
		if (((i == 0) || (s[i - 1] == c)) && (y < word) && (s[i] != c))
		{
			str[y] = get_sp(&s[i], c);
			y++;
		}
		i++;
	}
	return (str);
}
