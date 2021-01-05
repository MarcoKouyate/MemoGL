#pragma once
#include "Layer.h"

namespace MemoGL {
    class ExampleLayer : public Layer
    {
    public:
        ExampleLayer();
        ~ExampleLayer();

        void onAttach();
        void onDetach();

        void onUpdate();
        void onEvent(Event& e);

    private:

    };
}