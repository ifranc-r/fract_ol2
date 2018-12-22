/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 20:58:48 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/21 20:14:28 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_nbrwords(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] == c)
		++i;
	if (s[i] == '\0')
		return (0);
	while (s[i] != c && s[i] != '\0')
		++i;
	return (1 + ft_nbrwords(s + i, c));
}

static void				ft_extractwords(char ***wordtab_p, char const *s,
		size_t nbwords, char c)
{
	unsigned int	i;
	unsigned int	tabi;
	size_t			wordlen;

	i = 0;
	tabi = 0;
	while (tabi < nbwords)
	{
		wordlen = 0;
		while (s[i] == c)
			++i;
		while (s[(size_t)i + wordlen] != c && s[(size_t)i + wordlen] != '\0')
			++wordlen;
		(*wordtab_p)[tabi] = ft_strsub(s, i, wordlen);
		++tabi;
		if (!(*wordtab_p)[tabi - 1])
		{
			while (tabi-- > 0)
				ft_strdel(*wordtab_p + tabi);
			free(*wordtab_p);
			*wordtab_p = NULL;
			return ;
		}
		i += (unsigned int)wordlen;
	}
}

char					**ft_strsplit(char const *s, char c)
{
	size_t			nbwords;
	char			**wordtab;

	if (!s)
		return (NULL);
	nbwords = ft_nbrwords(s, c);
	wordtab = (char **)malloc(sizeof(char *) * (nbwords + 1));
	if (!wordtab)
		return (NULL);
	wordtab[nbwords] = NULL;
	if (nbwords > 0)
		ft_extractwords(&wordtab, s, nbwords, c);
	return (wordtab);
}
