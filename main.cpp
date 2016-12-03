#include <boost/process.hpp>
#include <regex>
#include <iostream>
#include <string>
#include <vector>

namespace bp =::boost::process;


bp::child start_child(const std::string& path)
{
	std::vector<std::string> args{path};
	
	bp::context ctx;
	ctx.stdout_behavior = bp::capture_stream();
	return bp::launch(path, args, ctx);
}

int main(int argc, char** argv) {

	if (argc != 2)
		return 1;

	bp::child c = start_child(argv[1]);
	bp::pistream& is = child.get_stdout();

	std::string line;
	std::regex rx("\\S+\\s*");
	std::cmatch result;
	size_t counter(0);

	while (std::getline(is, line)) {
		while (std::regex_search(line.c_str(), result, rx))
		{
			line = result.suffix().str();
			++counter;
		}
	}
		
	std::cout << "Number of words: " << counter << std::endl;
	bp::status s = c.wait();
	return s.exited() ? s.exit_status() : EXIT_FAILURE;
}
