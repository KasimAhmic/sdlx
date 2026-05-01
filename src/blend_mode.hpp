#pragma once

#include <SDL3/SDL_blendmode.h>

namespace SDL {
    enum class BlendMode : uint32_t {
        None               = SDL_BLENDMODE_NONE,
        Blend              = SDL_BLENDMODE_BLEND,
        BlendPreMultiplied = SDL_BLENDMODE_BLEND_PREMULTIPLIED,
        Add                = SDL_BLENDMODE_ADD,
        AddPreMultiplied   = SDL_BLENDMODE_ADD_PREMULTIPLIED,
        Mod                = SDL_BLENDMODE_MOD,
        Multiply           = SDL_BLENDMODE_MUL,
        Invalid            = SDL_BLENDMODE_INVALID,
    };
}
