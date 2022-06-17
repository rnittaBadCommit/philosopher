#include "../../philosopher.h"

int	_is_valid_args_num(int argc, char **argv, t_err *err)
{
	int	philosopher_num;

	philosopher_num = ft_atoi(argv[1], err);
	if (*err != NO_ERR)
	{
		*err = INVALID_ARG_NUM;
		return (INVALID);
	}
	if (argc != DEFAULT_ARGS_NUM && \
		argc != DEFAULT_ARGS_NUM + philosopher_num)
	{
		*err = INVALID_ARG_NUM;
		return (INVALID);
	}
	else
		return (VALID);
}

int	_is_all_digits(char *s)
{
	while (*s)
	{
		if (*s < '0' || '9' < *s)
			return (FALSE);
		s++;
	}
	return (TRUE);
}

int	_is_empty_string(char *s)
{
	return (*s == '\0');
}

int	_is_valid_args_value(char **argv, t_err *err)
{
	while (*(++argv))
	{
		if (_is_empty_string(*argv) || !_is_all_digits(*argv))
		{
			*err = INVALID_ARG_VALUE;
			return (INVALID);
		}
	}
	return (VALID);
}

int	is_valid_args(int argc, char **argv, t_err *err)
{
	if (_is_valid_args_value(argv, err) == INVALID)
		return (INVALID);
	else if (_is_valid_args_num(argc, argv, err) == INVALID)
		return (INVALID);
	else
		return (VALID);
}
