#define SDL_MAIN_USE_CALLBACKS 1

#include <array>
#include <memory>
#include <SDL3/SDL_main.h>

#include "init.hpp"
#include "renderer.hpp"
#include "texture.hpp"
#include "window.hpp"
#include "window_flag.hpp"

struct AppState {
    std::unique_ptr<SDL::Window> window;
    std::unique_ptr<SDL::Renderer> renderer;
};

SDL_AppResult SDL_AppInit(void** appstate, const int argc, char* argv[]) {
    *appstate = nullptr;

    SDL::init(SDL::InitFlag::Video | SDL::InitFlag::Audio);

    auto window = std::make_unique<SDL::Window>("Hello, SDL3!", 800, 600, SDL::WindowFlag::None);
    auto renderer = std::make_unique<SDL::Renderer>(*window, "");

    renderer->setVSync(SDL::Renderer::VSync::Enabled);
    window->show();

    *appstate = new AppState{
        .window = std::move(window),
        .renderer = std::move(renderer),
    };

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    const auto app = static_cast<AppState*>(appstate);

    const SDL::Renderer& renderer = *app->renderer;

    renderer.setDrawColor(0, 0, 0, 255);
    renderer.clear();
    renderer.setDrawColor(255, 0, 0, 255);

    const SDL::Texture texture = renderer.createTexture(SDL::PixelFormat::RGBA8888, SDL::TextureAccess::Static, 200, 200);

    constexpr SDL::Vertex vertices[3] = {
        { .position = SDL::FPoint{ 100.0f, 100.0f }, .color = SDL::FColor{ 255, 0, 0, 255 } },
        { .position = SDL::FPoint{ 200.0f, 100.0f }, .color = SDL::FColor{ 255, 0, 0, 255 } },
        { .position = SDL::FPoint{ 150.0f, 200.0f }, .color = SDL::FColor{ 255, 0, 0, 255 } },
    };
    renderer.renderGeometry(nullptr, vertices, 3, nullptr, 0);

    const std::array<SDL::Vertex, 3> verticesArray{
        SDL::Vertex{ .position = SDL::FPoint{ 100.0f, 300.0f }, .color = SDL::FColor{ 255, 0, 0, 255 } },
        SDL::Vertex{ .position = SDL::FPoint{ 200.0f, 300.0f }, .color = SDL::FColor{ 255, 0, 0, 255 } },
        SDL::Vertex{ .position = SDL::FPoint{ 150.0f, 400.0f }, .color = SDL::FColor{ 255, 0, 0, 255 } },
    };
    renderer.renderGeometry(nullptr, verticesArray);

    renderer.renderRect({ .x = 300.0f, .y = 100.0f, .w = 100.0f, .h = 100.0f });
    renderer.renderFillRect({ .x = 450.0f, .y = 100.0f, .w = 100.0f, .h = 100.0f });

    renderer.renderPoint(500.0f, 300.0f);
    renderer.renderLine(300.0f, 300.0f, 400.0f, 400.0f);

    constexpr std::array lines{ SDL::FPoint{450.0f, 300.0f}, SDL::FPoint{550.0f, 400.0f},
                                SDL::FPoint{500.0f, 350.0f}, SDL::FPoint{550.0f, 350.0f} };
    renderer.renderLines(lines);

    constexpr std::array points{ SDL::FPoint{550.0f, 300.0f},
                                 SDL::FPoint{550.0f, 350.0f},
                                 SDL::FPoint{500.0f, 350.0f} };
    renderer.renderPoints(points);

    SDL_FRect r;
    r.w = 100;
    r.h = 50;

    r.x = SDL_rand(500);
    r.y = SDL_rand(500);

    renderer.setRenderTarget(texture);
    renderer.setDrawColor(0, 0, 0, 255);
    renderer.setDrawColor(0xFF, 0x00, 0x00, 0xFF);
    renderer.renderFillRect(r);
    renderer.setRenderTarget();
    renderer.renderTexture(texture);

    renderer.present();

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, const SDL_AppResult result) {
    const auto app = static_cast<AppState*>(appstate);
    delete app;
}
