//기본적으로 return 1 값을 받는 경우를 false로 판단
//.h 즉 헤더 파일이 필요한 이유? 1) 전방 선언을 하지않아도 된다. 2) 분할 .c 파일을 컴파일 하기 때문에 함수 선언을 여러 c 파일과 공유 가능하다.
// 정리 -> c 파일로 만들어진 오브젝트 파일에 있는 함수들의 내용을 다른 소스 파일에서 사용할 수 있도록 하기 위함.

#include "exception_lib.h"
#include <unistd.h>

int	is_numbers(char c) // 숫자 판별
{
	return (c >= '0' && c <= '9');
}

int	is_argc_right(int argv) // 리눅스 환경에서 명령창에서 문자열을 받는 과정에서 필요한 배열 외의 다른 것이 들어올 경우 에러로 인식
{
	if (argv != 2) //argc가 오타난 것 argc는 매개변수의 개수 처음 문자열 입력 과정에서 ./rush.c 도 하나의 문자열로 인식하기에 2번째 들어오는 문자열이 아니면 error로 판단 argv[]는 매개변수의 문자열을 저장하는 배열
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	get_length_argv(char *str) //입력 받는 문자열의 길이
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		if (is_numbers(*str))
		{
			length++;
		}
		str++;
	}
	return (length);
}

int	check_boundary(int boundary[], int n) //입력받은 경계 값, 즉 밖의 배열의 마주보는 합이 5초과 인지 확인 초과면 error
{
	int	i;

	i = 0;
	while (i < n) //col
	{
		if (boundary[i] + boundary[i + n] > 5)
			return (1);
		i++;
	}
	i = 2 * n;
	while (i < n * 3) //row
	{
		if (boundary[i] + boundary[i + n] > 5)
			return (1);
		i++;
	}
	return (0);
}

//예외 처리
#include "vaildate_boundaries.h"

int	validate_all_boundaries(int **grid, int slot, int *boundary, int length) //알맞지 않은 숫자가 들어가 있다면 다시 전으로 돌아가서 숫자 탐색
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

	i = 0; //위쪽부터 확인하므로 0부터 시작
	max = 0;
	tower_count = 0; 
	boundary_offset = 0;//grid의 첫번째 줄을 의미
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
		if (boundary[slot % 4] != tower_count) //boundary의 col_up 숫자와 일치하는지 판별
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

	i = 3; //아래부터 확인 하므로 i = 3
	max = 0;
	tower_count = 0;
	boundary_offset = 4; //grid의 두번째 줄을 의미
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
		if (boundary[(slot % 4) + boundary_offset] != tower_count) //boundary의 col_down 숫자와 일치하는지 판별
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

	i = 0; //왼쪽부터 0
	max = 0;
	tower_count = 0;
	boundary_offset = 8; //grid line3
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
		if (boundary[(slot / 4) + boundary_offset] != tower_count) //boundary의 row_left 숫자와 일치하는지 판별
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

	i = 3; //오른쪽부터 역순 확인 이므로 3
	max = 0;
	tower_count = 0;
	boundary_offset = 12; //grid last line
	if (slot % 4 == 3)
	{
		while (i > -1)
		{
			if (grid[slot / 4][i] > max)
			{
				max = grid[slot / 4][i]; //맨 오른쪽부터 시작해서 max값을 변경
				tower_count++;//오른쪽에 들어갈 숫자랑 맞는지 비교를 위한 변수
			}
			i--;
		}
		if (boundary[(slot / 4) + boundary_offset] != tower_count) //맨 오른쪽에 있는 숫자랑 직접 오른쪽부터 센 변수와 같아 다음으로 넘어감 아니라면 다시 resolve 안의 재귀
			return (1);
	}
	return (0);
}

//resolve (문제푸는 알고리즘)
#include "resolve.h"
#include "vaildate_boundaries.h"
#include <unistd.h>

int	g_height[4] = { 1, 2, 3, 4 };

int	resolve(int **grid, int *boundary, int slot, int grid_length)
{
	if (resolve_recursive(grid, boundary, slot, grid_length) == 1) //재귀를 못돌고 빠져나오게 된다면 게임이 진행이 안되는 것
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
	cols = slot % grid_length; // 배열을 좌표처럼 생각
	if (slot == 16) //배열이 full이면 반환
		return (0);
	i = 0;
	while (i < grid_length)
	{
		if (validate_overlap(grid, slot, g_height[i], grid_length) == 0) //가로 세로 줄 검사, 중복된 수 있는지 판별
		{
			grid[rows][cols] = g_height[i]; //없으면 1부터 차례대로 넣음
			if (validate_all_boundaries(grid, slot, boundary, grid_length) == 0) //up, down, left, right 숫자를 차례로 확인해서 숫자가 알맞은지 판별
			{
				if (!resolve_recursive(grid, boundary, slot + 1, grid_length)) //
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	validate_overlap(int **grid, int slot_of_grid, int height, int grid_length) //가로, 세로 줄 검사, 중복된 수가 있는지 판별하는 함수
{
	int	i;
	int	rows;
	int	cols;

	rows = slot_of_grid / grid_length;
	cols = slot_of_grid % grid_length; // 배열을 좌표처럼 생각 몫은 행, 나머지는 열로 판단
	i = 0;
	while (i <= rows)
	{
		if (grid[i][cols] == height) //같은 것이 있으면
		{
			return (1); //false
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

//main 
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
	arg_len = get_length_argv(argv[1]); //boundary 배열의 길이
	grid_length = arg_len / BOUNDARY_COUNT;
	if (arg_len != grid_length * BOUNDARY_COUNT || grid_length != 4) //arg_len 과 4 * 4 비교하고 이중확인을 위한 grid_legnth == 4
	{
		write(1, "Error\n", 6);
		return (1);
	}
	put_boundary_value(boundary, argv[1], 4);
	if (check_boundary(boundary, BOUNDARY_COUNT) == 1) //주변 boundary 배열 체크해서 false일 경우 error
	{
		write(1, "Error\n", 6);
		return (1);
	}
	make_grid_malloc(&grid, 4); //동적할당
	resolve(grid, boundary, 0, grid_length); //알고리즘 풀이
	ft_print_grid(grid, grid_length); //풀이한 배열 프린트
	free_memory(&grid, grid_length); //할당해제
	return (0);
}

int	put_boundary_value(int *boundary, char *args, int grid_length) //argv로 받은 배열을 숫자 인지 파악해서 저장
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

int	make_grid_malloc(int ***gird, int grid_length) //동적할당, 3중 포인터를 쓰는 이유 2차원 배열 즉 2중 포인터의 주소 전달을 위해
{
	int	**p; //더블 포인터를 선언하는 이유는 할당 해제 할 때 grid의 주소를 잃어버리지 않기 위함 
	int	i;
	int	j;

	*gird = (int **)malloc(grid_length * sizeof(int *)); //동적할당
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

void	ft_print_grid(int **grid, int size) //grid 출력
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
			ch = grid[i][j] + '0'; //숫자 표현을 위한 + '0'
			write(1, &ch, 1);
			if (j != size - 1)
				write(1, " ", 1); //숫자 사이의 공백
			else
				write(1, "\n", 1); //줄바꿈
			j++;
		}
		i++;
	}
}

void	free_memory(int ***grid, int grid_length) //할당해제
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
