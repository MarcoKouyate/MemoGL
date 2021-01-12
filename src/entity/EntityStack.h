#pragma once
#include "Entity.h"
#include <vector>

namespace MemoGL {
    class EntityStack {
    public:
        EntityStack();
        ~EntityStack();

        void pushLayer(std::shared_ptr<Entity> entity);
        void popLayer(std::shared_ptr<Entity> entity);

        void pushOverlay(std::shared_ptr<Entity> overlay);
        void popOverlay(std::shared_ptr<Entity> overlay);

        void clear();

        std::vector<std::shared_ptr<Entity>>::iterator begin() { return entities.begin(); }
        std::vector<std::shared_ptr<Entity>>::iterator end() { return entities.end(); }
        std::vector<std::shared_ptr<Entity>>::reverse_iterator rbegin() { return entities.rbegin(); }
        std::vector<std::shared_ptr<Entity>>::reverse_iterator rend() { return entities.rend(); }

        std::vector<std::shared_ptr<Entity>>::const_iterator begin() const { return entities.begin(); }
        std::vector<std::shared_ptr<Entity>>::const_iterator end()	const { return entities.end(); }
        std::vector<std::shared_ptr<Entity>>::const_reverse_iterator rbegin() const { return entities.rbegin(); }
        std::vector<std::shared_ptr<Entity>>::const_reverse_iterator rend() const { return entities.rend(); }

    private:
        std::vector<std::shared_ptr<Entity>> entities;
        unsigned int insertIndex = 0;
    };
}