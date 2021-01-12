#include "EntityStack.h"

namespace MemoGL {

    void EntityStack::pushLayer(std::shared_ptr<Entity> entity) {
        entities.emplace(entities.begin() + insertIndex, entity);
        insertIndex++;
        entity->onAttach();
    }

    void EntityStack::pushOverlay(std::shared_ptr<Entity> overlay) {
        entities.emplace_back(overlay);
        overlay->onAttach();
    }


    void EntityStack::popLayer(std::shared_ptr<Entity> entity) {
        auto it = std::find(entities.begin(), entities.begin() + insertIndex, entity);

        if (it != entities.end()) {
            entity->onDetach();
            entities.erase(it);
            insertIndex--;
        }
    }

    void EntityStack::popOverlay(std::shared_ptr<Entity> overlay) {
        auto it = std::find(entities.begin() + insertIndex, entities.end(), overlay);

        if (it != entities.end()) {
            overlay->onDetach();
            entities.erase(it);
        }
    }


    void EntityStack::clear() {
        for (auto entity : entities) {
            entity->onDetach();
        }
        
        insertIndex = 0;
        entities.clear();
    }


    EntityStack::EntityStack() {

    }

    EntityStack::~EntityStack() {
        clear();
    }
}