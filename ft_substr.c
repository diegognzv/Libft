/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieggonz <dieggonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:04:46 by dieggonz          #+#    #+#             */
/*   Updated: 2024/02/20 19:43:16 by dieggonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if (i <= start)
		len = 0;
	else if ((len + start) >= i)
		len = i - start;
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)


{
	
}

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		pos;
	size_t		len_s;

	pos = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start <= len_s)
	{
		if (len > len_s - start)
			len = len_s - start;
		ptr = (char *)ft_calloc((len + 1), sizeof(char));
		if (!ptr)
			return (NULL);
		while (pos < len && s[start + pos] != '\0')
		{
			ptr[pos] = s[start + pos];
			pos++;
		}
	}
	else
		return (ft_calloc(1, sizeof(char)));
	return (ptr);
}
*/
