#pragma once
#include "graphics/renderer/IRenderer.h"
#include "events/Event.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

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

        virtual void setPosition(float x, float y) {
            setPosition(glm::vec2(x, y));
        }

        virtual void setPosition(glm::vec2 value) {
            for (const auto& child : children) {
                glm::vec2 offset = child->position - position;
                child->setPosition(value + offset);
            }

            position = value;
            update();
        }

        virtual void setScale(float x, float y) {
            setScale(glm::vec2(x, y));
        }

        virtual void setScale(glm::vec2 value) {
            for (const auto& child : children) {
                child->setScale(value);
            }

            scale = value;
            update();
        }

        virtual void translate(float x, float y) {
            setPosition(position.x + x, position.y + y);
        }

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

        virtual void update() {
            model = glm::scale(glm::mat4(1.0f), glm::vec3(scale.x, scale.y, 1.0f));
            model = glm::translate(model, glm::vec3(position.x, position.y, 0));
            mvp = proj * view * model;
        }

    protected:
        glm::mat4 model;
        glm::mat4 proj;
        glm::mat4 view;
        glm::mat4 mvp;

        glm::vec2 position;
        glm::vec2 scale;

        std::vector<std::shared_ptr<Entity>> children;
    };


}
