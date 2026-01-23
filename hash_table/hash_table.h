#ifndef HASH_TABLE_H

# define HASH_TABLE_H

# include "./list/list.h"
# include "./vector/vector.h"

namespace rub
{
	template <typename T, typename Hash, typename KeyEqual>
	class	hash_table
	{
		private:
			rub::vector<rub::list<T>>	_table;
			Hash						_hash;
			KeyEqual					_equal;
			std::size_t					_bucket_size;

		private:
			/*---------hash_table private functions---------*/
			std::size_t	hash(const T& value) const;
			std::size_t	index(const T& value) const;

		public:
			/*---------hash_table ctor/dtor---------*/
			hash_table(void);
			hash_table(std::size_t bucket = 16);
			~hash_table(void) = default;

			/*---------hash_table functions---------*/
			void		insert(const T& value);
			bool		contains(const T& value) const;
	};
}

# include "./hash_table.tpp"

#endif //HASH_TABLE_H