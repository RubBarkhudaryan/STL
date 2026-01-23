#ifndef FORWARD_ITERATOR_H

# define FORWARD_ITERATOR_H

# include <cstddef>
# include <iterator>

namespace rub
{
	template <typename T>
	class	forward_iterator
	{
		
		private:
			T	*ptr;

		public:

			/*-----iterator traits-----*/
			using value_type = T;
			using reference = T&;
			using pointer = T*;
			using const_pointer = const T*;
			using const_reference = const T&;
			using difference_type = std::ptrdiff_t;
			using iterator_category = std::forward_iterator_tag;

			/*-----forward iterator ctor/dtor-----*/
			forward_iterator(void);
			explicit forward_iterator(T *ptr);
			~forward_iterator() = default;

			/*-----forward iterator operators-----*/
			T&								operator*(void) noexcept;
			T*								operator->(void) noexcept;
			const T&						operator*(void) const noexcept;
			const T*						operator->(void) const noexcept;
			rub::forward_iterator<T>&		operator++(void) noexcept;
			rub::forward_iterator<T>		operator++(int) noexcept;
			bool							operator==(const rub::forward_iterator<T>& other) const noexcept;
			bool							operator!=(const rub::forward_iterator<T>& other) const noexcept;

			/*-----forward iterator functions-----*/
			T*								base() const noexcept;
	};
}

# include "./forward_iterator.tpp"

#endif //FORWARD_ITERATOR_H