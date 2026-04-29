#include "error.hpp"

#include "SDL3/SDL.h"

SDL::Error::Error()
    : std::runtime_error(SDL_GetError()) {}

SDL::Error::Error(const std::string& message)
    : std::runtime_error(message + ": " + SDL_GetError()) {}
