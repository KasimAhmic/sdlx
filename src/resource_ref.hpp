#pragma once

namespace SDL {
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
