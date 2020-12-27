#pragma once
#include "Event.h"
#include <sstream>

namespace MemoGL {
    class KeyEvent : public Event {
    public:
        inline int GetKeyCode() const { return keyCode; }

        EVENT_CLASS_CATEGORY(Keyboard | Input);

    protected:
        KeyEvent(int keyCode) : keyCode(keyCode) {}

        int keyCode;
    };


    class KeyPressedEvent : public KeyEvent {
        public:
            KeyPressedEvent(int keyCode, int repeatCount): 
                KeyEvent(keyCode), repeatCount(repeatCount) {
            }

            inline int getRepeatCount() const { return repeatCount; }

            std::string toString() const override {
                std::stringstream ss;
                ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyPressed);

        private:
            int repeatCount;
    };


    class KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

            std::string toString() const override {
                std::stringstream ss;
                ss << "KeyReleasedEvent: " << keyCode;
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyReleased);
    };
}