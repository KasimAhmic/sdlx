#pragma once

#include <utility>

namespace SDL::Internal {
    template <typename E>
    inline constexpr bool EnableBitmaskOperators = false;

    template <typename E>
    concept BitmaskEnum = std::is_enum_v<E> && EnableBitmaskOperators<E>;

    template <typename T>
    [[nodiscard]] constexpr std::underlying_type_t<T> toUnderlying(T flag) {
        return static_cast<std::underlying_type_t<T>>(flag);
    }
}

namespace SDL {
    template <Internal::BitmaskEnum E>
    [[nodiscard]] constexpr E operator|(E a, E b) noexcept {
        return static_cast<E>(std::to_underlying(a) | std::to_underlying(b));
    }

    template <Internal::BitmaskEnum E>
    [[nodiscard]] constexpr E operator&(E a, E b) noexcept {
        return static_cast<E>(std::to_underlying(a) & std::to_underlying(b));
    }

    template <Internal::BitmaskEnum E>
    constexpr E& operator|=(E& a, E b) noexcept {
        return a = a | b;
    }

    template <Internal::BitmaskEnum E>
    constexpr E& operator&=(E& a, E b) noexcept {
        return a = a & b;
    }

    template <Internal::BitmaskEnum E>
    [[nodiscard]] constexpr E operator~(E value) noexcept {
        return static_cast<E>(~std::to_underlying(value));
    }
}
