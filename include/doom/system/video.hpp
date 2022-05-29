#pragma once

namespace doom::sys::vid {

enum class FpsDotsState {
	SHOW,
	HIDE,
};

void displayFpsDots(FpsDotsState state);

} // namespace doom::sys::vid
