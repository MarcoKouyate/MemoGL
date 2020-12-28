#pragma once
#include "Event.h"
#include <sstream>

namespace MemoGL {
    class AppTickEvent : public Event {
    public:
        AppTickEvent() = default;

        EVENT_CLASS_CATEGORY(Application);
        EVENT_CLASS_TYPE(AppTick);
    };

    class AppUpdateEvent : public Event {
    public:
        AppUpdateEvent() = default;

        EVENT_CLASS_CATEGORY(Application);
        EVENT_CLASS_TYPE(AppUpdate);
    };

    class AppRenderEvent : public Event {
    public:
        AppRenderEvent() = default;

        EVENT_CLASS_CATEGORY(Application);
        EVENT_CLASS_TYPE(AppRender);
    };
}