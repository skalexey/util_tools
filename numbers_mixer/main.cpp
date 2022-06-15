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
	cout << "=== numbers_mixer ===" << endl;

	std::vector<std::string> v = {
		"9/0.4/12/8	116" // lentils
		,"5/0.2/10/6	84"	// peas
		,"0.7/0.2/5.1/2.9	35" // carrot
	};
	std::vector<std::string> multipliers_s = {
		"0.5"
		, "0.3"
		, "0.2"
	};
	std::vector<float> nums;
	int i = 0;
	for (auto&& e : v)
	{
		auto mult = std::stof(multipliers_s[i]);
		auto nums_s = utils::split_of(e, " \t/");
		nums.resize(std::max(nums.size(), nums_s.size()));
		std::transform(nums_s.begin(), nums_s.end(), nums.begin(), nums.begin(), [&](auto&& nums_s_e, auto&& nums_e) {
			return nums_e + std::stof(std::string(nums_s_e)) * mult;
		});
		std::copy(nums.begin(), nums.end(), std::ostream_iterator<float>(std::cout, " "));
		std::cout << "\n";
		i++;
	}
	return 0;
}