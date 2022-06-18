#include "../../philosopher.h"

int	_is_valid_args_num(int argc, t_err *err)
{
	if (argc == 5 || argc == 6)
		return (VALID);
	else
	{
		*err = INVALID_ARG_NUM;
		return (INVALID);
	}
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
	if (_is_valid_args_num(argc, err) == INVALID)
		return (INVALID);
	else if (_is_valid_args_value(argv, err) == INVALID)
		return (INVALID);
	else
		return (VALID);
}
