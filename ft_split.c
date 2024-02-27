/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieggonz <dieggonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:49:38 by dieggonz          #+#    #+#             */
/*   Updated: 2024/02/27 20:25:07 by dieggonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeup(char **strs, int z)
{
	int	i;

	i = 0;
	while (i < z)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

static void	ft_copy_word(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		j;

	word = NULL;
	j = *k;
	while (str[*k] != '\0' && str[*k] == c)
		*k += 1;
	while (str[*k] != '\0' && str[*k] != c)
		*k += 1;
	if (j < *k)
	{
		word = (char *)malloc(*k - j + 1);
		if (word == NULL)
			return (NULL);
		ft_copy_word(word, str, c, j);
	}
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (!str)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (!strs)
		return (NULL);
	while (i < j)
	{
		strs[i] = ft_stralloc(((char *)str), c, &pos);
		if (!strs[i])
		{
			ft_freeup(strs, i);
			strs[i] = NULL;
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
