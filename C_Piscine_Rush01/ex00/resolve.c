/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:24:43 by jokang            #+#    #+#             */
/*   Updated: 2021/10/17 23:27:56 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "vaildate_boundaries.h"
#include <unistd.h>

int	g_height[4] = {1, 2, 3, 4};

int	resolve(int **grid, int *boundary, int slot, int grid_length)
{
	if (resolve_recursive(grid, boundary, slot, grid_length) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	resolve_recursive(int **grid, int *boundary, int slot, int grid_length)
{
	int	rows;
	int	cols;
	int	i;

	rows = slot / grid_length;
	cols = slot % grid_length;
	if (slot == 16)
		return (0);
	i = 0;
	while (i < grid_length)
	{
		if (validate_overlap(grid, slot, g_height[i], grid_length) == 0)
		{
			grid[rows][cols] = g_height[i];
			if (validate_all_boundaries(grid, slot, boundary, grid_length) == 0)
			{
				if (!resolve_recursive(grid, boundary, slot + 1, grid_length))
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	validate_overlap(int **grid, int slot_of_grid, int height, int grid_length)
{
	int	i;
	int	rows;
	int	cols;

	rows = slot_of_grid / grid_length;
	cols = slot_of_grid % grid_length;
	i = 0;
	while (i <= rows)
	{
		if (grid[i][cols] == height)
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i <= cols)
	{
		if (grid[rows][i] == height)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
