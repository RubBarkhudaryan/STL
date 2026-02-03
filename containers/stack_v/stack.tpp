#ifndef STACK_TPP

# define STACK_TPP

# include "./stack.h"

template <typename T>
rub::stack<T>::stack(void) : rub::vector<T>()
{}

template <typename T>
rub::stack<T>::stack(const T& val) : rub::vector<T>({val})
{}

template <typename T>
void	rub::stack<T>::pop(void)
{
	this->pop_back();
}

template <typename T>
void	rub::stack<T>::push(const T& val)
{
	this->push_back(val);
}

template <typename T>
T	rub::stack<T>::top(void) const
{
	return (this->back());
}

template <typename T>
bool	rub::stack<T>::empty(void) const
{
	return (rub::vector<T>::empty());
}

#endif //STACK_TPP