/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:36:02 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/27 10:39:56 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int	ft_size_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i]);
	len += ((size - 1) * ft_strlen(sep) + 1);
	return (len);
}

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	while (s2[j])
	{	
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		i;

	i = 0;
	if (size <= 0)
	{
		arr = (char *)malloc(sizeof(char) * 1);
		arr = 0;
		return (arr);
	}
	arr = (char *)malloc(sizeof(char) * ft_size_len(size, strs, sep));
	if (arr == 0)
		return (0);
	arr[0] = 0;
	while (i < size)
	{
		ft_strcat(arr, strs[i++]);
		if (i == size)
			break ;
		ft_strcat(arr, sep);
	}
	return (arr);
}
