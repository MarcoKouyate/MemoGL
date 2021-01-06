#include "LayerStack.h"

namespace MemoGL {

    void LayerStack::pushLayer(Layer* layer) {
        layers.emplace(layers.begin() + insertIndex, layer);
        insertIndex++;
        layer->onAttach();
    }

    void LayerStack::pushOverlay(Layer* overlay) {
        layers.emplace_back(overlay);
        overlay->onAttach();
    }


    void LayerStack::popLayer(Layer* layer) {
        auto it = std::find(layers.begin(), layers.begin() + insertIndex, layer);

        if (it != layers.end()) {
            layer->onDetach();
            layers.erase(it);
            insertIndex--;
        }
    }

    void LayerStack::popOverlay(Layer* overlay) {
        auto it = std::find(layers.begin() + insertIndex, layers.end(), overlay);

        if (it != layers.end()) {
            overlay->onDetach();
            layers.erase(it);
        }
    }


    void LayerStack::clear() {
        for (auto layer : layers) {
            layer->onDetach();
            delete layer;
        }

        insertIndex = 0;
    }


    LayerStack::LayerStack(){

    }

    LayerStack::~LayerStack(){
        clear();
    }
}