#include "minishell.h"

bool	is_all_digits_or_signals(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]) && str[i] != '-' && str[i] != '+')
			return (false);
		i += 1;
	}
	return (true);
}