#pragma once 
#include <string>
#include "events/Event.h"

namespace MemoGL {
    class Layer {
        public:
            Layer(const std::string& name = "Layer");
            virtual ~Layer();

            virtual void onAttach();
            virtual void onDetach();
            virtual void onUpdate();
            virtual void onEvent(Event& e);
            virtual void onImGui();

            inline const std::string getName() const { return debugName; }

        protected:
            std::string debugName;
            bool isEnabled = true;
    };
}