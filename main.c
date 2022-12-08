#include "so_long.h"
//cc main.c libft.a libmlx.a -framework OpenGL -framework AppKit

 void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x, int y, int color, int size)
{
	int	i = 0;
	int j = 0;
	while (i < size)
	{
		while (j < size)
		{
			my_mlx_pixel_put(data, (x + j), (y + i), color);
			j++;
		}
		j = 0;
		i++;
	}
}

int	deal_key(int key, void *param)
{
	char c = '0' + key;
	ft_putnbr_fd(key, 1);
	write(1, "\n", 1);
	if (key == 53)
		ft_putstr_fd("ESC\n", 1);
	return (0);
}

int	end_prog(void *param)
{
	ft_putstr_fd("fin :-) \n", 1);
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_key_hook(mlx_win, deal_key, (void *)0);
	draw_square(&img, 5, 5, 0x55FF0000, 50);
	mlx_hook(mlx_win, 17, 0, end_prog, (void *)0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
