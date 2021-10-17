/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaildate_boundaries.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:25:32 by jokang            #+#    #+#             */
/*   Updated: 2021/10/17 23:28:07 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAILDATE_BOUNDARIES_H
# define VAILDATE_BOUNDARIES_H

int	validate_all_boundaries(int **grid, int slot, int *boundary, int length);
int	validate_col_up(int **grid, int slot, int *boundary, int length);
int	validate_col_down(int **grid, int slot, int *boundary);
int	validate_row_left(int **grid, int slot, int *boundary, int length);
int	validate_row_right(int **grid, int slot, int *boundary);

#endif /* VAILDATE_BOUNARIES_H */
