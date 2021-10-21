/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:24:07 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/21 19:08:59 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen])
		strlen++;
	return (strlen);
}

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	return (s1);
}

int	ft_ma_length(int size, char **strs, int sep_len)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (i < size)
	{
		length += sep_len + ft_strlen(strs[i]);
		i++;
	}
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	char	*
