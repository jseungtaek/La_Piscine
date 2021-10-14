/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:43:41 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/14 12:44:30 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ')
			continue ;
		else if (str[i] >= 'a' && str[i] <= 'z')
			continue ;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			continue ;
		else
			return (0);
	}
	return (1);
}
