#ifndef VECTOR_H

# define VECTOR_H

# include <initializer_list>
# include <iostream>
# include "../exception/exception.h"

namespace rub
{
	template <typename T>
	class vector
	{
		private:
			T*			_data = nullptr;
			std::size_t	_size = 0;
			std::size_t	_capacity = 0;

		public:
			/*---------vector ctor/dtor---------*/
			vector();
			vector(std::size_t size);
			vector(std::size_t size, const T& value);
			vector(const rub::vector<T>& other);
			vector(rub::vector<T>&& other) noexcept;
			vector(const std::initializer_list<T>& list);
			~vector();

			/*---------vector operators---------*/
			rub::vector<T>&	operator=(const rub::vector<T>& other);
			rub::vector<T>&	operator=(rub::vector<T>&& other) noexcept;
			bool			operator==(const rub::vector<T>& other) const;
			bool			operator!=(const rub::vector<T>& other) const;
			bool			operator>=(const rub::vector<T>& other) const;
			bool			operator<=(const rub::vector<T>& other) const;
			bool			operator<(const rub::vector<T>& other) const;
			bool			operator>(const rub::vector<T>& other) const;
			T&				operator[](std::size_t index);
			const T&		operator[](std::size_t index) const;

			/*---------vector methods---------*/
			/*element access*/
			const T&		at(std::size_t index) const;
			T&				at(std::size_t index);

			const T*		data(void) const noexcept;
			T*				data(void) noexcept;

			const T&		front(void) const noexcept;
			T&				front(void) noexcept;

			const T&		back(void) const noexcept;
			T&				back(void) noexcept;

			/*capacity*/
			void			reserve(std::size_t new_capacity);
			void			resize(std::size_t new_size, const T& value = T());
			void			shrink_to_fit(void);

			std::size_t		size(void) const noexcept;
			std::size_t		capacity(void) const noexcept;
			bool			empty(void) const noexcept;

			/*modifiers*/
			void			push_back(const T& value);
			void			push_back(T&& value) noexcept;
			void			pop_front(void) noexcept;
			void			pop_back(void) noexcept;
			void			clear(void) noexcept;
	};
};

#include "./vector.tpp"

#endif //VECTOR_H
