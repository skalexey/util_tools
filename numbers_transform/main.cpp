// main.cpp : Defines the entry point for the application.
//
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <string_view>
#include <stdexcept>
#include <utils/string_utils.h>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "=== numbers_transofm ===" << endl;
	
	cout << "Number list: ";
	std::string number_list;
	std::getline(cin, number_list);
	auto v = utils::split_of(number_list, " \t,|/");
	cout << "\n";
	cout << "Multiplier: ";
	float mpl = float();
	cin >> mpl;
	cout << "\n";
	//std::string s = "0.8/11/2.8/3/2	115";
	std::vector<float> nums;
	try
	{
		std::transform(v.begin(), v.end(), std::back_inserter(nums), [&](auto&& sv) {
			return std::stof(std::string(sv)) * mpl;
		});
	}
	catch (...)
	{
		//std::cout << "Input error\n";
		//return 1;
	}
	cout << "Result: ";
	//std::cout << std::setprecision(2);
	std::copy(nums.begin(), nums.end(), std::ostream_iterator<float>(std::cout, " "));
	std::cout << "\n";
	return 0;
}
