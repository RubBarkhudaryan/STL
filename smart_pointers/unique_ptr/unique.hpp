#ifndef UNIQUE_HPP

# define UNIQUE_HPP

# include <type_traits>
# include <cstddef>

namespace rub
{

	template <typename T>
	struct default_deleter
	{
		void	operator()(T* ptr);
	};

	template <typename T, typename Deleter = default_deleter<T>>
	class	unique_ptr
	{
		private:
			T*		ptr;
			Deleter	del;

		public:
			/*-----unique_ptr ctor/dtor-----*/
			unique_ptr(void) noexcept;
			unique_ptr(T* ptr) noexcept;
			unique_ptr(std::nullptr_t) noexcept;
			unique_ptr(rub::unique_ptr<T, Deleter> &&other) noexcept;
			unique_ptr(T *ptr, Deleter del) noexcept;
			template <
				typename P,
				typename D,
				typename = std::enable_if_t<
							std::is_convertible<P*, T*>::value &&
							std::is_constructible<Deleter, D&&>::value
				>
			>
			unique_ptr(rub::unique_ptr<P, D>&& other) noexcept;
			~unique_ptr() noexcept;
			unique_ptr(const rub::unique_ptr& other) = delete;

			/*-----unique_ptr operators-----*/
			T&								operator*(void) noexcept;
			T*								operator->(void) noexcept;
			rub::unique_ptr<T, Deleter>&	operator=(std::nullptr_t) noexcept;
			rub::unique_ptr<T, Deleter>&	operator=(rub::unique_ptr<T, Deleter>&& other) noexcept;
			template <
				typename P,
				typename D,
				typename = std::enable_if_t<
							std::is_convertible<P*, T*>::value &&
							std::is_constructible<Deleter, D&&>::value
				>
			>
			rub::unique_ptr<T, Deleter>&	operator=(rub::unique_ptr<P, D>&& other) noexcept;
			rub::unique_ptr<T, Deleter>&	operator=(const rub::unique_ptr<T, Deleter>& other) = delete;

			/*-----unique_ptr methods-----*/
			T*				release(void) noexcept;
			T*				get(void) const noexcept;
			Deleter&		get_deleter(void) noexcept;
			const Deleter&	get_deleter(void) const noexcept;
			void			reset(T *ptr = nullptr) noexcept;
	};
}

# include "./unique.tpp"

#endif //UNIQUE_HPP