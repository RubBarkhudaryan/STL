#ifndef STACK_H

# define STACK_H

# include "../vector/vector.h"

namespace rub
{
	template <typename T>
	class	stack : rub::vector<T>
	{
		public:
			/*---------stack ctor/dtor---------*/
			stack(void);
			stack(const T& val);
			~stack(void) noexcept override = default;
			stack(const stack &) = delete;

			/*---------stack operators---------*/
			stack& operator=(const stack &) = delete;

			/*---------stack methods---------*/
			T		top(void) const;
			void	pop(void);
			void	push(const T& val);
			bool	empty(void) const;
	};
};

# include "./stack.tpp"

#endif //stack_H