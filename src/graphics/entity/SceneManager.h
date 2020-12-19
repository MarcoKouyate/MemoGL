#pragma once
#include "Demo.h"

namespace MemoGL {
	class  SceneManager
	{
	public:
		static SceneManager* getInstance();
		std::shared_ptr<Demo> getCurrentScene();

		void load(std::shared_ptr<Demo> scene);

		~SceneManager();

	private:
		SceneManager();
		std::shared_ptr<Demo> currentScene = nullptr;

		static SceneManager* instance;
	};
}