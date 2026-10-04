#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

#include "AutoDecorator.hpp"
#include "DecorationRules.hpp"

using namespace geode::prelude;

class $modify(AutoDecoratorEditorUI, EditorUI) {

    struct Fields {
        std::unique_ptr<AutoDecorator::Decorator> decorator;
        CCMenu* themeMenu = nullptr;
    };

    bool init(LevelEditorLayer* levelEditorLayer) {

        if (!EditorUI::init(levelEditorLayer))
            return false;

        log::info("Auto Decorator: Editor loaded!");

        m_fields->decorator =
            std::make_unique<AutoDecorator::Decorator>();

        createThemeMenu();

        return true;
    }

    void createThemeMenu() {

        auto menu = CCMenu::create();
        menu->setID("auto-decorator-theme-menu"_spr);

        auto title = CCLabelBMFont::create(
            "THEME",
            "bigFont.fnt"
        );

        title->setScale(0.45f);
        menu->addChild(title);

        auto glow = createThemeButton(
            "Glow",
            AutoDecorator::Theme::Glow
        );

        auto hell = createThemeButton(
            "Hell",
            AutoDecorator::Theme::Hell
        );

        auto tech = createThemeButton(
            "Tech",
            AutoDecorator::Theme::Tech
        );

        auto space = createThemeButton(
            "Space",
            AutoDecorator::Theme::Space
        );

        auto nature = createThemeButton(
            "Nature",
            AutoDecorator::Theme::Nature
        );

        auto fantasy = createThemeButton(
            "Fantasy",
            AutoDecorator::Theme::Fantasy
        );

        auto ice = createThemeButton(
            "Ice",
            AutoDecorator::Theme::Ice
        );

        auto modern = createThemeButton(
            "Modern",
            AutoDecorator::Theme::Modern
        );

        auto minimal = createThemeButton(
            "Minimal",
            AutoDecorator::Theme::Minimal
        );

        menu->addChild(glow);
        menu->addChild(hell);
        menu->addChild(tech);
        menu->addChild(space);
        menu->addChild(nature);
        menu->addChild(fantasy);
        menu->addChild(ice);
        menu->addChild(modern);
        menu->addChild(minimal);

        title->setPosition(0, 45);

        glow->setPosition(0, 15);
        hell->setPosition(0, -15);
        tech->setPosition(0, -45);

        space->setPosition(100, 15);
        nature->setPosition(100, -15);
        fantasy->setPosition(100, -45);

        ice->setPosition(200, 15);
        modern->setPosition(200, -15);
        minimal->setPosition(200, -45);

        menu->setPosition(
            150.0f,
            CCDirector::sharedDirector()
                ->getWinSize()
                .height - 80.0f
        );

        addChild(menu, 1000);

        m_fields->themeMenu = menu;
    }

    CCMenuItemSpriteExtra* createThemeButton(
        char const* name,
        AutoDecorator::Theme theme
    ) {

        auto sprite = ButtonSprite::create(
            name,
            "goldFont.fnt",
            "GJ_button_01.png",
            1.0f
        );

        sprite->setScale(0.35f);

        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(
                AutoDecoratorEditorUI::onThemeSelected
            )
        );

        button->setTag(
            static_cast<int>(theme)
        );

        return button;
    }

    void onThemeSelected(CCObject* sender) {

        auto button =
            static_cast<CCMenuItemSpriteExtra*>(sender);

        if (!button)
            return;

        auto theme =
            static_cast<AutoDecorator::Theme>(
                button->getTag()
            );

        if (!m_fields->decorator)
            return;

        m_fields->decorator->setTheme(theme);

        log::info(
            "Auto Decorator: selected theme '{}'",
            AutoDecorator::getThemeName(theme)
        );
    }
};


$on_mod(Loaded) {

    log::info("Auto Decorator loaded!");

}
