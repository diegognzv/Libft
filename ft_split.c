/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieggonz <dieggonz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:04:28 by dieggonz          #+#    #+#             */
/*   Updated: 2024/03/07 21:54:25 by dieggonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_free(char **split)
{
	size_t	pos;

	pos = 0;
	while (split[pos] != NULL)
	{
		free(split[pos]);
		pos++;
	}
	free(split);
	return (NULL);
}

static	size_t	count_word(const char *str, char delimit)
{
	size_t	counter;
	size_t	index;

	if (!str)
		return (0);
	counter = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == delimit)
			index++;
		else
		{
			counter++;
			while (str[index] != delimit && str[index] != '\0')
				index++;
		}
	}
	return (counter);
}

static	char	*get_word(char const *str, char delimit, size_t *str_pos)
{
	char	*word;
	size_t	w_pos;

	w_pos = 0;
	while (str[*str_pos + w_pos] != '\0' && str[*str_pos + w_pos] != delimit)
		w_pos++;
	word = (char *)malloc(sizeof(char) * (w_pos + 1));
	if (word == NULL)
		return (NULL);
	w_pos = 0;
	while (str[*str_pos] != '\0' && str[*str_pos] != delimit)
	{
		word[w_pos] = str[*str_pos];
		w_pos++;
		(*str_pos)++;
	}
	word[w_pos] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	pos;
	size_t	str_pos;

	if (!s)
		return (NULL);
	arr = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	pos = 0;
	str_pos = 0;
	while (s[str_pos] != '\0')
	{
		if (s[str_pos] == c)
			str_pos++;
		else
		{
			arr[pos] = get_word(s, c, &str_pos);
			if (arr[pos] == NULL)
				return (ft_free(arr));
			pos++;
		}
	}
	arr[pos] = NULL;
	return (arr);
}
