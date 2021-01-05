#include "Layer.h"

namespace MemoGL {
    void Layer::onAttach() {}

    void Layer::onDetach() {}

    void Layer::onUpdate() {}

    void Layer::onEvent(Event& e) {}

    Layer::Layer(const std::string& debugName) : 
        debugName(debugName), isEnabled(true) {}

    Layer::~Layer() {}
}