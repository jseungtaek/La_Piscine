/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:13:16 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/12 19:16:03 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	a[10] = { 1, 3, 5, 7 ,8, 2, 4, 11, 25, 6};
	int i;

	i = 0;
	ft_sort_int_tab(a, 10);
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%d\n", a[i]);
	}
	return (0);
}