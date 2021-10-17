/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:25:01 by jokang            #+#    #+#             */
/*   Updated: 2021/10/17 23:28:00 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_H
# define RESOLVE_H

int	resolve(int **grid, int *boundary, int slot, int grid_length);
int	resolve_recursive(int **grid, int *boundary, int slot, int grid_length);
int	validate_overlap(int **grid, int slot_of_grid, int height, int grid_length);

#endif /* RESOLVE_H */
