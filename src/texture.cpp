#include "texture.hpp"

#include "blend_mode.hpp"
#include "renderer.hpp"
#include "error.hpp"

SDL::Texture::Texture(const SDL::Renderer &renderer, SDL::PixelFormat format, SDL::TextureAccess access, int width, int height) {
    this->texture = SDL_CreateTexture(renderer.get(),
                                      static_cast<SDL_PixelFormat>(format),
                                      static_cast<SDL_TextureAccess>(access),
                                      width,
                                      height);

    if (!this->texture) {
        throw SDL::Error("Failed to create texture");
    }
}

SDL::Texture::Texture(const SDL::Renderer &renderer, const SDL::Surface &surface) {
    this->texture = SDL_CreateTextureFromSurface(renderer.get(), surface.get());

    if (!this->texture) {
        throw SDL::Error("Failed to create texture");
    }
}

SDL::Texture::Texture(const SDL::Renderer &renderer, const SDL::PropertiesId properties) {
    this->texture = SDL_CreateTextureWithProperties(renderer.get(), properties);

    if (!this->texture) {
        throw SDL::Error("Failed to create texture");
    }
}

SDL::Texture::~Texture() {
    SDL_DestroyTexture(this->texture);
}

SDL::ResourceRef<SDL_Renderer> SDL::Texture::getRenderer() const noexcept {
    return SDL::ResourceRef(SDL_GetRendererFromTexture(this->texture));
}

SDL::PropertiesId SDL::Texture::getProperties() const noexcept {
    return SDL_GetTextureProperties(this->texture);
}

SDL::FSize SDL::Texture::getSize() const noexcept {
    SDL::FSize size{};
    SDL_GetTextureSize(this->texture, &size.width, &size.height);
    return size;
}

SDL::ResourceRef<SDL_Palette> SDL::Texture::getPalette() const noexcept {
    return SDL::ResourceRef(SDL_GetTexturePalette(this->texture));
}

void SDL::Texture::setPalette() const noexcept {
}

SDL::Color SDL::Texture::getColorMod() const noexcept {
    SDL::Color color{};
    SDL_GetTextureColorMod(this->texture, &color.r, &color.g, &color.b);
    return color;
}

void SDL::Texture::setColorMod(const uint8_t r, const uint8_t g, const uint8_t b) const noexcept {
    SDL_SetTextureColorMod(this->texture, r, g, b);
}

void SDL::Texture::setColorMod(const SDL::Color &color) const noexcept {
    SDL_SetTextureColorMod(this->texture, color.r, color.g, color.b);
}

SDL::FColor SDL::Texture::getColorModFloat() const noexcept {
    SDL_FColor color{};
    SDL_GetTextureColorModFloat(this->texture, &color.r, &color.g, &color.b);
    return color;
}

void SDL::Texture::setColorModFloat(float r, float g, float b) const noexcept {
    SDL_SetTextureColorModFloat(this->texture, r, g, b);
}

void SDL::Texture::setColorModFloat(const SDL::FColor &color) const noexcept {
    SDL_SetTextureColorModFloat(this->texture, color.r, color.g, color.b);
}

uint8_t SDL::Texture::getAlphaMod() const noexcept {
    uint8_t alpha{};
    SDL_GetTextureAlphaMod(this->texture, &alpha);
    return alpha;
}

void SDL::Texture::setAlphaMod(const uint8_t a) const noexcept {
    SDL_SetTextureAlphaMod(this->texture, a);
}

float SDL::Texture::getAlphaModFloat() const noexcept {
    float alpha{};
    SDL_GetTextureAlphaModFloat(this->texture, &alpha);
    return alpha;
}

void SDL::Texture::setAlphaModFloat(const float a) const noexcept {
    SDL_SetTextureAlphaModFloat(this->texture, a);
}

void SDL::Texture::getBlendMode() const noexcept {
    uint32_t blendMode{};
    SDL_GetTextureBlendMode(this->texture, &blendMode);
}

void SDL::Texture::setBlendMode() const noexcept {
}

void SDL::Texture::getScaleMode() const noexcept {
}

void SDL::Texture::setScaleMode() const noexcept {
}

void SDL::Texture::update() const noexcept {
}

void SDL::Texture::updateYUV() const noexcept {
}

void SDL::Texture::updateNV() const noexcept {
}

void SDL::Texture::lock() const noexcept {
}

void SDL::Texture::lockToSurface() const noexcept {
}

void SDL::Texture::unlock() const noexcept {
}
