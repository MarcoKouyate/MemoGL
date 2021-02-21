#pragma once
#include "graphics/buffer/Shader.h"
#include "graphics/buffer/VertexArray.h"
#include "graphics/buffer/Vertex2D.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Entity.h"

#include <memory>

namespace MemoGL {
    class Object : public Entity {
        public:
            void render() override;
            void update(float deltatime) override;
            void position(float x, float y);

        private:
            void binders(std::shared_ptr<IRenderer> renderer);
            void unbinders();

        protected:
            Object();

            std::shared_ptr<Shader> shader = nullptr;
            std::shared_ptr<VertexArray> vao = nullptr;

            std::vector<Vertex2D> vertices;
            std::vector<unsigned int> indices;

            glm::mat4 proj;
            glm::mat4 view;
            glm::mat4 model;
            glm::mat4 mvp;



            float camera_position_x = 0;
            float camera_position_y = 0;

            std::string vertexShader;
            std::string fragmentShader;
    };
}