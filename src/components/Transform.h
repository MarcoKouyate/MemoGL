#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <memory>


namespace MemoGL {
    class Transform {
        public:
            Transform() :
                position(glm::vec2(0)),
                scale(glm::vec2(1))
            {}

            glm::mat4 getTransformation() const;

            void setPosition(float x, float y);
            void setPosition(glm::vec2 value);
            void translate(float x, float y);
            void translate(glm::vec2 value);

            void setScale(float x, float y);
            void setScale(glm::vec2 value);

            void setParent(std::shared_ptr<Transform> newParent);

        private:
            glm::vec2 position;
            glm::vec2 scale;
            std::shared_ptr<Transform> parent;
    };
}