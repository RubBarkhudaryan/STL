#include "vector.h"

template <typename T>
rub::vector<T>::vector() : _data(nullptr), _size(0), _capacity(0)
{
	// std::cout << "vector default ctor.\n";
}

template <typename T>
rub::vector<T>::vector(std::size_t size) : _data(nullptr), _size(0), _capacity(0)
{
	// std::cout << "vector parameterized ctor.\n";
	if (size > 0)
	{
		this->_size = size;
		this->_capacity = 2;
		while (this->_capacity <= this->_size)
			this->_capacity *= 2;
		this->_data = new T[this->_capacity]();
	}
}

template <typename T>
rub::vector<T>::vector(std::size_t size, const T& value) : _data(nullptr), _size(0), _capacity(0)
{
	// std::cout << "vector parameterized ctor.\n";
	if (size > 0)
	{
		this->_size = size;
		this->_capacity = 2;
		while (this->_capacity <= this->_size)
			this->_capacity *= 2;
		this->_data = new T[this->_capacity]();
		for (std::size_t i = 0; i < this->_size; ++i)
			this->_data[i] = value;
	}
}

template <typename T>
rub::vector<T>::vector(const rub::vector<T>& other) : _data(nullptr), _size(other._size), _capacity(other._capacity)
{
	// std::cout << "vector copy ctor.\n";
	this->_data = new T[this->_capacity]();
	for (std::size_t i = 0; i < other._size; ++i)
		this->_data[i] = other._data[i];
}

template <typename T>
rub::vector<T>::vector(rub::vector<T>&& other) noexcept : _data(other._data), _size(other._size), _capacity(other._capacity)
{
	// std::cout << "vector move ctor.\n";
	other._size = 0;
	other._capacity = 0;
	other._data = nullptr;
}

template <typename T>
rub::vector<T>::vector(const std::initializer_list<T>& list) : _data(nullptr), _size(0), _capacity(0)
{
	// std::cout << "vector initializer_list ctor called.\n";
	if (list.size() > 0)
	{
		this->_capacity = 2;
		while (this->_capacity <= list.size())
			this->_capacity *= 2;
		this->_data = new T[this->_capacity]();
		for (const T& it : list)
			this->_data[this->_size++] = it;
	}
}

template <typename T>
rub::vector<T>::~vector()
{
	// std::cout << "vector dtor called.\n";
	delete[] this->_data;
}

template <typename T>
rub::vector<T>&	rub::vector<T>::operator=(const rub::vector<T>& other)
{
	// std::cout << "vector copy assignment operator called.\n";
	if (this != &other)
	{
		delete[] this->_data;
		this->_size = other._size;
		this->_capacity = other._capacity;
		this->_data = new T[this->_capacity]();
		for (std::size_t i = 0; i < this->_size; ++i)
			this->_data[i] = other._data[i];
	}
	return (*this);
}

template <typename T>
rub::vector<T>&	rub::vector<T>::operator=(rub::vector<T>&& other) noexcept
{
	// std::cout << "vector move assignment operator called.\n";
	if (this != &other)
	{
		delete[] this->_data;
		this->_size = other._size;
		this->_capacity = other._capacity;
		this->_data = other._data;

		other._data = nullptr;
		other._size = 0;
		other._capacity = 0;
	}
	return (*this);
}

template <typename T>
bool	rub::vector<T>::operator==(const rub::vector<T>& other) const
{
	if (this->_size != other._size)
		return (false);

	for (std::size_t i = 0; i < this->_size; ++i)
	{
		if (this->_data[i] != other._data[i])
			return (false);
	}

	return (true);
}

template <typename T>
bool	rub::vector<T>::operator!=(const rub::vector<T>& other) const
{
	return !(*this == other);
}

template <typename T>
bool	rub::vector<T>::operator>=(const rub::vector<T>& other) const
{
	if ((*this == other) || (*this) > other)
		return (true);
	return (false);
}

template <typename T>
bool	rub::vector<T>::operator<=(const rub::vector<T>& other) const
{
	if ((*this == other) || (*this) < other)
		return (true);
	return (false);
}

template <typename T>
bool	rub::vector<T>::operator<(const rub::vector<T>& other) const
{
	std::size_t	min_len = std::min(this->_size, other._size);

	for (std::size_t i = 0; i < min_len; ++i)
	{
		if (this->_data[i] < other._data[i])
			return (true);
		if (other._data[i] < this->_data[i])
			return (false);
	}
	return (this->_size < other._size);
}

