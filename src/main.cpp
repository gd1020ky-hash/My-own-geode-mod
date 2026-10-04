#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

namespace AutoDecorator {

    // Group used for objects created by Auto Decorator.
    constexpr int GENERATED_GROUP = 9999;

    class Decorator {
    public:

        static void run(EditorUI* editor) {
            if (!editor) {
                log::error("Auto Decorator: EditorUI is null.");
                return;
            }

            log::info("Auto Decorator: starting scan...");

            /*
             * Decoration pipeline
             *
             * 1. Read the objects currently in the editor.
             * 2. Detect structures such as:
             *      - blocks
             *      - slopes
             *      - platforms
             *      - spikes
             *      - portals
             * 3. Determine where decoration can safely be placed.
             * 4. Generate decorative objects.
             * 5. Assign generated objects to GENERATED_GROUP.
             * 6. Apply level colors.
             *
             * The actual object-generation functions will be added
             * after the Geode SDK/editor API is configured.
             */

            scanLevel(editor);
        }

    private:

        static void scanLevel(EditorUI* editor) {

            log::info("Auto Decorator: analyzing level structures...");

            /*
             * Future structure detection:
             *
             * for every object:
             *
             *     if object is a block:
             *         createBlockDecoration(object);
             *
             *     if object is a slope:
             *         createSlopeDecoration(object);
             *
             *     if object is a platform:
             *         createPlatformDecoration(object);
             *
             *     if object is a spike:
             *         createSpikeDecoration(object);
             *
             *     if object is a portal:
             *         createPortalDecoration(object);
             */

            log::info("Auto Decorator: scan complete.");
        }
    };

}


// ------------------------------------------------------------
// Geode mod entry point
// ------------------------------------------------------------

$on_mod(Loaded) {

    log::info("==============================");
    log::info(" Auto Decorator v1.0.0");
    log::info("==============================");

}
