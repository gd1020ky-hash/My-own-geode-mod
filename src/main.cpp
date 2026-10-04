#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

// ============================================================
// AUTO DECORATOR
// ============================================================
//
// Current stage:
// - Loads into the Geometry Dash editor
// - Adds the foundation for the Auto Decorator
// - Theme system will be connected to the generator next
//
// ============================================================

class $modify(AutoDecoratorEditorUI, EditorUI) {

    bool init(LevelEditorLayer* levelEditorLayer) {

        // Initialize the original Geometry Dash editor.
        if (!EditorUI::init(levelEditorLayer))
            return false;

        log::info("================================");
        log::info(" Auto Decorator");
        log::info(" Editor loaded!");
        log::info("================================");

        // ----------------------------------------------------
        // Theme list
        // ----------------------------------------------------

        // These are the themes that the decorator will support.
        //
        // The actual decoration generator will use this
        // selection later.

        log::info("Available themes:");
        log::info("1. Glow");
        log::info("2. Hell");
        log::info("3. Tech");
        log::info("4. Space");
        log::info("5. Nature");
        log::info("6. Fantasy");
        log::info("7. Ice");
        log::info("8. Modern");
        log::info("9. Minimal");
        log::info("10. Custom");

        return true;
    }
};


// ============================================================
// MOD LOADING
// ============================================================

$on_mod(Loaded) {

    log::info("================================");
    log::info(" Auto Decorator loaded!");
    log::info(" Version 1.0.0");
    log::info("================================");

}
