#pragma once

#include <SDL3/SDL_init.h>

#include "internal/enum.hpp"

namespace SDL {
    enum class InitFlag : uint32_t {
        Audio    = SDL_INIT_AUDIO,
        Video    = SDL_INIT_VIDEO,
        Joystick = SDL_INIT_JOYSTICK,
        Haptic   = SDL_INIT_HAPTIC,
        Gamepad  = SDL_INIT_GAMEPAD,
        Events   = SDL_INIT_EVENTS,
        Sensor   = SDL_INIT_SENSOR,
        Camera   = SDL_INIT_CAMERA,
    };

    template <>
    inline constexpr bool Internal::EnableBitmaskOperators<InitFlag> = true;
}
