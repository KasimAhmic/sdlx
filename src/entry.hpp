#pragma once

#include <SDL3/SDL_init.h>

namespace SDL {
    enum class AppResult {
        Continue = SDL_APP_CONTINUE,
        Success = SDL_APP_SUCCESS,
        Failure = SDL_APP_FAILURE,
    };
}
