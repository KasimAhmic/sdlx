#pragma once

namespace SDL {
    /**
     * @brief A simple wrapper around a pointer to an SDL resource, such as an SDL_Renderer or SDL_Texture. This class
     *        does not manage the lifetime of the resource; it is the responsibility of the caller to ensure that the
     *        resource remains valid for the duration of the ResourceRef's existence.
     *
     * @tparam T The type of the resource being referenced. This should be a pointer type, such as SDL_Renderer*.
     */
    template <typename T>
    class ResourceRef {
    public:
        explicit ResourceRef(T* resource): resource(resource) {}
        ~ResourceRef() = default;

        [[nodiscard]] T* get() const { return this->resource; }

        explicit operator bool() const { return this->resource != nullptr; }

    private:
        T* resource;
    };
}
