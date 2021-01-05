#include "ExampleLayer.h"
#include "tools/Log.h"

namespace MemoGL {

    ExampleLayer::ExampleLayer() : 
        Layer("Example Layer")
    {}

    ExampleLayer::~ExampleLayer()
    {}

    void ExampleLayer::onAttach() {
        MEMOGL_LOG_INFO("{0} attach", debugName);
    }

    void ExampleLayer::onDetach() {
        MEMOGL_LOG_INFO("{0} detach", debugName);
    }

    void ExampleLayer::onEvent(Event& e) {
        MEMOGL_LOG_INFO("{0} : {1}", debugName, e);
    }

    void ExampleLayer::onUpdate() {
        MEMOGL_LOG_INFO("{0} update", debugName);
    }
}