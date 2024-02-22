/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieggonz <dieggonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:17:05 by dieggonz          #+#    #+#             */
/*   Updated: 2024/02/22 22:24:16 by dieggonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_s1;
	size_t	len_s1;
	char	*str_new;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
	{
		str_new = (char *)malloc(sizeof(char));
		if (!str_new)
			return (NULL);
		*str_new = '\0';
		return (str_new);
	}
	start_s1 = 0;
	len_s1 = ft_strlen(s1);
	while (s1[start_s1] && ft_strchr(set, s1[start_s1]))
		start_s1++;
	while (ft_strchr(set, s1[len_s1 - 1]) && len_s1 > start_s1)
		len_s1--;
	str_new = (char *)malloc(sizeof(char) * (len_s1 - start_s1 + 1));
	if (!str_new)
		return (NULL);
	ft_strlcpy(str_new, &s1[start_s1], len_s1 - start_s1 + 1);
	return (str_new);
}
/*
#include <stdio.h>
int	main(void)
{
	char const *s1 = "ixixixAAAA  aa ix c EEEEixixix";
	char const *set = "ix";
	char *result;

	result = ft_strtrim(s1, set);
	if (result == NULL)
		printf("OK");
	else
	
	{	
		printf("%s\n", s1);
		printf("%s\n", result);
	}
	free(result);

}

De linea 23 a linea 30 soluciona problema de parametro *s1 = "";
*/
