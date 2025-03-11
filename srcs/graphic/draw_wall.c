#include "../../include/cub3d.h"

void    draw_wall(t_dda ray, t_game *game, int pixel)
{
    // mlx_image_t *wall_img;
    t_wall  wall;
    // uint32_t	color;
    (void)game;
    (void)pixel;
    int y;

    wall.wall_height = HEIGHT / ray.perpen_dist;
    wall.line_starty = (HEIGHT / 2 - wall.wall_height / 2);
    printf("line_starty: %d\n", wall.line_starty);
    wall.line_endy = (HEIGHT / 2 + wall.wall_height / 2);
    y = wall.line_starty;
    while (y < wall.line_endy)
    {
        // wall_img = mlx_new_image(game->mlx, WIDTH, y);
        // color = get_rgb(255,0,0);
        // mlx_put_pixel(wall_img, pixel, y, color);
        y++;
    }
}