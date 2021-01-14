#pragma once
#include "events/inputs/GLFWInput.h"

namespace MemoGL {
    Input* Input::instance = nullptr;

    Input* Input::get() {
        if (!instance) {
            instance = new GLFWInput;
        }

        return instance;
    }
}