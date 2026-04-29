#pragma once

#include "SDL3/SDL_video.h"

namespace SDL {
    enum class ProgressState {
        Invalid       = SDL_PROGRESS_STATE_INVALID,
        None          = SDL_PROGRESS_STATE_NONE,
        Indeterminate = SDL_PROGRESS_STATE_INDETERMINATE,
        Normal        = SDL_PROGRESS_STATE_NORMAL,
        Paused        = SDL_PROGRESS_STATE_PAUSED,
        Error         = SDL_PROGRESS_STATE_ERROR
    };
}
