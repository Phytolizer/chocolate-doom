#include "doom/system/video.hpp"

static bool shouldDisplayFpsDots;

void doom::sys::vid::displayFpsDots(FpsDotsState state) {
	shouldDisplayFpsDots = state == FpsDotsState::SHOW;
}
