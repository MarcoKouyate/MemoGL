#include "File.h"

namespace MemoGL {
    std::string readFile(const std::string& filepath) {
        std::ifstream in(filepath);
        std::stringstream buffer;
        buffer << in.rdbuf();
        std::string contents(buffer.str());
        return contents;
    }
}