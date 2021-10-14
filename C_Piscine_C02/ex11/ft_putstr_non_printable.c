/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:16:08 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/14 17:29:11 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	g_base[17] = "0123456789abcdef";

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] <= 31 || str[i] >= 127)
		{
			ft_putchar('\\');
			ft_putchar(g_base[str[i] / 16]);
			ft_putchar(g_base[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
	}
}
