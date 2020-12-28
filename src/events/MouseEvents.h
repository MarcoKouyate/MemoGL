#pragma once
#include "Event.h"
#include <sstream>

namespace MemoGL {
    class MouseButtonEvent : public Event {
    public:
        inline int getButton() const { return button; }

        EVENT_CLASS_CATEGORY(Mouse | MouseButton | Input);

    protected:
        MouseButtonEvent(int button) : button(button) {}

        int button;
    };

    class MousePressedEvent : public MouseButtonEvent {
        public:
            MousePressedEvent(int button) : MouseButtonEvent(button) {}

            std::string toString() const override {
                std::stringstream ss;
                ss << "MousePressedEvent: (" << button << ")";
                return ss.str();
            }

            EVENT_CLASS_TYPE(MousePressed);
    };

    class MouseReleasedEvent : public MouseButtonEvent {
    public:
        MouseReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseReleasedEvent: (" << button << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MousePressed);
    };

    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(int horizontal, int vertical) : 
            horizontal(horizontal), vertical(vertical) 
        {}

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: (" << horizontal << ", " << horizontal <<")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved);
        EVENT_CLASS_CATEGORY(Mouse | Input);

    private:
        int horizontal, vertical;
    };


    class MouseScrollEvent : public Event {
    public:
        MouseScrollEvent(unsigned int scroll) :
           scroll(scroll)
        {}

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseScrollEvent: (" << scroll << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled);
        EVENT_CLASS_CATEGORY(Mouse | Input);

    private:
        int scroll;
    };
}