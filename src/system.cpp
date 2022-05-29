#include "doom/system.hpp"

#include <SDL.h>
#include <cstdlib>
#include <fmt/core.h>
#include <list>

struct AtExitListEntry {
	doom::sys::AtExitFunc func;
	doom::sys::OnError onError;
};

static std::list<AtExitListEntry> atExitList;

void doom::sys::atExit(AtExitFunc func, OnError onError) {
	atExitList.emplace_back(AtExitListEntry{func, onError});
}

void doom::sys::quit() {
	for (auto& entry : atExitList) {
		entry.func();
	}

	SDL_Quit();

	std::exit(0);
}

void doom::sys::printBanner(std::string_view message) {
	fmt::print("{:^75}\n", message);
}

void doom::sys::printDivider() {
	fmt::print("{:=<75}\n", "");
}
