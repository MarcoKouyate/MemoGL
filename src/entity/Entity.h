#pragma once
#include "graphics/renderer/IRenderer.h"
#include "events/Event.h"

namespace MemoGL {
    class Entity
    {
    public:
        virtual ~Entity() = default;
        virtual void onAttach() {}
        virtual void onDetach() {}

        virtual void update(float deltatime) {}
        virtual void render() {  };
        virtual void imgui() { };
        virtual void onEvent(Event& e) { };

        std::vector<std::shared_ptr<Entity>> getChildren() const {
            return children;
        }

        void addChild(std::shared_ptr<Entity> entity) {
            if (entity) {
                children.push_back(entity);
            }
        }

        void removeChild(std::shared_ptr<Entity> entity) {
            if (entity) {
                //TODO Remove child from entity
            }
        }

    protected:
        std::vector<std::shared_ptr<Entity>> children;
    };


}
