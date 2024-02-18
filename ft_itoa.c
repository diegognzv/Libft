/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieggonz <dieggonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:43:04 by dieggonz          #+#    #+#             */
/*   Updated: 2024/02/18 21:35:29 by dieggonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_number_size(int number)
{
	int	length;

	length = 0;
	if (number <= 9 && number >= 0)
		return (1);
	else if (number < 0)
	{
		length++;
		number *= -1;
	}
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*string;
	long int	number;
	int			length;

	number = (long)n;
	length = ft_number_size(number);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (!string)
		return (NULL);
	if (number == 0)
		string[0] = '0';
	if (number < 0)
	{
		string[0] = '-';
		number = number * -1;
	}
	string[length] = '\0';
	length--;
	while (number != 0)
	{
		string[length] = (number % 10) + '0';
		length--;
		number = number / 10;
	}
	return (string);
}
/*
#include <stdio.h>

int	main (void)
{
	//int number = -2147483648;
	int number = 10;
	char *str;

	str = ft_itoa(number);
	if (str != NULL)
	{
		printf("INT '%d' to string '%s'\n", number, str);
		free(str);
	}
	else
		printf("Error: INT '%d' to string.\n", number);
	return (0);
}
*/
