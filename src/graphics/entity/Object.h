#pragma once
#include "Shader.h"
#include <memory>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Entity.h"
#include "VertexArray.h"


namespace MemoGL {
	class Object : public Entity {
		public:
			Object(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> vertices);
			~Object() override;

			void render(IRenderer& renderer) override;
			void update(float deltatime);
			void imgui();

		private:
			std::shared_ptr<Shader> shader = nullptr;
			std::shared_ptr<VertexArray> vertices = nullptr;

			glm::mat4 proj;
			glm::mat4 view;
			glm::mat4 model;
			glm::vec3 translationA;
			glm::vec3 translationB;

			float camera_position_x = 0;
			float camera_position_y = 0;
	};
}