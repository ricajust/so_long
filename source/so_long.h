/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:45:59 by rda-silv          #+#    #+#             */
/*   Updated: 2022/06/26 15:47:52 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H //Nome do progama
# define WINDOW_WIDTH 600 //Constante da largura da janela
# define WINDOW_HEIGHT 300 //Constante da altura da janela
# define MLX_ERROR 1 //Constante onde setamos o valor de retorno do erro
# define RED_PIXEL 0xff0000 // Constante do valor do pixel, neste caso vermelho
# define GREEN_PIXEL 0xFF00// Constante do valor do retangulo, setado como verde
# define WHITE_PIXEL 0xFFFFFF// Constante do valor do fundo, setado como branco

# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h> //Biblioteca para os metodos 'KeyPress' e 'KeyPressMask'
# include <X11/keysym.h> //Biblioteca que mapeia o teclado
# include <mlx.h> //minilibx

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
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



#endif