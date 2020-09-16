#include <mlx.h>

int main(void)
{
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");
	mlx_string_put(mlx, window, 10, 10, 100, "HELLO");
	mlx_loop(mlx);

	return (0);
}