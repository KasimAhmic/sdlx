#include "window.hpp"

#include <stdexcept>
#include <utility>

#include "error.hpp"
#include "pixel_format.hpp"
#include "progress_state.hpp"
#include "sdl.hpp"

SDL::Window::Window(const std::string& title, const int w, const int h, const SDL::WindowFlag flags) {
    this->window = SDL_CreateWindow(title.c_str(), w, h, SDL::Internal::toUnderlying(flags));

    if (!this->window) {
        throw SDL::Error("Failed to create window");
    }
}

SDL::Window::Window(const SDL_PropertiesID props) {
    this->window = SDL_CreateWindowWithProperties(props);

    if (!this->window) {
        throw SDL::Error("Failed to create window from properties");
    }
}

SDL::Window::Window(const SDL::ResourceRef<SDL_Window>& parent, const int offsetX, const int offsetY, const int w, const int h, const SDL::WindowFlag flags) {
    this->window = SDL_CreatePopupWindow(parent.get(), offsetX, offsetY, w, h, SDL::Internal::toUnderlying(flags));

    if (!this->window) {
        throw SDL::Error("Failed to create window from parent");
    }
}

SDL::Window::~Window() {
    SDL_DestroyWindow(this->window);
}

SDL::Window::Window(Window&& other) noexcept {
    this->window = std::exchange(other.window, nullptr);
}

SDL::Window& SDL::Window::operator=(Window&& other) noexcept {
    if (this != &other) {
        if (this->window) {
            SDL_DestroyWindow(this->window);
        }

        this->window = std::exchange(other.window, nullptr);
    }

    return *this;
}

SDL::ResourceRef<SDL_Window> SDL::Window::getFromID(const SDL::WindowId id) noexcept {
    return SDL::ResourceRef(SDL_GetWindowFromID(id));
}

std::vector<SDL::ResourceRef<SDL_Window>> SDL::Window::getWindows() noexcept {
    int count{};
    SDL_Window** windows = SDL_GetWindows(&count);

    std::vector<SDL::ResourceRef<SDL_Window>> windowsList{};
    windowsList.reserve(count);

    for (int i = 0; i < count; ++i) {
        if (windows[i]) {
            windowsList.emplace_back(windows[i]);
        }
    }

    SDL_free(windows);

    return windowsList;
}

SDL_WindowID SDL::Window::getId() const noexcept {
    return SDL_GetWindowID(this->window);
}

std::string SDL::Window::getTitle() const noexcept {
    return SDL_GetWindowTitle(this->window);
}

SDL::Point SDL::Window::getPosition() const noexcept {
    SDL::Point point{};
    SDL_GetWindowPosition(this->window, &point.x, &point.y);
    return point;
}

SDL::Point SDL::Window::getSize() const noexcept {
    SDL::Point point{};
    SDL_GetWindowSize(this->window, &point.x, &point.y);
    return point;
}

SDL::WindowFlag SDL::Window::getFlags() const noexcept {
    return static_cast<SDL::WindowFlag>(SDL_GetWindowFlags(this->window));
}

float SDL::Window::getPixelDensity() const noexcept {
    return SDL_GetWindowPixelDensity(this->window);
}

float SDL::Window::getDisplayScale() const noexcept {
    return SDL_GetWindowDisplayScale(this->window);
}

auto SDL::Window::getFullscreenMode() const noexcept {
    return SDL_GetWindowFullscreenMode(this->window);
}

void* SDL::Window::getICCProfile(size_t* size) const noexcept {
    return SDL_GetWindowICCProfile(this->window, size);
}

SDL::PixelFormat SDL::Window::getPixelFormat() const noexcept {
    return static_cast<SDL::PixelFormat>(SDL_GetWindowPixelFormat(this->window));
}

SDL::ResourceRef<SDL_Window> SDL::Window::getParent() const noexcept {
    return SDL::ResourceRef(SDL_GetWindowParent(this->window));
}

SDL::PropertiesId SDL::Window::getProperties() const noexcept {
    return SDL_GetWindowProperties(this->window);
}

SDL::Rect SDL::Window::getSafeArea() const noexcept {
    SDL::Rect rect{};
    SDL_GetWindowSafeArea(this->window, &rect);
    return rect;
}

SDL::FRange SDL::Window::getAspectRatio() const noexcept {
    SDL::FRange aspectRatio{};
    SDL_GetWindowAspectRatio(this->window, &aspectRatio.min, &aspectRatio.max);
    return aspectRatio;
}

SDL::WindowBorders SDL::Window::getBordersSize() const noexcept {
    int top{}, left{}, bottom{}, right{};
    SDL_GetWindowBordersSize(this->window, &top, &left, &bottom, &right);
    return {top, left, bottom, right};
}

SDL::Size SDL::Window::getSizeInPixels() const noexcept {
    SDL::Size size{};
    SDL_GetWindowSizeInPixels(this->window, &size.width, &size.height);
    return size;
}

SDL::Size SDL::Window::getMinimumSize() const noexcept {
    SDL::Size size{};
    SDL_GetWindowMinimumSize(this->window, &size.width, &size.height);
    return size;
}

SDL::Size SDL::Window::getMaximumSize() const noexcept {
    SDL::Size size{};
    SDL_GetWindowMaximumSize(this->window, &size.width, &size.height);
    return size;
}

SDL::ResourceRef<SDL_Surface> SDL::Window::getSurface() const noexcept {
    return SDL::ResourceRef(SDL_GetWindowSurface(this->window));
}

int SDL::Window::getSurfaceVSync() const noexcept {
    int vsync{};
    SDL_GetWindowSurfaceVSync(this->window, &vsync);
    return vsync;
}

bool SDL::Window::getKeyboardGrab() const noexcept {
    return SDL_GetWindowKeyboardGrab(this->window);
}

bool SDL::Window::getMouseGrab() const noexcept {
    return SDL_GetWindowMouseGrab(this->window);
}

// TODO: Validate this method is correct
std::optional<SDL::Rect> SDL::Window::getMouseRect() const noexcept {
    if (const SDL_Rect* rect = SDL_GetWindowMouseRect(this->window)) {
        return *rect;
    }

    return std::nullopt;
}

float SDL::Window::getOpacity() const noexcept {
    return SDL_GetWindowOpacity(this->window);
}

SDL::ProgressState SDL::Window::getProgressState() const noexcept {
    return static_cast<SDL::ProgressState>(SDL_GetWindowProgressState(this->window));
}

float SDL::Window::getProgressValue() const noexcept {
    return SDL_GetWindowProgressValue(this->window);
}

void SDL::Window::show() const {
    if (!SDL_ShowWindow(this->window)) {
        throw SDL::Error("Failed to show window");
    }
}
