#ifndef EXCEPTION_H

# define EXCEPTION_H

# include <string>
# include <stdexcept>

namespace rub
{
	class	exception : public std::exception
	{
		private:
			const char	*issue;

		public:
			exception() = default;
			exception(const char *issue);
			~exception() = default;
			const char * what() const noexcept override;
	};
}

# include "./exception.tpp"

#endif //EXCEPTION_H