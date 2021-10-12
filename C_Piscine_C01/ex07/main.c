/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:33:53 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/12 18:39:35 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_rev_int_tab(int *tab, int size);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i;

	i = 0;
	ft_rev_int_tab(array, 10);
	while(i < 10)
	{
		ft_putchar(array[i] + '0');
		i++;
	}
	return (0);
}
