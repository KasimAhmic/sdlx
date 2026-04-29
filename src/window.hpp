#pragma once

#include <optional>
#include <string>
#include <vector>
#include <SDL3/SDL.h>

#include "pixel_format.hpp"
#include "progress_state.hpp"
#include "resource_ref.hpp"
#include "sdl.hpp"
#include "window_flag.hpp"

namespace SDL {
    class Window {
    public:
        explicit Window(const std::string&, int w, int h, SDL::WindowFlag flags);
        explicit Window(SDL_PropertiesID props);
        explicit Window(const SDL::ResourceRef<SDL_Window>& parent, int offsetX, int offsetY, int w, int h, SDL::WindowFlag flags);
        ~Window();

        Window(Window&&) noexcept;
        Window& operator=(Window&& other) noexcept;

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        [[nodiscard]] static SDL::ResourceRef<SDL_Window> getFromID(SDL::WindowId id) noexcept;
        [[nodiscard]] static std::vector<SDL::ResourceRef<SDL_Window>> getWindows() noexcept;

        [[nodiscard]] SDL::WindowId getId() const noexcept;
        [[nodiscard]] std::string getTitle() const noexcept;
        [[nodiscard]] SDL::Point getPosition() const noexcept;
        [[nodiscard]] SDL::Point getSize() const noexcept;
        [[nodiscard]] SDL::WindowFlag getFlags() const noexcept;
        [[nodiscard]] float getPixelDensity() const noexcept;
        [[nodiscard]] float getDisplayScale() const noexcept;
        [[nodiscard]] auto getFullscreenMode() const noexcept;
        [[nodiscard]] void* getICCProfile(size_t* size) const noexcept;
        [[nodiscard]] SDL::PixelFormat getPixelFormat() const noexcept;
        [[nodiscard]] SDL::ResourceRef<SDL_Window> getParent() const noexcept;
        [[nodiscard]] SDL::PropertiesId getProperties() const noexcept;
        [[nodiscard]] SDL::Rect getSafeArea() const noexcept;
        [[nodiscard]] SDL::FRange getAspectRatio() const noexcept;
        [[nodiscard]] SDL::WindowBorders getBordersSize() const noexcept;
        [[nodiscard]] SDL::Size getSizeInPixels() const noexcept;
        [[nodiscard]] SDL::Size getMinimumSize() const noexcept;
        [[nodiscard]] SDL::Size getMaximumSize() const noexcept;
        [[nodiscard]] SDL::ResourceRef<SDL_Surface> getSurface() const noexcept;
        [[nodiscard]] int getSurfaceVSync() const noexcept;
        [[nodiscard]] bool getKeyboardGrab() const noexcept;
        [[nodiscard]] bool getMouseGrab() const noexcept;
        [[nodiscard]] std::optional<SDL::Rect> getMouseRect() const noexcept;
        [[nodiscard]] float getOpacity() const noexcept;
        [[nodiscard]] SDL::ProgressState getProgressState() const noexcept;
        [[nodiscard]] float getProgressValue() const noexcept;

        [[nodiscard]] SDL_Window* get() const noexcept { return this->window; }

        // SDL_GetWindows
        void show() const;

    private:
        SDL_Window *window{};
    };
}
