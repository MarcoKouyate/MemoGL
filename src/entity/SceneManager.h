#pragma once
#include "Scene.h"

namespace MemoGL {
	class  SceneManager
	{
	public:
		static SceneManager* getInstance();
		std::shared_ptr<Scene> getCurrentScene();

		void load(std::shared_ptr<Scene> scene);

		~SceneManager();

	private:
		SceneManager();
		std::shared_ptr<Scene> currentScene = nullptr;

		static SceneManager* instance;
	};
}