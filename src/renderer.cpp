#include "renderer.hpp"

#include <utility>

#include "error.hpp"

SDL::Renderer::Renderer(const SDL::Window &window, const std::string& name) {
    this->renderer = SDL_CreateRenderer(window.get(), name.c_str());

    if (!this->renderer) {
        throw SDL::Error("Failed to create renderer");
    }
}

SDL::Renderer::~Renderer() {
    SDL_DestroyRenderer(this->renderer);
}

SDL::Renderer::Renderer(Renderer &&) noexcept {
    this->renderer = std::exchange(this->renderer, nullptr);
}

SDL::Renderer & SDL::Renderer::operator=(Renderer &&other) noexcept {
    if (this != &other) {
        if (this->renderer) {
            SDL_DestroyRenderer(this->renderer);
        }

        this->renderer = std::exchange(other.renderer, nullptr);
    }

    return *this;
}

void SDL::Renderer::setVSync(SDL::Renderer::VSync vsync) const noexcept {
    SDL_SetRenderVSync(this->renderer, static_cast<int>(vsync));
}

void SDL::Renderer::renderGeometry(SDL_Texture *texture, const SDL::Vertex *vertices, const int num_vertices, const int *indices, const int num_indices) const noexcept {
    if (!SDL_RenderGeometry(this->renderer, texture, vertices, num_vertices, indices, num_indices)) {
        SDL_Log("Failed to render geometry: %s", SDL_GetError());
    }
}

void SDL::Renderer::renderRect(const SDL::FRect& rect) const noexcept {
    SDL_RenderRect(this->renderer, &rect);
}

void SDL::Renderer::renderLine(const float x1, const float y1, const float x2, const float y2) const noexcept {
    SDL_RenderLine(this->renderer, x1, y1, x2, y2);
}

void SDL::Renderer::renderPoint(const float x, const float y) const noexcept {
    SDL_RenderPoint(this->renderer, x, y);
}

void SDL::Renderer::renderFillRect(const SDL::FRect& rect) const noexcept {
    SDL_RenderFillRect(this->renderer, &rect);
}

void SDL::Renderer::clear() const noexcept {
    SDL_RenderClear(this->renderer);
}

void SDL::Renderer::present() const noexcept {
    SDL_RenderPresent(this->renderer);
}

void SDL::Renderer::setDrawColor(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) const noexcept {
    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

void SDL::Renderer::setDrawColor(const SDL::Color& color) const noexcept {
    this->setDrawColor(color.r, color.g, color.b, color.a);
}
