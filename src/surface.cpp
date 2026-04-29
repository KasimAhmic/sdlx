#include "surface.hpp"

#include <utility>

#include "error.hpp"

SDL::Surface::Surface(const int width, const int height, const SDL::PixelFormat format) {
    this->surface = SDL_CreateSurface(width, height, static_cast<SDL_PixelFormat>(format));

    if (!this->surface) {
        throw SDL::Error("Failed to create surface");
    }
}

SDL::Surface::~Surface() noexcept {
    SDL_DestroySurface(this->surface);
}

SDL::Surface::Surface(Surface&& other) noexcept {
    this->surface = std::exchange(other.surface, nullptr);
}

SDL::Surface & SDL::Surface::operator=(Surface &&other) noexcept {
    if (this != &other) {
        if (this->surface) {
            SDL_DestroySurface(this->surface);
        }

        this->surface = std::exchange(other.surface, nullptr);
    }

    return *this;
}
