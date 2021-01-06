#include "Object.h"
#include "imgui.h"


namespace MemoGL {
    Object::Object() {
        proj = glm::ortho(-2.0f, 2.0f, -1.125f, 1.125f, -1.0f, 1.0f);
        view = glm::translate(glm::mat4(1.0f), glm::vec3(camera_position_x, camera_position_y, 0));
        model = glm::translate(glm::mat4(1.0f), translationA);

        mvp = proj * view * model;
    }


    void Object::update(float deltatime) {

    }

    void Object::render(IRenderer& renderer) {
        if (!shader) {
            shader = renderer.createShader();
            shader->init(vertexShader, fragmentShader);
            shader->bind();
            shader->setUniform4f("u_Color", 0.8f, 0.5f, 0.3f, 1.0f);
            shader->setUniformMat4f("u_MVP", mvp);
            shader->setUniform1i("u_Texture_Slot", 0);
            shader->unbind();
        }

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

    void Object::imgui() {
        ImGui::Text("Hello from object");
        imguiChildren();
    }
}