#ifndef HASH_TABLE_TPP

# define HASH_TABLE_TPP

# include "./hash_table.h"

template <typename T, typename Hash, typename KeyEqual>
rub::hash_table<T, Hash, KeyEqual>::hash_table(void) : _table(16), _bucket_size(16)
{}

template <typename T, typename Hash, typename KeyEqual>
rub::hash_table<T, Hash, KeyEqual>::hash_table(std::size_t bucket) : _table(bucket), _bucket_size(bucket)
{}

template <typename T, typename Hash, typename KeyEqual>
std::size_t	rub::hash_table<T, Hash, KeyEqual>::hash(const T& value) const
{
	return (this->_hash(value));
}

template <typename T, typename Hash, typename KeyEqual>
std::size_t	rub::hash_table<T, Hash, KeyEqual>::index(const T& value) const
{
	return (this->hash(value) % this->_table.size());
}

template <typename T, typename Hash, typename KeyEqual>
void	rub::hash_table<T, Hash, KeyEqual>::insert(const T& value)
{
	std::size_t			ind = this->index(value);
	rub::list<T>&		lst = this->_table[ind];

	for (rub::node<T> *it = lst.front(); it != nullptr; it = it->next)
	{
		if (this->_equal(it->value, value))
		{
			std::cout << "Duplicate value.\n";
			return ;
		}
	}
	lst.push(value);
}

template <typename T, typename Hash, typename KeyEqual>
bool	rub::hash_table<T, Hash, KeyEqual>::contains(const T& value) const
{
	std::size_t			ind = this->index(value);
	const rub::list<T>&	lst = this->_table[ind];

	for (const rub::node<T> *it = lst.front(); it != nullptr; it = it->next)
	{
		if (this->_equal(it->value, value))
			return (true);
	}
	return (false);
}

#endif //HASH_TABLE_TPP