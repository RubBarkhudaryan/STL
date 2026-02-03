#include "./vector.h"

int main()
{
	rub::vector<int> vct = {1,2,3,4,5};

	try
	{
		vct.at(5);
	}
	catch(const rub::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}