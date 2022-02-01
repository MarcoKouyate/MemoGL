#include "Button.h"
#include "entity/texts/Text.h"
#include "entity/shapes/ColorRectangle.h"
#include "events/inputs/Input.h"
#include "tools/Log.h"

namespace MemoGL {
    Button::Button(const std::string& content) {
        std::shared_ptr<ColorRectangle> rectangle = std::make_shared<ColorRectangle>();
        float scale = 7;
        std::shared_ptr<Text> text = std::make_shared<Text>(content, scale);
        text->getTransform()->setScale(1/ scale, 1/scale);
        text->getTransform()->setPosition(-scale/2, 0); //TODO center text depending on textwidth;
        rectangle->addChild(text);
        this->addChild(rectangle);
    }

    void Button::update(float deltatime) {
        if (!Input::get()->isMouseButtonPressed(0))  return;

        glm::vec2 mousePos = Input::get()->getMousePosition();
        MEMOGL_LOG_INFO(std::to_string(mousePos.x) + " " + std::to_string(mousePos.y));
    }
}