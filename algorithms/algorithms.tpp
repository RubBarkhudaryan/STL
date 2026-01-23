#ifndef ALGORITHMS_TPP

# define ALGORITHMS_TPP

# include "./algorithms.h"

template <typename T>
void	rub::swap(T *elem_1, T* elem_2)
{
	T	temp;

	temp = *elem_1;
	*elem_1 = *elem_2;
	*elem_2 = temp;
}

template <typename T>
void	rub::bubble_sort(T *arr, std::size_t size)
{
	std::size_t	i;
	std::size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] < arr[j])
				rub::swap(&arr[i], &arr[j]);
			++j;
		}
		++i;
	}
}

template <typename T>
void	rub::merge(T *arr, std::size_t length, T *left, T *right)
{
	std::size_t	i;
	std::size_t	j;
	std::size_t	ind;
	std::size_t	mid;

	mid = length / 2;
	ind = 0;
	j = 0;
	i = 0;

	while (i < mid && j < length - mid)
	{
		if (left[i] < right[j])
			arr[ind++] = left[i++];
		else
			arr[ind++] = right[j++];
	}

	while (i < mid)
		arr[ind++] = left[i++];

	while (j < length - mid)
		arr[ind++] = right[j++];
}

template <typename T>
void	rub::merge_sort(T *arr, std::size_t length)
{
	T			*left;
	T			*right;
	std::size_t	r_ind;
	std::size_t	mid;

	if (length <= 1)
		return ;

	r_ind = 0;
	mid	= length / 2;
	left = new T[mid];
	right = new T[length - mid];

	for (std::size_t i = 0; i < mid; ++i)
		left[i] = arr[i];

	for (std::size_t j = mid; j < length; ++j)
		right[r_ind++] = arr[j];

	rub::merge_sort(left, mid);
	rub::merge_sort(right, length - mid);
	rub::merge(arr, length, left, right);

	delete[] left;
	delete[] right;
}

template <typename T>
std::size_t	rub::partition(T *arr, std::size_t length)
{
	std::size_t	j;
	std::size_t	ind;
	T			pivot;

	ind = length - 1;
	pivot = arr[ind];
	j = 0;

	for (std::size_t i = 0; i < ind; ++i)
	{
		if (arr[i] < pivot)
		{
			rub::swap(&arr[i], &arr[j]);
			++j;
		}
	}
	rub::swap(&arr[j], &arr[ind]);
	return (j);
}

template <typename T>
void	rub::quick_sort(T *arr, std::size_t length)
{
	std::size_t	pivot;

	if (length <= 1)
		return ;

	pivot = rub::partition(arr, length);
	rub::quick_sort(arr, pivot);
	rub::quick_sort(arr + pivot + 1, length - pivot - 1);
}

#endif //ALGORITHMS_TPP
