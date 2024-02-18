/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieggonz <dieggonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:49:38 by dieggonz          #+#    #+#             */
/*   Updated: 2024/02/18 21:41:52 by dieggonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
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
		}
		else
		{
			i++;
		}
	}
	return (word);
}

static void	ft_strcpy(char *word, char *str, char c, int *j)
{
	int	i;

	i = 0;
	while (str[*j] != '\0' && str[*j] == c)
		(*j)++;
	while (str[*j + i] != c && str[*j + i] != '\0')
	{
		word[i] = str[*j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		j;

	j = *k;
	word = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k] != '\0' && str[*k] != c)
				*k += 1;
			word = (char *)malloc(sizeof(char) * (*k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_strcpy(word, str, c, &j);
	return (word);
}

// DESPUES DE AQUI EMPIEZA FT_SPLIT()

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (s == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount((char *)s, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	while (i < j)
	{
		strs[i] = ft_stralloc(((char *)s), c, &pos);
		if (strs[i] == NULL)
			ft_free(&strs[i]);
		i++;
	}
	return (strs);
}

// FUNCION SIN COMPLETAR NI COMPROBAR
