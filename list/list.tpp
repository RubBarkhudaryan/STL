#ifndef LIST_TPP

# define LIST_TPP

# include "./list.h"

template <typename T>
rub::node<T>::node(const T& val) : value(val), next(nullptr)
{}

template <typename T>
rub::list<T>::list(void) : _head(nullptr), _tail(nullptr), _size(0)
{}

template <typename T>
rub::list<T>::list(const T& val) : _head(new rub::node<T>(val)), _tail(_head), _size(1)
{}

template <typename T>
rub::list<T>::~list(void) noexcept
{
	rub::node<T>	*temp;
	rub::node<T>	*nxt;

	temp = this->_head;
	while (temp)
	{
		nxt = temp->next;
		delete temp;
		temp = nxt;
	}
}

template <typename T>
void	rub::list<T>::insert(node<T> *target, const T& value)
{
	rub::node<T>	*new_node;
	if (!target)
		return ;
	new_node = new rub::node<T>(value);
	new_node->next = target->next;
	target->next = new_node;
	if (target == this->_tail)
		this->_tail = new_node;
	++(this->_size);
}

template <typename T>
void	rub::list<T>::push(const T& value)
{
	rub::node<T>	*new_node;
	if (!new_node)
		return ;
	new_node = new rub::node<T>(value);
	new_node->next = nullptr;
	if (!_head)
	{
		this->_head = new_node;
		this->_tail = new_node;
	}
	else
	{
		this->_tail->next = new_node;
		this->_tail = this->_tail->next;
	}
	++(this->_size);
}

template <typename T>
void	rub::list<T>::pop(void)
{
	rub::node<T>	*temp;

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
	temp = this->_head;
	while (temp->next != this->_tail)
		temp = temp->next;
	delete this->_tail;
	this->_tail = temp;
	this->_tail->next = nullptr;
	--(this->_size);
}

template <typename T>
rub::node<T>	*rub::list<T>::front(void)
{
	return (this->_head);
}

template <typename T>
const rub::node<T>	*rub::list<T>::front(void) const
{
	return (this->_head);
}

template <typename T>
rub::node<T>	*rub::list<T>::back(void)
{
	return (this->_tail);
}

template <typename T>
const rub::node<T>	*rub::list<T>::back(void) const
{
	return (this->_tail);
}

template <typename T>
std::size_t	rub::list<T>::size() const
{
	return (this->_size);
}

#endif //LIST_TPP