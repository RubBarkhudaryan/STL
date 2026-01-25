#ifndef TOOLS_TPP

# define TOOLS_TPP

# include "./tools.h"

template <typename InputIt, typename UnaryFunc>
UnaryFunc	rub::for_each(InputIt start, InputIt end, UnaryFunc func)
{
	while (start != end)
	{
		func(*start);
		++start;
	}
	return (func);
}

#endif //TOOLS_TPP