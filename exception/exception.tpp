#ifndef EXCEPTION_TPP

# define EXCEPTION_TPP

# include "./exception.h"
# include <utility>

rub::exception::exception(const char *issue) : issue(issue)
{}

const char	*rub::exception::what() const noexcept
{
	return (this->issue);
}

#endif //EXCEPTION_TPP