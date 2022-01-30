#include "Transform.h"

namespace MemoGL {
    glm::mat4 Transform::getTransformation() const {
        glm::mat4 model = glm::mat4(1.0f);

        if (parent) model = parent->getTransformation();

        model = glm::scale(model, glm::vec3(scale.x, scale.y, 1.0f));
        model = glm::translate(model, glm::vec3(position.x, position.y, 0));
        return model;
    }

    void Transform::setPosition(float x, float y) {
        setPosition(glm::vec2(x, y));
    }


    void Transform::setPosition(glm::vec2 value){
        position = value;
    }

    void Transform::setScale(float x, float y) {
        setScale(glm::vec2(x, y));
    }

    void Transform::setScale(glm::vec2 value) {
        scale = value;
    }

    void Transform::translate(float x, float y) {
        translate(glm::vec2(x, y));
    }

    void Transform::translate(glm::vec2 value) {
        position = position + value;
    }

    void Transform::setParent(std::shared_ptr<Transform> newParent) {
        parent = newParent;
    }
}