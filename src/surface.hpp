#pragma once

#include <SDL3/SDL_surface.h>

#include "pixel_format.hpp"

namespace SDL {
    class Surface {
    public:
        explicit Surface(int width, int height, SDL::PixelFormat format);
        ~Surface() noexcept;

        Surface(Surface&& other) noexcept;
        Surface& operator=(Surface&& other) noexcept;

        Surface(const Surface&) = delete;
        Surface& operator=(const Surface&) = delete;

    private:
        SDL_Surface* surface;
    };
}
