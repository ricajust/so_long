/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:58:15 by rda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 21:58:46 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <mlx.h>

/**
 * @brief Struct with window definition
 * @param *mlx_ptr pointer to mlx instance
 * @param *win_ptr pointer to window instance
 */
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

/**
 * @brief First function to show a windows
 * 
 */
int	show_window(void);

#endif