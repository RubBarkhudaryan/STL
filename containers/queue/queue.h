#ifndef QUEUE_H

# define QUEUE_H

# include "../list/list.h"

namespace rub
{
	template <typename T>
	class	queue : public list<T>
	{
		public:
			/*---------queue ctor/dtor---------*/
			queue(void);
			queue(const T& val);
			~queue(void) noexcept = default;
			queue(const queue<T> &) = delete;
			queue<T>& operator=(const queue<T> &) = delete;

			/*---------queue methods---------*/
			void	pop(void) override;
	};
}

#include "./queue.tpp"

#endif //QUEUE_H