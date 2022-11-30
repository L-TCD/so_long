#include <stdlib.h>
#include "mlx.h"
//cc main.c libmlx.a -framework OpenGL -framework AppKit
int main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	free(mlx_ptr);
}