template <typename T>
bool	rub::vector<T>::operator>(const rub::vector<T>& other) const
{
	return (other < *this);
}

template <typename T>
const T&	rub::vector<T>::operator[](std::size_t index) const
{
	return (this->_data[index]);
}

template <typename T>
T&	rub::vector<T>::operator[](std::size_t index)
{
	return (this->_data[index]);
}

template <typename T>
T&	rub::vector<T>::at(std::size_t index)
{
	if (index >= this->_size)
		throw std::out_of_range("rub::vector::at() : index out of range.\n");
	return (this->_data[index]);
}

template <typename T>
const T&	rub::vector<T>::at(std::size_t index) const
{
	if (index >= this->_size)
		throw std::out_of_range("rub::vector::at() : index out of range.\n");
	return (this->_data[index]);
}

template <typename T>
T*	rub::vector<T>::data(void) noexcept
{
	return (this->_data);
}

template <typename T>
const T*	rub::vector<T>::data(void) const noexcept
{
	return (this->_data);
}

template <typename T>
T&	rub::vector<T>::front(void) noexcept
{
	return (this->_data[0]);
}

template <typename T>
const T&	rub::vector<T>::front(void) const noexcept
{
	return (this->_data[0]);
}

template <typename T>
T&	rub::vector<T>::back(void) noexcept
{
	return (this->_data[this->_size - 1]);
}

template <typename T>
const T&	rub::vector<T>::back(void) const noexcept
{
	return (this->_data[this->_size - 1]);
}

template <typename T>
void	rub::vector<T>::push_back(const T& value)
{
	if (this->_size == this->_capacity)
	{
		std::size_t	new_capacity = this->_capacity == 0 ? 2 : this->_capacity * 2;
		reserve(new_capacity);
	}
	this->_data[this->_size++] = value;
}

template <typename T>
void	rub::vector<T>::push_back(T&& value)
{
	if (this->_size == this->_capacity)
	{
		std::size_t	new_capacity = this->_capacity == 0 ? 2 : this->_capacity * 2;
		reserve(new_capacity);
	}
	this->_data[this->_size++] = std::move(value);
}

template <typename T>
void	rub::vector<T>::pop_back(void) noexcept
{
	if (this->_size > 0)
	{
		this->_data[this->_size - 1] = T{};
		--(this->_size);
	}
}

template <typename T>
void	rub::vector<T>::pop_front(void) noexcept
{
	if (this->_size == 0)
		return ;
	for (std::size_t i = 0; i < this->_size - 1; ++i)
		this->_data[i] = this->_data[i + 1];
	--(this->_size);
}

template <typename T>
void	rub::vector<T>::reserve(std::size_t new_capacity)
{
	if (new_capacity <= this->_capacity)
		return ;

	T*	new_data = new T[new_capacity]();

	for (std::size_t i = 0; i < this->_size; ++i)
		new_data[i] = std::move(this->_data[i]);

	delete[] this->_data;
	this->_data = new_data;
	this->_capacity = new_capacity;
}

template <typename T>
void	rub::vector<T>::resize(std::size_t new_size, const T& value)
{
	if (new_size < this->_size)
	{
		while (this->_size > new_size)
			pop_back();
	}
	if (new_size > this->_size)
	{
		while (this->_size < new_size)
			push_back(value);
	}
}

template <typename T>
void	rub::vector<T>::shrink_to_fit(void)
{
	if (this->_size == this->_capacity)
		return ;
	
	if (this->_size == 0)
	{
		delete[] this->_data;
		this->_data = nullptr;
		this->_capacity = 0;
		return ;
	}

	this->_capacity = this->_size;
	T*	new_data = new T[this->_capacity]();

	for (std::size_t i = 0; i < this->_size; ++i)
		new_data[i] = std::move(this->_data[i]);

	delete[] this->_data;
	this->_data = new_data;
}

template <typename T>
std::size_t	rub::vector<T>::capacity(void) const noexcept
{
	return (this->_capacity);
}

template <typename T>
std::size_t	rub::vector<T>::size(void) const noexcept
{
	return (this->_size);
}

template <typename T>
bool	rub::vector<T>::empty(void) const noexcept
{
	return (this->_size == 0);
}

template <typename T>
void	rub::vector<T>::clear(void) noexcept
{
	while (this->_size)
		pop_back();
}
