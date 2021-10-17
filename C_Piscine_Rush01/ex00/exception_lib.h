/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:24:31 by jokang            #+#    #+#             */
/*   Updated: 2021/10/17 23:27:38 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_LIB_H
# define EXCEPTION_LIB_H

int	is_numbers(char c);
int	is_argc_right(int argv);
int	get_length_argv(char *str);
int	check_boundary(int boundary[], int n);

#endif /* EXCEPTION_LIB_H */
