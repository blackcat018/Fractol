#include "../includes.h"

void initialize(t_frac *fr)
{
    fr->mlx_start = mlx_init();
    if(!fr->mlx_start)
        cleanup(); //TODO
    fr->mlx_win = mlx_new_window(fr->mlx_start, WIDTH, HIGHT, fr->name);
    if(!fr->mlx_win)
    {
        mlx-distroy_display(fr->mlx_start);
        free(fr->mlx_start);
         cleqnup();
    }
    fr->img.img = mlx_newi_mage(fr->mlx_start, WIDTH, HIGHT);
    if(! fr->img.img)
    {
        mlx-distroy_display(fr->mlx_start, fr->mlx_win);
        free(fr->mlx_start);
         cleqnup();
    }
    fr->img.pixels_ptr = mlx_get_data_addr(fr->img.img, &fr->img.bits_per_pixel, &fr->img.line_length, &fr->img.endian);

    events_init(fr);//TODO!
}