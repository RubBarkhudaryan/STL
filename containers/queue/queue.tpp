#ifndef QUEUE_TPP

# define QUEUE_TPP

# include "./queue.h"

template <typename T>
rub::queue<T>::queue(void) : list<T>()
{}

template <typename T>
rub::queue<T>::queue(const T& val) : list<T>(val)
{}

template <typename T>
void	rub::queue<T>::pop(void)
{
	rub::Node<T>*	del_node;

	if (!this->_head)
		return ;
	if (this->_head == this->_tail)
	{
		delete this->_head;
		this->_head = nullptr;
		this->_tail = nullptr;
		this->_size = 0;
		return ;
	}
	del_node = this->_head;
	this->_head = this->_head->next;
	delete del_node;
	--(this->_size);
}

#endif //QUEUE_TPP