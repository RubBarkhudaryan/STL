#ifndef LIST_H

# define LIST_H

# include <cstddef>

namespace rub
{
	template <typename T>
	struct	node
	{
		T				value;
		rub::node<T>	*next;
		explicit node(const T& val);
	};

	template <typename T>
	class	list
	{
		protected:
			rub::node<T>		*_head;
			rub::node<T>		*_tail;
			std::size_t	_size;

		public:
			/*---------list ctor/dtor---------*/
			list(void);
			list(const T& val);
			list(const list<T> &) = delete;
			list<T>& operator=(const list<T> &) = delete;
			virtual ~list(void) noexcept;

			/*---------list methods---------*/
			void				insert(rub::node<T> *target, const T& value);
			void				push(const T& value);
			virtual void		pop(void);
			rub::node<T>		*front(void);
			rub::node<T>		*back(void);
			const rub::node<T>	*back(void) const;
			const rub::node<T>	*front(void) const;
			std::size_t			size() const;
	};
}

# include "./list.tpp"

#endif //LIST_H