#include "Entity.h"


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace MemoGL {
    void Entity::updateMVP() {
        model = transform->getTransformation();
        mvp = proj * view * model;
    }

    void Entity::removeChild(std::shared_ptr<Entity> entity) {
        if (!entity) return;

        entity->getTransform()->setParent(nullptr);

        //TODO Remove the child from the list
    }

    void Entity::addChild(std::shared_ptr<Entity> entity) {
        if (!entity) return;

        entity->getTransform()->setParent(transform);
        children.push_back(entity);
    }
}