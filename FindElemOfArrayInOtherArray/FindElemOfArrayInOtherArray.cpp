#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <ranges>
#include <limits>
#include <fstream>

int get_randval(int _MaxVal = std::numeric_limits<int>::max())
{
	return std::random_device{}() % _MaxVal;
}

int main()
{
	constexpr size_t src_size = 1024;
	constexpr size_t data_size = 8192;

	constexpr int max_val = 128;

	std::vector<int> srcv(src_size);
	for (auto& e : srcv)
		e = get_randval(max_val);

	std::vector<int> datav(data_size);
	for (auto& e : datav)
		e = get_randval(max_val);

	auto counter = 0;
	auto& e = srcv.front();
	for (auto de : datav)
		if (e == de)
			counter++;


	std::cout << "Value " << e << " repeat counter: " << counter << std::endl;

	return 0;
}