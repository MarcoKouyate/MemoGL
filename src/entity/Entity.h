#pragma once
#include "graphics/renderer/IRenderer.h"
#include <vector>
#include <memory>

namespace MemoGL {
    class Entity
    {
    public:
        virtual ~Entity() = default;
        virtual void update(float deltatime) = 0;
        virtual void render(IRenderer& renderer) = 0;
        virtual void imgui() = 0;

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