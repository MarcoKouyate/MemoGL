#include "Object.h"
#include "imgui.h"
#include "GameEngine.h"

namespace MemoGL {
    Object::Object() {
        proj = glm::ortho(-2.0f, 2.0f, -1.125f, 1.125f, -1.0f, 1.0f);
        view = glm::translate(glm::mat4(1.0f), glm::vec3(camera_position_x, camera_position_y, 0));
        model = glm::mat4(1.0f);

        mvp = proj * view * model;
    }

    void Object::update(float deltatime) {
        
    }

    void Object::render() {
        std::shared_ptr<IRenderer> renderer = GameEngine::get()->getGraphicsEngine()->getRenderer();

        if (!shader) {
            shader = renderer->createShader();
            shader->init(vertexShader, fragmentShader);
            shader->bind();
            shader->setUniform4f("u_Color", 0.8f, 0.5f, 0.3f, 1.0f);
            shader->setUniform1i("u_Texture_Slot", 0);
            shader->unbind();
        }

        if (!vao) {
            vao = renderer->createVertexArray();
            vao->push(vertices, indices);
        }

        if (vao && shader) {
            shader->bind();
            vao->bind();
            shader->setUniformMat4f("u_MVP", mvp);
            renderer->draw();

            vao->unbind();
            shader->unbind();
        }
    }

    void Object::position(float x, float y) {
        model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0));
        mvp = proj * view * model;
    }
}