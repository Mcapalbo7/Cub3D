/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:51:15 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 16:28:11 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	if (matrix != NULL)
		free(matrix);
}

int	is_space_string(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

char	*extract_path(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		i--;
	str[i + 1] = '\0';
	while (ft_isspace(*str))
		str++;
	str += 2;
	while (ft_isspace(*str))
		str++;
	if (str == NULL)
		return (NULL);
	return (ft_strdup(str));
}

int	check_wall_bord(int x, int y, char **matrix)
{
	if ((ft_strlen(matrix[x]) > ft_strlen(matrix[x + 1])
			&& (size_t)y > ft_strlen(matrix[x - 1]))
		|| (ft_strlen(matrix[x]) > ft_strlen(matrix[x - 1])
			&& (size_t)y > ft_strlen(matrix[x - 1])))
		return (0);
	return (1);
}

void	reset_color(t_color *color)
{
	color->red = -1;
	color->green = -1;
	color->blue = -1;
}
