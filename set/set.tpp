#ifndef SET_TPP

# define SET_TPP

# include <iostream>
# include "./set.h"


template <typename T>
rub::set_node<T>::set_node(void) : left(nullptr), right(nullptr), value(T{})
{}

template <typename T>
rub::set_node<T>::set_node(const T& val) : left(nullptr), right(nullptr), value(val)
{}

template <typename T>
void	rub::set<T>::bst_insert(rub::set_node<T> *node, const T& val)
{
	if (val < node->value)
	{
		if (node->left)
			bst_insert(node->left, val);
		else
			node->left = new rub::set_node<T>(val);
	}
	else if (val > node->value)
	{
		if (node->right)
			bst_insert(node->right, val);
		else
			node->right = new rub::set_node<T>(val);
	}
}

template <typename T>
rub::set<T>::set(void) : root(nullptr)
{}

template <typename T>
rub::set<T>::set(std::initializer_list<T> list)
{
	auto	it = list.begin();
	if (it == list.end())
		return ;

	root = new rub::set_node<T>(*it);
	++it;

	for (; it != list.end(); ++it)
		bst_insert(root, *it);
}

template <typename T>
rub::set<T>::~set(void)
{
	delete_tree(root);
}

template <typename T>
void	rub::set<T>::delete_tree(rub::set_node<T> *node)
{
	if (!node)
		return ;
	delete_tree(node->left);
	delete_tree(node->right);
	delete node;
}

template <typename T>
void	rub::set<T>::print(rub::set_node<T> *node, int mode) const
{
	if (!node)
		return ;
	if (mode == INORDER)
	{
		print(node->left, mode);
		std::cout << node->value << std::endl;
		print(node->right, mode);
	}
	else if (mode == PREORDER)
	{
		std::cout << node->value << std::endl;
		print(node->left, mode);
		print(node->right, mode);
	}
	else if (mode == POSTORDER)
	{
		print(node->left, mode);
		print(node->right, mode);
		std::cout << node->value << std::endl;
	}
}

template <typename T>
void	rub::set<T>::inorder(void) const
{
	print(root, INORDER);
}

template <typename T>
void	rub::set<T>::preorder(void) const
{
	print(root, PREORDER);
}

template <typename T>
void	rub::set<T>::postorder(void) const
{
	print(root, POSTORDER);
}

#endif //SET_TPP