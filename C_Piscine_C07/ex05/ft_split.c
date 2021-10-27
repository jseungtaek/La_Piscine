/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:45:32 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/27 14:17:52 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		len;
	int		i;

	len = 0;
	i = 0;
	arr = malloc(sizeof(char *) * ft_t_length(str, charset) + 1);
	while (str[i])
	{
		arr[i] = malloc(sizeof(char) * ft_c_length(str, charset, len) + 1);
		ft_strcpy(arr[i], str, len, len += ft_c_length(str, charset, len));
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
	

char	*ft_strcpy(char *s1, char *s2, int st, int fi)
{
	int	i;

	i = 0;
	while (st < fi)
	{
		s1[i] = s2[st];
		i++;
		st++;
	}
	s1[i] = '\0';
	return (s1);
}

int	ft_c_length(char *str, char *charset, int i)
{
	int	j;

	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				break ;
			j++;
		}
		if (str[i] == charset[j])
			break ;
		i++;
	}
	return (i);
}

int	ft_t_length(char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (k);
}
