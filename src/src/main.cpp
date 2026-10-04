#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(AutoDecoratorEditorUI, EditorUI) {

    bool init(LevelEditorLayer* levelEditorLayer) {
        if (!EditorUI::init(levelEditorLayer))
            return false;

        // Create our button sprite.
        auto sprite = ButtonSprite::create(
            "AUTO DECORATE",
            "goldFont.fnt",
            "GJ_button_01.png",
            1.0f
        );

        sprite->setScale(0.55f);

        // Create clickable button.
        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(AutoDecoratorEditorUI::onAutoDecorate)
        );

        // The button must be inside a CCMenu.
        auto menu = CCMenu::create();
        menu->setID("auto-decorator-menu"_spr);

        menu->addChild(button);

        // Put the button near the top-left of the editor.
        menu->setPosition(
            115.0f,
            CCDirector::sharedDirector()->getWinSize().height - 45.0f
        );

        this->addChild(menu, 999);

        log::info("Auto Decorator button created!");

        return true;
    }

    void onAutoDecorate(CCObject* sender) {

        log::info("AUTO DECORATE clicked!");

        auto editor = this;

        if (!editor) {
            log::error("Auto Decorator: EditorUI is invalid.");
            return;
        }

        /*
         * NEXT STAGE:
         *
         * 1. Read the current level's GameObjects.
         * 2. Identify blocks/slopes/platforms.
         * 3. Calculate safe decoration positions.
         * 4. Create decorative GameObjects.
         * 5. Assign generated objects to group 9999.
         */

        FLAlertLayer::create(
            "Auto Decorator",
            "Auto decoration engine is ready to run.",
            "OK"
        )->show();
    }
};

$on_mod(Loaded) {
    log::info("==============================");
    log::info(" Auto Decorator loaded!");
    log::info("==============================");
}
