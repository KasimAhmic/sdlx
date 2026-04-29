#include "init.hpp"
#include "error.hpp"

void SDL::init(const SDL::InitFlag flags) {
    if (!SDL_Init(SDL::Internal::toUnderlying(flags))) {
        throw SDL::Error("Failed to initialize SDL");
    }
}
