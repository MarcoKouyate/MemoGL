#pragma once
#include "graphics/renderer/IRenderer.h"

namespace MemoGL {
    class Entity
    {
    public:
        virtual ~Entity() = default;
        virtual void update(float deltatime) {}
        virtual void render(IRenderer& renderer) { renderChildren(renderer); };
        virtual void imgui() { imguiChildren(); };

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


        void renderChildren(IRenderer& renderer) {
            for (auto child : children) {
                child->render(renderer);
            }
        }

        void imguiChildren() {
            for (auto child : children) {
                child->imgui();
            }
        }
    };


}