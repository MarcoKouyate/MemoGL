#include "SceneManager.h"

namespace MemoGL {
	SceneManager* SceneManager::instance = nullptr;

	SceneManager* SceneManager::getInstance() {
		if (!instance) {
			instance = new SceneManager;
		}
		return instance;
	}

	std::shared_ptr<Scene> SceneManager::getCurrentScene() {
		return currentScene;
	}

	void SceneManager::load(std::shared_ptr<Scene> newScene) {
		currentScene = newScene;
	}

	SceneManager::SceneManager()
	{
	}

	SceneManager::~SceneManager()
	{
	}
}