#include "../../philosopher.h"

int _is_valid_args_num(int argc, char **argv)
{
    int philosopher_num;
    t_err err;

    philosopher_num = ft_atoi(argv[1], &err);
    if (err != NO_ERR)
        return (INVALID);
    else if (argc != DEFAULT_ARGS_NUM && argc != DEFAULT_ARGS_NUM + philosopher_num)
        return (INVALID);
    else
        return (VALID);
}

int _is_all_digits(char *s)
{
    while (*s)
    {
        if (*s <'0' || '9' < *s)
            return (FALSE);
        s++;
    }
    return (TRUE);
}

int _is_valid_args_value(char **argv)
{
    while (*argv)
    {
        if (!_is_all_digits(*argv))
            return (INVALID);
        argv++;
    }
    return (VALID);
}

int is_valid_args(int argc, char **argv, t_err *err)
{
    if (_is_valid_args_value(argv) == INVALID)
        *err = INVALID_ARG_VALUE;
    else if (_is_valid_args_num(argc, argv) == INVALID)
        *err = INVALID_ARG_NUM;
    if (*err == NO_ERR)
        return (VALID);
    else
        return (INVALID);
}
