/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaildate_boundaries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:25:18 by jokang            #+#    #+#             */
/*   Updated: 2021/10/17 23:28:13 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vaildate_boundaries.h"

int	validate_all_boundaries(int **grid, int slot, int *boundary, int length)
{
	if (validate_col_up(grid, slot, boundary, length) == 1)
	{
		return (1);
	}
	if (validate_col_down(grid, slot, boundary) == 1)
	{
		return (1);
	}
	if (validate_row_left(grid, slot, boundary, length) == 1)
	{
		return (1);
	}
	if (validate_row_right(grid, slot, boundary) == 1)
	{
		return (1);
	}
	return (0);
}

int	validate_col_up(int **grid, int slot, int *boundary, int grid_length)
{
	int	i;
	int	max;
	int	tower_count;
	int	boundary_offset;

	i = 0;
	max = 0;
	tower_count = 0;
	boundary_offset = 0;
	if (slot / 4 == 3)
	{
		while (i < grid_length)
		{
			if (grid[i][slot % 4] > max)
			{
				max = grid[i][slot % 4];
				tower_count++;
			}
			i++;
		}
		if (boundary[slot % 4] != tower_count)
			return (1);
	}
	return (0);
}

int	validate_col_down(int **grid, int slot, int *boundary)
{
	int	i;
	int	max;
	int	tower_count;
	int	boundary_offset;

	i = 3;
	max = 0;
	tower_count = 0;
	boundary_offset = 4;
	if (slot / 4 == 3)
	{
		while (i > -1)
		{
			if (grid[i][slot % 4] > max)
			{
				max = grid[i][slot % 4];
				tower_count++;
			}
			i--;
		}
		if (boundary[(slot % 4) + boundary_offset] != tower_count)
			return (1);
	}
	return (0);
}

int	validate_row_left(int **grid, int slot, int *boundary, int length)
{
	int	i;
	int	max;
	int	tower_count;
	int	boundary_offset;

	i = 0;
	max = 0;
	tower_count = 0;
	boundary_offset = 8;
	if (slot % 4 == 3)
	{
		while (i < length)
		{
			if (grid[slot / 4][i] > max)
			{
				max = grid[slot / 4][i];
				tower_count++;
			}
			i++;
		}
		if (boundary[(slot / 4) + boundary_offset] != tower_count)
			return (1);
	}
	return (0);
}

int	validate_row_right(int **grid, int slot, int *boundary)
{
	int	i;
	int	max;
	int	tower_count;
	int	boundary_offset;

	i = 3;
	max = 0;
	tower_count = 0;
	boundary_offset = 12;
	if (slot % 4 == 3)
	{
		while (i > -1)
		{
			if (grid[slot / 4][i] > max)
			{
				max = grid[slot / 4][i];
				tower_count++;
			}
			i--;
		}
		if (boundary[(slot / 4) + boundary_offset] != tower_count)
			return (1);
	}
	return (0);
}
