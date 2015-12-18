#include <iostream>
#include "Expression.h"

int main()
{
	Expression exp;
	while (std::cin >> exp)
	{
		try
		{
			std::cout << exp.calculate() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
