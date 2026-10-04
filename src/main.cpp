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

        // Create our decorator.
        m_fields->decorator =
            std::make_unique<AutoDecorator::Decorator>();

        return true;
    }

    void onAutoDecorate(CCObject*) {

        log::info("Auto Decorate pressed!");

        if (!m_fields->decorator) {
            log::error("Auto Decorator: decorator unavailable!");
            return;
        }

        m_fields->decorator->decorate(this);
    }
};


$on_mod(Loaded) {

    log::info("Auto Decorator loaded!");

}
