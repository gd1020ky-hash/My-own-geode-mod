#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

#include "AutoDecorator.hpp"

using namespace geode::prelude;

class $modify(AutoDecoratorEditorUI, EditorUI) {

    struct Fields {
        std::unique_ptr<AutoDecorator::Decorator> decorator;
    };

    bool init(LevelEditorLayer* levelEditorLayer) {

        if (!EditorUI::init(levelEditorLayer))
            return false;

        log::info("Auto Decorator: Editor loaded!");

        m_fields->decorator =
            std::make_unique<AutoDecorator::Decorator>();

        // --------------------------------------------------------
        // Create AUTO DECORATE button
        // --------------------------------------------------------

        auto buttonSprite = ButtonSprite::create(
            "AUTO DECORATE",
            "bigFont.fnt",
            "GJ_button_01.png",
            1.0f
        );

        buttonSprite->setScale(0.45f);

        auto button = CCMenuItemSpriteExtra::create(
            buttonSprite,
            this,
            menu_selector(AutoDecoratorEditorUI::onAutoDecorate)
        );

        auto menu = CCMenu::create();

        menu->addChild(button);

        menu->setPosition(
            100.0f,
            CCDirector::sharedDirector()
                ->getWinSize()
                .height - 45.0f
        );

        this->addChild(menu, 1000);

        return true;
    }


    void onAutoDecorate(CCObject*) {

        log::info("================================");
        log::info(" AUTO DECORATE PRESSED");
        log::info("================================");

        if (!m_fields->decorator) {
            log::error("Auto Decorator: decorator unavailable!");
            return;
        }

        m_fields->decorator->decorate(this);
    }
};


$on_mod(Loaded) {

    log::info("==============================");
    log::info(" Auto Decorator loaded!");
    log::info("==============================");

}
