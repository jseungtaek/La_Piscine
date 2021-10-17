/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:24:17 by jokang            #+#    #+#             */
/*   Updated: 2021/10/17 23:26:40 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception_lib.h"
#include <unistd.h>

int	is_numbers(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_argc_right(int argv)
{
	if (argv != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	get_length_argv(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		if (is_numbers(*str))
		{
			length++;
		}
		str++;
	}
	return (length);
}

int	check_boundary(int boundary[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (boundary[i] + boundary[i + n] > 5)
			return (1);
		i++;
	}
	i = 2 * n;
	while (i < n * 3)
	{
		if (boundary[i] + boundary[i + n] > 5)
			return (1);
		i++;
	}
	return (0);
}
