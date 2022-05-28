#include "doom/miscellaneous/argv.hpp"

#include <algorithm>

std::vector<std::string> doom::misc::argv::args;

bool doom::misc::argv::exists(std::string_view arg) {
	return std::find(args.begin(), args.end(), arg) != args.end();
}
