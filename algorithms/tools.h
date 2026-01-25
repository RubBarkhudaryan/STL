#ifndef TOOLS_H

# define TOOLS_H

namespace rub
{
	template <typename InputIt, typename UnaryFunc>
	UnaryFunc	for_each(InputIt start, InputIt end, UnaryFunc func);
}

# include "./tools.tpp"

#endif //TOOLS_H