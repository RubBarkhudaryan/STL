#ifndef TREE_H

# define TREE_H

# include "../vector/vector.h"

namespace rub
{
	template <typename T>
	class	Tree
	{
		private:
			T						value;
			rub::vector<Tree<T> *>	nodes;
			void	remove_children(void);
		public:
			/*---------tree ctor/dtor---------*/
			Tree(const T& val);
			~Tree(void);
			Tree(const Tree&) = delete;

			/*---------tree operators---------*/
			Tree& operator=(const Tree&) = delete;

			/*---------tree methods---------*/
			rub::Tree<T>*		get_child(std::size_t index);
			const rub::Tree<T>*	get_child(std::size_t index) const;
			void				add_child(const T& val);
			void				print(void) const;
	};
}
#include "tree.tpp"

#endif //TREE_H