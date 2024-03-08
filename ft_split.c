/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieggonz <dieggonz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:04:28 by dieggonz          #+#    #+#             */
/*   Updated: 2024/03/08 16:19:49 by dieggonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
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
	char	**new_array;
	size_t	index;
	size_t	str_index;

	if (!s)
		return (NULL);
	new_array = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!new_array)
		return (NULL);
	index = 0;
	str_index = 0;
	while (s[str_index] != '\0')
	{
		if (s[str_index] == c)
			str_index++;
		else
		{
			new_array[index] = get_word(s, c, &str_index);
			if (new_array[index] == NULL)
				return (ft_free(new_array));
			index++;
		}
	}
	new_array[index] = NULL;
	return (new_array);
}
/*
int	main(void)
{
	char	*s = "Hola mundo! Esto es un string de prueba.";
	char	c = ' ';
	char	**split = ft_split(s, c);
	if (!split)
		return (1);
	printf("substring: %s\n", split[0]);	
	printf("substring: %s\n", split[1]);
	printf("substring: %s\n", split[2]);	
	printf("substring: %s\n", split[3]);
	printf("substring: %s\n", split[4]);
	printf("substring: %s\n", split[5]);
	printf("substring: %s\n", split[6]);
	printf("substring: %s\n", split[7]);
	
	ft_free(split);
	return(0);
}
*/
