#pragma once

#include <SDL3/SDL_render.h>

#include "window.hpp"

namespace SDL {

    class Renderer {
    public:
        enum class VSync : int {
            Disabled = SDL_RENDERER_VSYNC_DISABLED,
            Adaptive = SDL_RENDERER_VSYNC_ADAPTIVE,
            Enabled  = 1,
            HalfRate = 2,
        };

        explicit Renderer(const SDL::Window& window, const std::string& name);
        ~Renderer();

        Renderer(Renderer&&) noexcept;
        Renderer& operator=(Renderer&& other) noexcept;

        Renderer(const Renderer&) = delete;
        Renderer& operator=(const Renderer&) = delete;

        [[nodiscard]] SDL_Renderer* get() const { return this->renderer; }

        void setVSync(SDL::Renderer::VSync vsync) const noexcept;
        void renderGeometry(SDL_Texture* texture, const SDL_Vertex* vertices, int num_vertices, const int *indices, int num_indices) const noexcept;
        void renderRect(const SDL::FRect& rect) const noexcept;
        void renderLine(float x1, float y1, float x2, float y2) const noexcept;
        template <size_t N>
        void renderLines(const std::array<SDL::FPoint, N>& vertices) const noexcept;
        void renderPoint(float x, float y) const noexcept;
        template <size_t N>
        void renderPoints(const std::array<SDL::FPoint, N>& vertices) const noexcept;
        void renderFillRect(const SDL::FRect& rect) const noexcept;
        void clear() const noexcept;
        void present() const noexcept;
        void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) const noexcept;
        void setDrawColor(const SDL::Color& color) const noexcept;

    private:
        SDL_Renderer* renderer;
    };

    template<size_t N>
    void Renderer::renderLines(const std::array<SDL::FPoint, N>& vertices) const noexcept {
        SDL_RenderLines(this->renderer, vertices.data(), N);
    }

    template<size_t N>
    void Renderer::renderPoints(const std::array<SDL::FPoint, N>& vertices) const noexcept {
        SDL_RenderPoints(this->renderer, vertices.data(), N);
    }
}
