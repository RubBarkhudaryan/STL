#ifndef FORWARD_ITERATOR_TPP

# define FORWARD_ITERATOR_TPP

# include "./forward_iterator.h"

template <typename T>
rub::forward_iterator<T>::forward_iterator(void) : ptr(nullptr)
{}

template <typename T>
rub::forward_iterator<T>::forward_iterator(T *ptr) : ptr(ptr)
{}

template <typename T>
T&	rub::forward_iterator<T>::operator*(void) noexcept
{
	return (*(this->ptr));
}

template <typename T>
T*	rub::forward_iterator<T>::operator->(void) noexcept
{
	return (this->ptr);
}

template <typename T>
const T&	rub::forward_iterator<T>::operator*(void) const noexcept
{
	return (*(this->ptr));
}

template <typename T>
const T*	rub::forward_iterator<T>::operator->(void) const noexcept
{
	return (this->ptr);
}

template <typename T>
typename rub::forward_iterator<T>&	rub::forward_iterator<T>::operator++(void) noexcept
{
	++(this->ptr);
	return (*this);
}

template <typename T>
typename rub::forward_iterator<T>	rub::forward_iterator<T>::operator++(int) noexcept
{
	rub::forward_iterator<T>	temp(*this);

	++(this->ptr);
	return (temp);
}

template <typename T>
bool	rub::forward_iterator<T>::operator==(const rub::forward_iterator<T>& other) const noexcept
{
	return (this->ptr == other.ptr);
}

template <typename T>
bool	rub::forward_iterator<T>::operator!=(const rub::forward_iterator<T>& other) const noexcept
{
	return (this->ptr != other.ptr);
}

template <typename T>
T*	rub::forward_iterator<T>::base() const noexcept
{
	return (this->ptr);
}

#endif //FORWARD_ITERATOR_TPP