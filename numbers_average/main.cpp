// main.cpp : Defines the entry point for the application.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <string_view>
#include <utils/string_utils.h>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "=== numbers_average ===" << endl;

	std::vector<std::string> v;
	int n = 1;
	while (true)
	{
		cout << "Number list " << n++ << " (or type 'end' to stop entering): ";
		std::string number_list;
		std::getline(cin, number_list);
		if (number_list == "end")
			break;
		v.push_back(number_list);
	}
	//std::vector<std::string> v = {
	//	"26/49/7/9	567"
	//	,"15/65/7/7	654"
	//	,"15/60/7/10	628"
	//};
	std::vector<float> nums;
	int i = 1;
	for (auto&& e : v)
	{
		auto nums_s = utils::split_of(e, " \t,|/");
		nums.resize(std::max(nums.size(), nums_s.size()));
		std::transform(nums_s.begin(), nums_s.end(), nums.begin(), nums.begin(), [&](auto&& nums_s_e, auto&& nums_e) {
			auto val = nums_e + std::stof(std::string(nums_s_e));
			return i == v.size() ? val / i : val;
		});
		std::copy(nums.begin(), nums.end(), std::ostream_iterator<float>(std::cout, " "));
		std::cout << "\n";
		i++;
	}
	return 0;
}
