#include "../../philosopher.h"

static void _ini_all(t_all *all)
{
    ft_bzero(all, sizeof(t_all));
}

void    ft_finalize(t_all *all)
{
    ft_free_all();
}

int main(int argc, char **argv)
{
    t_all all;

    _ini_all(&all);
    if (!is_valid_args(argc, argv, &all.err))
        return (ft_error(&all));
    if (set_all(&all) != NO_ERR)
        return (ft_error(&all));
    if (main_process(&all) != NO_ERR)
        return (ft_error(&all));
}