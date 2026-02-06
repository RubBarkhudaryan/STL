#ifndef UNIQUE_TPP

# define UNIQUE_TPP

# include "./unique.hpp"

/*-------default deleter-------*/
template<typename T>
void	rub::default_deleter<T>::operator()(T *ptr)
{
	delete ptr;
}

/*-------ctor/dtor-------*/
template<typename T, typename Deleter>
rub::unique_ptr<T, Deleter>::unique_ptr() noexcept :
	ptr(nullptr), del(Deleter{})
{}

template<typename T, typename Deleter>
rub::unique_ptr<T, Deleter>::unique_ptr(T* ptr) noexcept :
	ptr(ptr), del(Deleter{})
{}

template<typename T, typename Deleter>
rub::unique_ptr<T, Deleter>::unique_ptr(std::nullptr_t) noexcept :
	ptr(nullptr), del(Deleter{})
{}

template<typename T, typename Deleter>
rub::unique_ptr<T, Deleter>::unique_ptr(rub::unique_ptr<T, Deleter> &&other) noexcept :
	ptr(other.release()), del(other.get_deleter())
{}

template<typename T, typename Deleter>
rub::unique_ptr<T, Deleter>::unique_ptr(T* ptr, Deleter del) noexcept :
	ptr(ptr), del(del)
{}

template <typename T, typename Deleter>
template <typename P, typename D, typename>
rub::unique_ptr<T, Deleter>::unique_ptr(rub::unique_ptr<P, D>&& other) noexcept :
	ptr(other.release()), del(std::forward<D>(other.get_deleter()))
{}

template<typename T, typename Deleter>
rub::unique_ptr<T, Deleter>::~unique_ptr() noexcept
{
	this->del(this->ptr);
}

/*-------operators-------*/
template<typename T, typename Deleter>
T&	rub::unique_ptr<T, Deleter>::operator*(void) noexcept
{
	return (*(this->ptr));
}

template<typename T, typename Deleter>
T*	rub::unique_ptr<T, Deleter>::operator->(void) noexcept
{
	return (this->ptr);
}

template<typename T, typename Deleter>
rub::unique_ptr<T, Deleter>&	rub::unique_ptr<T, Deleter>::operator=(std::nullptr_t) noexcept
{
	this->reset();
	return (*this);
}

template<typename T, typename Deleter>
rub::unique_ptr<T, Deleter>&	rub::unique_ptr<T, Deleter>::operator=(rub::unique_ptr<T, Deleter>&& other) noexcept
{
	if (this != &other)
	{
		if (this->ptr)
			this->del(this->ptr);
		this->ptr = other.release();
		this->del = other.get_deleter();
		other.ptr = nullptr;
	}
	return (*this);
}

template<typename T, typename Deleter>
template <typename P, typename D, typename>
rub::unique_ptr<T, Deleter>&	rub::unique_ptr<T, Deleter>::operator=(rub::unique_ptr<P, D>&& other) noexcept
{
	if (this != &other)
	{
		if (this->ptr)
			this->del(this->ptr);
		this->ptr = other.release();
		this->del = std::forward<D>(other.get_deleter());
		other.ptr = nullptr;
	}
	return (*this);
}

/*-------methods-------*/
template<typename T, typename Deleter>
T*	rub::unique_ptr<T, Deleter>::release(void) noexcept
{
	T*	temp;

	temp = this->ptr;
	this->ptr = nullptr;
	return (temp);
}

template<typename T, typename Deleter>
T*	rub::unique_ptr<T, Deleter>::get(void) const noexcept
{
	return (this->ptr);
}

template<typename T, typename Deleter>
Deleter&	rub::unique_ptr<T, Deleter>::get_deleter(void) noexcept
{
	return (this->del);
}

template<typename T, typename Deleter>
const Deleter&	rub::unique_ptr<T, Deleter>::get_deleter(void) const noexcept
{
	return (this->del);
}

template<typename T, typename Deleter>
void	rub::unique_ptr<T, Deleter>::reset(T *ptr) noexcept
{
	if (this->ptr)
		this->del(this->ptr);
	this->ptr = ptr;
}

#endif //UNIQUE_TPP