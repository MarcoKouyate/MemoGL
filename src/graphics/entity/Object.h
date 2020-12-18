#pragma once
#include "Shader.h"
#include <memory>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Entity.h"


namespace MemoGL {
	class Object : public Entity {
		public:
			Object(std::shared_ptr<Shader> shader);
			~Object();

			void render(IRenderer& renderer) override;

			void bind() {
				shader->bind();
			}

		private:
			std::shared_ptr<Shader> shader = nullptr;

			glm::mat4 proj;
			glm::mat4 view;
			glm::mat4 model;
			glm::vec3 translationA;
			glm::vec3 translationB;

			float camera_position_x = 0;
			float camera_position_y = 0;
	};
}