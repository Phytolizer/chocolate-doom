#include "doom/main.hpp"

#include "doom/miscellaneous/argv.hpp"

#include <config.hpp>
#include <cstdio>

using doom::misc::argv::args;
namespace argv = doom::misc::argv;

int main(int argc, char** argv) {
	args.reserve(argc);
	std::copy(argv, argv + argc, std::back_inserter(args));
	if (argv::exists("-version") || argv::exists("--version")) {
		std::puts(PACKAGE_STRING);
		return 0;
	}

	argv::setExeDir();

	return doom::main();
}
