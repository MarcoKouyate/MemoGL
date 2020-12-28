#pragma once
#include "tools/CommonMacros.h"

#include <string>
#include <functional>

namespace MemoGL {

 // TO TRY on other compilers than the one in Visual Studio if it doesn't work :
 // > remove the concatenation of the first line of the EVENT_CLASS_TYPE. 
 // > Instead of return EventType::##type;   it's return  EventType::type;

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::type; }\
                               virtual EventType getEventType() const override { return getStaticType(); }\
                               virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; };

    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, 
        MousePressed, MouseReleased, MouseMoved, MouseScrolled
    };

    // Bit field. Use it to assign multiple categories using one byte data
    enum EventCategory
    {
        None = 0,
        Application   = BIT(0),
        Input         = BIT(1),
        Keyboard      = BIT(2),
        Mouse         = BIT(3),
        MouseButton   = BIT(4),
        Window        = BIT(5)
    };

    class Event {
        public:
            virtual EventType getEventType() const = 0;
            virtual const char* getName() const = 0;
            virtual int getCategoryFlags() const = 0;
            virtual std::string toString() const { return getName(); }

            inline bool isInCategory(EventCategory category) {
                return getCategoryFlags() & category;
            }

        protected:
            bool handled = false;
    };

    class EventDispatcher {
        template<typename T>
        using EventFunction = std::function<bool(T&)>;

        public:
            EventDispatcher(Event& targetEvent) : targetEvent(targetEvent) {}

            template <typename T>
            bool dispatch(EventFunction<T> func) {
                if (targetEvent.getEventType() == T::getStaticType()) {
                    targetEvent = func(*(T*)&targetEvent);
                    return true;
                }

                return false;
            }

        private:
            Event& targetEvent;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.toString();
    }
}