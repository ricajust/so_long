/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:57:25 by rda-silv          #+#    #+#             */
/*   Updated: 2022/06/15 22:03:28 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h> //Biblioteca para os metodos 'KeyPress' e 'KeyPressMask'
#include <X11/keysym.h> //Biblioteca que mapeia o teclado
#include <mlx.h> //minilibx

#define WINDOW_WIDTH 600 //Constante da largura da janela
#define WINDOW_HEIGHT 300 //Constante da altura da janela
#define MLX_ERROR 1 //Constante onde setamos o valor de retorno do erro
#define RED_PIXEL 0xff0000 // Constante do valor do pixel, neste caso vermelho
#define GREEN_PIXEL 0xFF00// Constante do valor do retangulo, setado como verde
#define WHITE_PIXEL 0xFFFFFF// Constante do valor do fundo, setado como branco

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /*bit per pixel*/
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_data
{
	void	*mlx_ptr; //ponteiro que receberá o minilibx
	void	*win_ptr; //ponteiro que receberá a janela
	t_img	img;
}	t_data; 

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
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
		i++;
	}
}

int	render(t_data * data)
{
	render_background(data, WHITE_PIXEL);
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 200, 100, 200, GREEN_PIXEL});
	render_rect(data, (t_rect){0, 0, 200, 100, RED_PIXEL});
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init(); // inicia e atribui o minilibx
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR); // se erro de conexão com o X server retorna erro
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "SHAZAM"); // cria a janela
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
}
