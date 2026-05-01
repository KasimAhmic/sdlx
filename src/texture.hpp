#pragma once

#include <SDL3/SDL_render.h>

#include "pixel_format.hpp"
#include "resource_ref.hpp"
#include "sdl.hpp"
#include "surface.hpp"

namespace SDL {
    class Renderer;

    enum class TextureAccess : int {
        Static    = SDL_TEXTUREACCESS_STATIC,
        Streaming = SDL_TEXTUREACCESS_STREAMING,
        Target    = SDL_TEXTUREACCESS_TARGET,
    };

    enum class TextureAddressMode : int {
        Invalid = SDL_TEXTURE_ADDRESS_INVALID,
        Auto    = SDL_TEXTURE_ADDRESS_AUTO,
        Clamp   = SDL_TEXTURE_ADDRESS_CLAMP,
        Wrap    = SDL_TEXTURE_ADDRESS_WRAP,

    };

    enum class RendererLogicalPresentation : int {
        Disabled     = SDL_LOGICAL_PRESENTATION_DISABLED,
        Stretch      = SDL_LOGICAL_PRESENTATION_STRETCH,
        Letterbox    = SDL_LOGICAL_PRESENTATION_LETTERBOX,
        Overscan     = SDL_LOGICAL_PRESENTATION_OVERSCAN,
        IntegerScale = SDL_LOGICAL_PRESENTATION_INTEGER_SCALE,
    };

    class Texture {
    public:
        explicit Texture(const SDL::Renderer& renderer, SDL::PixelFormat format, SDL::TextureAccess access, int width, int height);
        explicit Texture(const SDL::Renderer& renderer, const SDL::Surface& surface);
        explicit Texture(const SDL::Renderer& renderer, SDL::PropertiesId properties);
        ~Texture();

        [[nodiscard]] SDL_Texture* get() const { return this->texture; }

        [[nodiscard]] ResourceRef<SDL_Renderer> getRenderer() const noexcept;
        [[nodiscard]] SDL::PropertiesId getProperties() const noexcept;
        [[nodiscard]] SDL::FSize getSize() const noexcept;

        [[nodiscard]] SDL::ResourceRef<SDL_Palette> getPalette() const noexcept;
        void setPalette() const noexcept;

        [[nodiscard]] SDL::Color getColorMod() const noexcept;
        void setColorMod(uint8_t r, uint8_t g, uint8_t b) const noexcept;
        void setColorMod(const SDL::Color& color) const noexcept;

        [[nodiscard]] SDL::FColor getColorModFloat() const noexcept;
        void setColorModFloat(float r, float g, float b) const noexcept;
        void setColorModFloat(const SDL::FColor& color) const noexcept;

        [[nodiscard]] uint8_t getAlphaMod() const noexcept;
        void setAlphaMod(uint8_t a) const noexcept;

        [[nodiscard]] float getAlphaModFloat() const noexcept;
        void setAlphaModFloat(float a) const noexcept;

        [[nodiscard]] void getBlendMode() const noexcept;
        void setBlendMode() const noexcept;

        [[nodiscard]] void getScaleMode() const noexcept;
        void setScaleMode() const noexcept;

        void update() const noexcept;
        void updateYUV() const noexcept;
        void updateNV() const noexcept;

        void lock() const noexcept;
        void lockToSurface() const noexcept;
        void unlock() const noexcept;


    private:
        SDL_Texture* texture{};
    };
}
