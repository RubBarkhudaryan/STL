#ifndef SET_H

# define SET_H

# include <initializer_list>

namespace rub
{
	enum	print_modes
	{
		INORDER,
		PREORDER,
		POSTORDER
	};

	template <typename T>
	struct	set_node
	{
		T					value;
		rub::set_node<T>	*left;
		rub::set_node<T>	*right;

		set_node(void);
		set_node(const T& val);
		~set_node(void) = default;
	};

	template <typename T>
	class	set
	{
		private:
			rub::set_node<T>	*root;

			void	bst_insert(rub::set_node<T> *node, const T& val);
			void	print(rub::set_node<T> *node, int mode) const;
			void	delete_tree(rub::set_node<T> *node);
		public:
			public:
			/*---------set ctor/dtor---------*/
			set(void);
			set(std::initializer_list<T> list);
			set(const rub::set<T>& other) = delete;
			~set(void);

			/*---------set operators---------*/
			rub::set<T>&	operator=(const rub::set<T>& other) = delete;

			/*---------set methods---------*/
			void	inorder(void) const;
			void	preorder(void) const;
			void	postorder(void) const;
	};
};

# include "./set.tpp"

#endif //SET_H