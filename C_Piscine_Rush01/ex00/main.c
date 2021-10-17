#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BOUNDARY_COUNT 4

int is_numbers(char c);
int get_length_argv(char* str);
int put_boundary_value(int* boundary, char* args, int grid_length);
int make_grid_malloc(int*** g_blank, int grid_length);

int resolve(int **grid, int *boundary, int slot_of_grid, int grid_length);
int validate_overlap(int **grid, int slot_of_grid, int height, int grid_length);
int validate_all_boundaries(int** grid, int slot_of_grid, int* boundary, int grid_length);
int validate_col_up(int** grid, int slot_of_grid, int* boundary, int grid_length);
int validate_col_down(int** grid, int slot_of_grid, int* boundary, int grid_length);
int validate_row_left(int** grid, int slot_of_grid, int* boundary, int grid_length);
int validate_row_right(int** grid, int slot_of_grid, int* boundary, int grid_length);

int main(int argc, char **argv)
{
	int arg_len;
	int grid_length;
	char *p;

	//Exception1 : argc  is not 2
	if (argc != 2)
	{
		write(1, "Error\n", 6);
	}

	//Exception2 : arg_count in agv[1] is not 16
	arg_len = get_length_argv(argv[1]);
	grid_length = arg_len / BOUNDARY_COUNT;
	if (arg_len != grid_length * BOUNDARY_COUNT || grid_length != 4)	
	{
		write(1, "Error\n", 6);
	}

	//Make boundary and put values on them
	//make grid
	int boundary[4 * BOUNDARY_COUNT];
	int** grid;

 	put_boundary_value(boundary, argv[1], 4);
	make_grid_malloc(&grid, 4);

	//algorithm
	resolve(grid, boundary, 0, grid_length);

	//just Test of boundary and grid
	//Of course You have to remove it before submit
	for (int i = 0; i < grid_length * grid_length; i++)
	{
		printf("%d", *(boundary + i));
	}
	printf("\n");


	for (int i = 0; i < grid_length; i++)
	{
		for (int j = 0; j < grid_length; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");	
	}

}

int is_numbers(char c)
{
	return (c >= '0' && c <= '9');
}

int get_length_argv(char* str)
{
	int length;
	
	length = 0;
	while (*str != '\0')
	{
		if (is_numbers(*str))
		{
			length++;
		}
		str++;
	}
	
	return length;
}

int put_boundary_value(int* boundary, char* args, int grid_length)
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
	return 0;
}

int make_grid_malloc(int*** gird, int grid_length)
{
	int	**p;
	int	i;
	int	j;

	*gird = (int **)malloc(grid_length * sizeof(int *));
	p = *gird;
	if (p == 0)
	{
		return 1;
	}
	i = 0;
	while (i < grid_length)
	{
		p[i] = (int *)malloc(grid_length * sizeof(int));
		if (p[i] == 0)
		{
			return 1;
		}
		j = 0;
		while (j < grid_length)
		{
			p[i][j] = 0;
			j++;
		}
		i++;	
	}
	
	return 0;
}

int resolve(int **grid, int *boundary, int slot_of_grid, int grid_length)
{
	int	height[4] = { 1, 2, 3, 4 };
	int	rows;
	int	cols;
	int	i;

	//when start, slot_grid == 0, grid_length == 4
	//and keep recurising until gird end or out when it is not vaild.
	rows = slot_of_grid / grid_length;
	cols = slot_of_grid % grid_length;
	if (slot_of_grid == 16)
	{
		return (1);
	}
	i = 0;
	while (i < grid_length)
	{
		if (validate_overlap(grid, slot_of_grid, height[i], grid_length) == 0)
		{
			grid[rows][cols] = height[i];
			if (validate_all_boundaries(grid, slot_of_grid, boundary, grid_length) == 0)
			{
				if (resolve(grid, boundary, slot_of_grid + 1, grid_length) == 1)
				{
					return (1);
				}
			}
		}
		i++;
	}
	return (0);
}

int validate_overlap(int **grid, int slot_of_grid, int height, int grid_length)
{
	int	i;
	int	rows;
	int cols;

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

int validate_all_boundaries(int** grid, int slot_of_grid, int* boundary, int grid_length)
{
	if (validate_col_up(grid, slot_of_grid, boundary, grid_length) == 1)
	{
		return (1);
	}
	if (validate_col_down(grid, slot_of_grid, boundary, grid_length) == 1)
	{
		return (1);
	}
	if (validate_row_left(grid, slot_of_grid, boundary, grid_length) == 1)
	{
		return (1);
	}
	if (validate_row_right(grid, slot_of_grid, boundary, grid_length) == 1)
	{
		return (1);
	}

	return (0);
}

int validate_col_up(int** grid, int slot_of_grid, int* boundary, int grid_length)
{
	int	is_full_rows;
	int	rows;
	int	cols;
	int	i;
	int	max;
	int	tower_count;
	int	boundary_offset;

	rows = slot_of_grid / 4;
	cols = slot_of_grid % 4;
	i = 0;
	max = 0;
	tower_count = 0;
	boundary_offset = 0;

	is_full_rows = rows == 3;
	if (is_full_rows)
	{
		while (i < grid_length)
		{
			if (grid[i][cols] > max)
			{
				max = grid[i][cols];
				tower_count++;
			}
			i++;
		}
		if (boundary[cols] != tower_count)
		{
			return (1);
		}
	}
	return (0);
}

int validate_col_down(int** grid, int slot_of_grid, int* boundary, int grid_length)
{
	int	is_full_rows;
	int	rows;
	int	cols;
	int	i;
	int	max;
	int	tower_count;
	int	boundary_offset;

	rows = slot_of_grid / 4;
	cols = slot_of_grid % 4;
	i = 3;
	max = 0;
	tower_count = 0;
	boundary_offset = 4;

	is_full_rows = rows == 3;
	if (is_full_rows)
	{
		while (i > -1)
		{
			if (grid[i][cols] > max)
			{
				max = grid[i][cols];
				tower_count++;
			}
			i--;
		}
		if (boundary[cols + boundary_offset] != tower_count)
		{
			return (1);
		}
	}
	return (0);
}

int validate_row_left(int** grid, int slot_of_grid, int* boundary, int grid_length)
{
	int	is_full_columns;
	int	rows;
	int	cols;
	int	i;
	int	max;
	int	tower_count;
	int	boundary_offset;

	rows = slot_of_grid / 4;
	cols = slot_of_grid % 4;
	i = 0;
	max = 0;
	tower_count = 0;
	boundary_offset = 8;

	is_full_columns = cols == 3;
	if (is_full_columns)
	{
		while (i < grid_length)
		{
			if (grid[rows][i] > max)
			{
				max = grid[rows][i];
				tower_count++;
			}
			i++;
		}
		if (boundary[rows + boundary_offset] != tower_count)
		{
			return (1);
		}
	}
	return (0);
}

int validate_row_right(int** grid, int slot_of_grid, int* boundary, int grid_length)
{
	int	is_full_columns;
	int	rows;
	int	cols;
	int	i;
	int	max;
	int	tower_count;
	int	boundary_offset;

	rows = slot_of_grid / 4;
	cols = slot_of_grid % 4;
	i = 3;
	max = 0;
	tower_count = 0;
	boundary_offset = 12;

	is_full_columns = cols == 3;
	if (is_full_columns)
	{
		while (i > -1)
		{
			if (grid[rows][i] > max)
			{
				max = grid[rows][i];
				tower_count++;
			}
			i--;
		}
		if (boundary[rows + boundary_offset] != tower_count)
		{
			return (1);
		}
	}
	return (0);
}
