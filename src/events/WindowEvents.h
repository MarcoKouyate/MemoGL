#pragma once
#include "Event.h"
#include <sstream>

namespace MemoGL {
    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) :
            width(width), height(height)
        {}

        std::string toString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: (" << width << ", " << height << ")";
            return ss.str();
        }

        inline unsigned int getWidth() const { return width; }
        inline unsigned int getHeight() const { return height; }

        EVENT_CLASS_CATEGORY(Window);
        EVENT_CLASS_TYPE(WindowResize);

    private:
        unsigned int width, height;
    };

    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_CATEGORY(Window);
        EVENT_CLASS_TYPE(WindowClose);
    };

    class WindowFocusEvent : public Event {
    public:
        WindowFocusEvent() = default;

        EVENT_CLASS_CATEGORY(Window);
        EVENT_CLASS_TYPE(WindowFocus);
    };

    class WindowLostFocusEvent : public Event {
    public:
        WindowLostFocusEvent() = default;

        EVENT_CLASS_CATEGORY(Window);
        EVENT_CLASS_TYPE(WindowLostFocus);
    };

    class WindowMovedEvent : public Event {
    public:
        WindowMovedEvent() = default;

        EVENT_CLASS_CATEGORY(Window);
        EVENT_CLASS_TYPE(WindowMoved);
    };
}