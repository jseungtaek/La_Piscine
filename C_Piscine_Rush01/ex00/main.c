/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:23:53 by jokang            #+#    #+#             */
/*   Updated: 2021/10/17 23:26:47 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "exception_lib.h"
#include "resolve.h"
#include "vaildate_boundaries.h"

#define BOUNDARY_COUNT 4

int		put_boundary_value(int *boundary, char *args, int grid_length);
int		make_grid_malloc(int ***gird, int grid_length);
void	ft_print_grid(int **grid, int size);
void	free_memory(int ***grid, int grid_length);

int	main(int argc, char **argv)
{
	int		arg_len;
	int		grid_length;
	int		boundary[4 * BOUNDARY_COUNT];
	int		**grid;

	if (is_argc_right(argc) == 1)
		return (1);
	arg_len = get_length_argv(argv[1]);
	grid_length = arg_len / BOUNDARY_COUNT;
	if (arg_len != grid_length * BOUNDARY_COUNT || grid_length != 4)
	{		
		write(1, "Error\n", 6);
		return (1);
	}
	put_boundary_value(boundary, argv[1], 4);
	if (check_boundary(boundary, BOUNDARY_COUNT) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	make_grid_malloc(&grid, 4);
	resolve(grid, boundary, 0, grid_length);
	ft_print_grid(grid, grid_length);
	free_memory(&grid, grid_length);
	return (0);
}

int	put_boundary_value(int *boundary, char *args, int grid_length)
{
	int	*p;
	int	i;

	p = boundary;
	i = 0;
	while (i < grid_length * BOUNDARY_COUNT)
	{
		if (is_numbers(*args))
		{				
			*p = *args - '0';
			i++;
			p++;
		}
		args++;
	}
	return (0);
}

int	make_grid_malloc(int ***gird, int grid_length)
{
	int	**p;
	int	i;
	int	j;

	*gird = (int **)malloc(grid_length * sizeof(int *));
	p = *gird;
	if (p == 0)
		return (1);
	i = 0;
	while (i < grid_length)
	{
		p[i] = (int *)malloc(grid_length * sizeof(int));
		if (p[i] == 0)
			return (1);
		j = 0;
		while (j < grid_length)
		{
			p[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print_grid(int **grid, int size)
{
	int		i;
	int		j;
	char	ch;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ch = grid[i][j] + '0';
			write(1, &ch, 1);
			if (j != size - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			j++;
		}
		i++;
	}
}

void	free_memory(int ***grid, int grid_length)
{
	int	i;
	int	**p;

	i = 0;
	p = *grid;
	while (i < grid_length)
	{
		free(p[i]);
		i++;
	}
	free(p);
}
