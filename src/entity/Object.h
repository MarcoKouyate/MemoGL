#pragma once
#include "graphics/buffer/Shader.h"
#include "graphics/buffer/VertexArray.h"
#include "graphics/buffer/Vertex2D.h"

#include "Entity.h"
#include "graphics/renderer/IRenderer.h"

#include <memory>

namespace MemoGL {
    class Object : public Entity {
        public:
            void render() override;
            void update(float deltatime) override;

        private:
            void binders(std::shared_ptr<IRenderer> renderer);
            void unbinders();

        protected:
            Object();

            //buffers
            std::shared_ptr<Shader> shader = nullptr;
            std::shared_ptr<VertexArray> vao = nullptr;
            std::vector<Vertex2D> vertices;
            std::vector<unsigned int> indices;

            float camera_position_x = 0;
            float camera_position_y = 0;

            // shader
            std::string vertexShader;
            std::string fragmentShader;
    };
}