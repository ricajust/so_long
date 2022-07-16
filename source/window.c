/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:21:08 by rda-silv          #+#    #+#             */
/*   Updated: 2022/07/16 17:22:05 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL; //precisamos definir a janela como null após sua destruição
	}
	return (0);
}

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
		i++;
	}
}

int	render(t_data * data)
{
	render_background(data, WHITE_PIXEL);
	render_rect(data, (t_rect){WIN_WIDTH - 100, WIN_HEIGHT - 200, 100, 200, GREEN_PIXEL});
	render_rect(data, (t_rect){0, 0, 200, 100, RED_PIXEL});
	return (0);
}

int	show_window(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init(); // inicia e atribui o minilibx
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR); // se erro de conexão com o X server retorna erro
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME); // cria a janela
	if (data.win_ptr == NULL) //Testa se a atribuição da janela foi válida
	{
		free(data.win_ptr); //Se não, libera memória...
		return (MLX_ERROR); //...e retorna o erro (1)
	}
	/*Fazendo os setups dos hooks*/
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	/**
	 * @brief Função utilizada para receber eventos. Ela nunca retorna e é um 
	 * loop infinito que aguardo um evento e em seguida chama uma função 
	 * definida pelo usuário associada ao evento
	 * @param mlx_ptr identificado de conexão 
	 */
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
