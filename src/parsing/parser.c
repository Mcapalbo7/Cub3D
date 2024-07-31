/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:09:21 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:33 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	validate_floor_line(char **matrix, size_t last)
{
	char	*tmp;

	tmp = matrix[0];
	while (*tmp)
	{
		if (*tmp != '1' && *tmp != ' ')
			return (0);
		tmp++;
	}
	tmp = matrix[last];
	while (*tmp != '\0')
	{
		if (*tmp != '1' && *tmp != ' ')
			return (0);
		tmp++;
	}
	return (1);
}

int	get_first_char(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str != '1')
		return (0);
	else if (str[ft_strlen(str) - 1] != '1')
		return (0);
	return (1);
}

int	check_last_line(char *last, char *prev)
{
	int	i;

	i = 0;
	while (last[i])
	{
		if (last[i] == ' ')
		{
			if (prev[i] != ' ' && prev[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map_row(char **matrix, int x, int y)
{
	if (check_wall_bord(x, y, matrix) == 0)
	{
		if (matrix[x][y] != '1')
			return (0);
		else
			return (1);
	}
	if (matrix[x][y] == ' ')
	{
		if ((matrix[x][y + 1] != ' ' && matrix[x][y + 1] != '1')
		|| (matrix[x][y - 1] != ' ' && matrix[x][y - 1] != '1')
				|| (matrix[x + 1][y] != ' ' && matrix[x + 1][y] != '1')
				|| (matrix[x - 1][y] != ' ' && matrix[x - 1][y] != '1'))
			return (0);
		else
			return (1);
	}
	else if (matrix[x][y] == '0')
	{
		if (matrix[x][y + 1] == ' ' || matrix[x][y - 1] == ' '
			|| matrix[x - 1][y] == ' ' || matrix[x + 1][y] == ' ')
			return (0);
	}
	return (1);
}

int	verify_wall(char **matrix)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	if (validate_floor_line(matrix, matrix_length(matrix) - 1) == 0)
		return (0);
	while (x < matrix_length(matrix) - 1)
	{
		y = 0;
		if (!get_first_char(matrix[x]))
			return (0);
		while (matrix[x][y++] == ' ')
			;
		while (matrix[x][y])
		{
			if (!validate_map_row(matrix, x, y))
				return (0);
			y++;
		}
		x++;
	}
	if (!check_last_line(matrix[x], matrix[x - 1]))
		return (0);
	return (1);
}
