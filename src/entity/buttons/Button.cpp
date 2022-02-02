#include "Button.h"
#include "entity/texts/Text.h"
#include "entity/shapes/ColorRectangle.h"
#include "events/inputs/Input.h"
#include "tools/Log.h"

namespace MemoGL {
    Button::Button(const std::string& content) {
        std::shared_ptr<ColorRectangle> rectangle = std::make_shared<ColorRectangle>();
        float scale = 7;
        std::shared_ptr<Text> text = std::make_shared<Text>(content, 0);
        text->getTransform()->setScale(1/ scale, 1/scale);
        text->getTransform()->setPosition(-scale/2, 0); //TODO center text depending on textwidth;
        rectangle->addChild(text);
        this->addChild(rectangle);
    }

    void Button::update(float deltatime) {
        if (!Input::get()->isMouseButtonPressed(0))  return;
    }
    void Button::onEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<MousePressedEvent>(EVENT_CALLBACK(Button::OnMousePressed));
        dispatcher.dispatch<MouseReleasedEvent>(EVENT_CALLBACK(Button::OnMouseReleased));
    }

    bool Button::OnMousePressed(MousePressedEvent& e)
    {
        glm::vec2 pos = Input::get()->getMousePosition();
        // TODO get button screen position
        MEMOGL_LOG_INFO("Mouse Pressed at (x: {0}/y: {1})", pos.x, pos.y);
        return true;
    }

    bool Button::OnMouseReleased(MouseReleasedEvent& e)
    {
        MEMOGL_LOG_INFO("Mouse Released");
        return true;
    }
}