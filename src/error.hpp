#pragma once

#include <stdexcept>
#include <string>

namespace SDL {
    class Error : public std::runtime_error {
    public:
        explicit Error();
        explicit Error(const std::string& message);
    };
}
