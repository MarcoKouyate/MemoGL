#pragma once
#include "events/Event.h"
#include <vector>

#include "components/Transform.h"

namespace MemoGL {
    class Entity
    {
    public:
        Entity() {
            /* TODO check if transform should be created with constructor 
            or with Attach() */
            transform = std::make_shared<Transform>();
        }

        virtual ~Entity() = default;
        virtual void onAttach() {}
        virtual void onDetach() {}

        virtual void update(float deltatime) {}
        virtual void render() {  };
        virtual void imgui() { };
        virtual void onEvent(Event& e) { };


        void addChild(std::shared_ptr<Entity> entity);
        void removeChild(std::shared_ptr<Entity> entity);


        void updateMVP();

        std::vector<std::shared_ptr<Entity>> getChildren() const {
            return children;
        }

        std::shared_ptr<Transform> getTransform() const {
            return transform;
        }

    protected:
        glm::mat4 model;
        glm::mat4 proj;
        glm::mat4 view;
        glm::mat4 mvp;


        std::shared_ptr<Transform> transform;
        std::vector<std::shared_ptr<Entity>> children;
    };


}
