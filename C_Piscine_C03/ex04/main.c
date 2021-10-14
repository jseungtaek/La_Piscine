/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:39:12 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/14 19:43:01 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	str[10] = "abcdefghi";
	char	to_find[4] = "deg";

	printf("%s", ft_strstr(str, to_find));
	return (0);
}
