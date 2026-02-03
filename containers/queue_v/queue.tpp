#ifndef QUEUE_TPP

# define QUEUE_TPP

# include "./queue.h"

template <typename T>
rub::queue<T>::queue(void) : vector<T>()
{}

template <typename T>
rub::queue<T>::queue(const T& val) : vector<T>({val})
{}

template <typename T>
void	rub::queue<T>::pop(void)
{
	this->pop_front();
}

template <typename T>
void	rub::queue<T>::push(const T& val)
{
	this->push_back(val);
}

template <typename T>
T	rub::queue<T>::top(void) const
{
	return (this->front());
}

template <typename T>
bool	rub::queue<T>::empty(void) const
{
	return (rub::vector<T>::empty());
}

#endif //QUEUE_TPP