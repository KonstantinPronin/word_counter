#include <iostream>
#include <regex>
#include <string>


int main() {
	std::cout << "Hello, beatiful word, i like you!" << std::endl;
	std::string tmp("Hello, beatiful word, i like you!");

	std::regex rx("\\S+\\s*");

	std::cmatch result;

	while (std::regex_search(tmp.c_str(), result, rx)) {
		std::cout << result[0];
		
	}

	system("pause");
	return 0;
}
