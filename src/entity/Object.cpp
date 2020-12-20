#include "Object.h"
#include "imgui.h"

namespace MemoGL {

    void Object::render(IRenderer& renderer) {

        if (!vao) {
            vao = renderer.createVertexArray();
            vao->push(vertices, indices);
        }

        if (vao && shader) {
            shader->bind();
            vao->bind();

            renderer.draw();

            vao->unbind();
            shader->unbind();
        }

        renderChildren(renderer);
    }

    void Object::update(float deltatime) {

    }

    void Object::imgui() {
        ImGui::Text("Hello from object");
        imguiChildren();
    }

    Object::Object(std::shared_ptr<Shader> shader) : 
        shader(shader), vao(nullptr)
    {
        vertices = {
            Vertex2D(glm::vec2(-0.5, -0.5), glm::vec2(0, 0), glm::vec3(1, 0, 0)),
            Vertex2D(glm::vec2(0.5, -0.5), glm::vec2(1, 0), glm::vec3(0, 1, 0)),
            Vertex2D(glm::vec2(0.5, 0.5), glm::vec2(1, 1), glm::vec3(0, 0, 1)),
            Vertex2D(glm::vec2(-0.5, 0.5), glm::vec2(0, 1), glm::vec3(1, 1, 1))
        };

        indices = {
            0, 1, 2,
            2, 3, 0
        };

        proj = glm::ortho(-2.0f, 2.0f, -1.125f, 1.125f, -1.0f, 1.0f);
        view = glm::translate(glm::mat4(1.0f), glm::vec3(camera_position_x, camera_position_y, 0));
        model = glm::translate(glm::mat4(1.0f), translationA);

        glm::mat4 mvp = proj * view * model;

        shader->bind();
        shader->setUniform4f("u_Color", 0.8f, 0.5f, 0.3f, 1.0f);
        shader->setUniformMat4f("u_MVP", mvp);
        shader->setUniform1i("u_Texture_Slot", 0);
    }

    Object::~Object() {
    }
}