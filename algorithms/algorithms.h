#ifndef ALGORITHMS_H

# define ALGORITHMS_H

# include <cstddef>

namespace rub
{
/*-----helper functions-----*/
template <typename T>
void	swap(T *elem_1, T* elem_2);

template <typename T>
std::size_t	partition(T *arr, std::size_t length);

template <typename T>
void	merge(T *arr, std::size_t length, T *left, T *right);

/*-----sorting algorithms-----*/
template <typename T>
void	bubble_sort(T *arr, std::size_t size);

template <typename T>
void	merge_sort(T *arr, std::size_t length);


template <typename T>
void	quick_sort(T *arr, std::size_t length);
}

# include "./algorithms.tpp"

#endif //ALGORITHMS_H