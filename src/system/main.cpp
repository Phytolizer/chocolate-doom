#include "doom/miscellaneous/argv.hpp"

#include <cstdio>

using doom::misc::argv::args;

int main(int argc, char** argv) {
	args.reserve(argc);
	std::copy(argv, argv + argc, std::back_inserter(args));
}
