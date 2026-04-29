#pragma once

#include <SDL3/SDL.h>

namespace SDL {
    struct WindowBorders {
        int top{};
        int left{};
        int bottom{};
        int right{};
    };

    template <typename T>
    struct BasicSize {
        T width{};
        T height{};
    };

    template <typename T>
    struct BasicRange {
        T min{};
        T max{};
    };

    using Size = BasicSize<int>;
    using FSize = BasicSize<float>;
    using Range = BasicRange<int>;
    using FRange = BasicRange<float>;

    // Aliased SDL types
    using WindowId = SDL_WindowID;
    using PropertiesId = SDL_PropertiesID;
    using Rect = SDL_Rect;
    using FRect = SDL_FRect;
    using Point = SDL_Point;
    using FPoint = SDL_FPoint;
    using Vertex = SDL_Vertex;
    using Color = SDL_Color;
    using FColor = SDL_FColor;
}
