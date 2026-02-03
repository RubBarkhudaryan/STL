#ifndef QUEUE_H

# define QUEUE_H

# include "../vector/vector.h"

namespace rub
{
	template <typename T>
	class	queue : private vector<T>
	{
		public:
			/*---------queue ctor/dtor---------*/
			queue(void);
			queue(const T& val);
			~queue(void) noexcept override = default;
			queue(const queue &) = delete;

			/*---------queue operators---------*/
			queue& operator=(const queue &) = delete;

			/*---------queue methods---------*/
			T		top(void) const;
			void	pop(void);
			void	push(const T& val);
			bool	empty(void) const;
	};
};

# include "./queue.tpp"

#endif //QUEUE_H