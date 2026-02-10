#ifndef UNIQUE_HPP

# define UNIQUE_HPP

# include <type_traits>
# include <cstddef>
# include <utility>

namespace rub
{
	template <typename T>
	struct default_deleter
	{
		default_deleter() = default;
		~default_deleter() = default;
		template <typename U,
				typename = std::enable_if_t<
								std::is_convertible<U*, T*>::value
							>
				>
		default_deleter(const default_deleter<U>&)
		{}
		void	operator()(T* ptr);
	};

	template <typename T>
	struct default_deleter<T[]>
	{
		default_deleter() = default;
		~default_deleter() = default;
		template <typename U,
				typename = std::enable_if_t<
								std::is_convertible<U*, T*>::value
							>
				>
		default_deleter(const default_deleter<U>&)
		{}
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
			unique_ptr(const rub::unique_ptr<T, Deleter>& other) = delete;

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

	template<typename T, typename Deleter>
	class	unique_ptr<T[], Deleter>
	{
		private:
			T*		ptr;
			Deleter	del;

		public:
			/*-----unique_ptr ctor/dtor-----*/
			unique_ptr() noexcept;
			unique_ptr(std::nullptr_t) noexcept;
			unique_ptr(rub::unique_ptr<T[], Deleter>&& u) noexcept;
			unique_ptr(const rub::unique_ptr<T[], Deleter>&) = delete;
			~unique_ptr() noexcept;

			/*-----template ctors-----*/
			template <typename U,
					typename = std::enable_if_t<
									std::is_convertible<U(*)[], T(*)[]>::value
								>
			>
			explicit unique_ptr(U *ptr) noexcept;

			template<typename U,
					typename = std::enable_if_t<
									std::is_convertible<U(*)[], T(*)[]>::value
								>
			>
			explicit unique_ptr(U *ptr, Deleter del1) noexcept;

			template<typename U,
					typename E,
					typename = std::enable_if_t<
									std::is_convertible<U(*)[], T(*)[]>::value &&
									std::is_constructible<Deleter, E&&>::value
								>
			>
			unique_ptr(rub::unique_ptr<U[], E>&& other) noexcept;

			/*-----unique_ptr[] operators-----*/
			T&								operator[](std::size_t ind) const;
			rub::unique_ptr<T[], Deleter>&	operator=(std::nullptr_t) noexcept;
			rub::unique_ptr<T[], Deleter>&	operator=(rub::unique_ptr<T[], Deleter>&& other) noexcept;
			rub::unique_ptr<T[], Deleter>&	operator=(const rub::unique_ptr<T[], Deleter>& other) = delete;

			template <
				typename P,
				typename D,
				typename = std::enable_if_t<
							std::is_convertible<P(*)[], T(*)[]>::value &&
							std::is_constructible<Deleter, D&&>::value
				>
			>
			rub::unique_ptr<T[], Deleter>&	operator=(rub::unique_ptr<P, D>&& other) noexcept;

			/*-----unique_ptr[] methods-----*/
			T*				release(void) noexcept;
			T*				get(void) const noexcept;
			Deleter&		get_deleter(void) noexcept;
			const Deleter&	get_deleter(void) const noexcept;
			void			reset(T *ptr = nullptr) noexcept;
	};
}

# include "./unique.tpp"

#endif //UNIQUE_HPP