#include "doom/main.hpp"

#include "doom/dehacked/strings.hpp"
#include "doom/english.hpp"
#include "doom/miscellaneous/argv.hpp"
#include "doom/stat.hpp"
#include "doom/system.hpp"
#include "doom/system/video.hpp"

#include <config.hpp>

int doom::main() {
	sys::printBanner(PROJECT_NAME_PRETTY);
	stat::noMonsters = misc::argv::exists("-nomonsters");
	stat::respawnParm = misc::argv::exists("-respawn");
	stat::fastParm = misc::argv::exists("-fast");
	stat::devParm = misc::argv::exists("-devparm");

	sys::vid::displayFpsDots(stat::devParm ? sys::vid::FpsDotsState::SHOW
	                                       : sys::vid::FpsDotsState::HIDE);

	if (stat::devParm) {
		deh::print(eng::DEVSTR);
	}

	return 0;
}
