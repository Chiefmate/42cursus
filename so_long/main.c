/* img training */

int	main(void)
{
	void	*mlx;
	void	*wlx;
	void	*img1;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	wlx = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./asset/land.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, wlx, 0, 0);
	mlx_loop(mlx);
	return (0);
	return (0);
}