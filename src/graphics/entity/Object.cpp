#include "Object.h"
#include "imgui.h"

namespace MemoGL {

    void Object::render(IRenderer& renderer) {
        renderChildren(renderer);

        if (shader) {
            shader->bind();
        }
            
        if (vertices) {
            vertices->bind();
        }
            
        renderer.draw();

        if (vertices) {
            vertices->unbind();
        }

        if (shader) {
            shader->unbind();
        }
    }

    void Object::update(float deltatime) {

    }

    void Object::imgui() {
        ImGui::Text("Hello from object");
        imguiChildren();
    }

    Object::Object(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> vertices) : 
        shader(shader), vertices(vertices) 
    {

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