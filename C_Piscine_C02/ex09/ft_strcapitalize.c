/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:37:14 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/14 14:26:47 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_islower(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		return (1);
	return (0);
}

int	ft_isupper(char *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
		return (1);
	return (0);
}

int	ft_isdigit(char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(char *str, int i)
{
	if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (i == 0 && ft_islower(str, i))
			str[i] -= 32;
		else if (!ft_isdigit(str, i - 1))
		{
			if (ft_isalpha(str, i - 1))
			{
				if (ft_isupper(str, i))
					str[i] += 32;
			}
			else if (!ft_isalpha(str, i - 1) && ft_islower(str, i))
				str[i] -= 32;
		}
	}
	return (str);
}
