#include "AutoDecorator.hpp"

namespace AutoDecorator {

    Decorator::Decorator() {
        m_settings = DecorationSettings{};
    }

    Decorator::~Decorator() = default;


    void Decorator::setTheme(Theme theme) {
        m_settings.theme = theme;
    }


    DecorationSettings const& Decorator::getSettings() const {
        return m_settings;
    }


    void Decorator::decorate(
        EditorUI* editor,
        DecorationSettings const& settings
    ) {

        if (!editor) {
            log::error("Auto Decorator: EditorUI is null.");
            return;
        }

        // Save the settings selected by the user.
        m_settings = settings;

        log::info(
            "Auto Decorator: starting decoration with theme '{}'",
            getThemeName(m_settings.theme)
        );

        // Start scanning the level.
        scanLevel(editor);

        log::info("Auto Decorator: decoration finished.");
    }


    void Decorator::clearGeneratedDecoration(
        EditorUI* editor
    ) {

        if (!editor) {
            log::error("Auto Decorator: EditorUI is null.");
            return;
        }

        /*
         * Generated objects will eventually be identified using
         * our dedicated generated-object group.
         *
         * We will implement the actual GameObject removal here
         * after connecting this class to the correct editor API.
         */

        log::info(
            "Auto Decorator: clear generated decoration requested."
        );
    }


    void Decorator::scanLevel(
        EditorUI* editor
    ) {

        if (!editor)
            return;

        /*
         * IMPORTANT:
         *
         * This is where the real Geometry Dash editor object
         * scanning will be connected.
         *
         * Planned process:
         *
         *     Editor objects
         *          ↓
         *     identify structures
         *          ↓
         *     Structure objects
         *          ↓
         *     decoration rules
         *          ↓
         *     generated GameObjects
         *
         * We are keeping this separate from the UI so the
         * Auto Decorator button doesn't contain the entire
         * decoration engine.
         */

        log::info("Auto Decorator: scanning level...");
    }


    void Decorator::decorateStructure(
        EditorUI* editor,
        Structure const& structure
    ) {

        if (!editor)
            return;

        if (!shouldDecorate(structure, m_settings))
            return;

        auto type = chooseDecoration(structure);

        switch (type) {

            case DecorationType::BlockEdge:
            case DecorationType::BlockCorner:
                createBlockDecoration(editor, structure);
                break;

            case DecorationType::SlopeEdge:
                createSlopeDecoration(editor, structure);
                break;

            case DecorationType::GroundDetail:
            case DecorationType::CeilingDetail:
                createGroundDecoration(editor, structure);
                break;

            case DecorationType::BackgroundShape:
            case DecorationType::GlowDetail:
            case DecorationType::SmallDetail:
                createBackgroundDecoration(editor, structure);
                break;
        }
    }


    void Decorator::createBlockDecoration(
        EditorUI* editor,
        Structure const& structure
    ) {

        if (!editor)
            return;

        /*
         * Block decoration will eventually be generated here.
         *
         * Example:
         *
         *      ██████████
         *      █        █
         *      █        █
         *      ██████████
         *
         * The generator will create edge/corner objects while
         * keeping them outside the gameplay collision area.
         */

        log::info(
            "Auto Decorator: block decoration at {}, {}",
            structure.x,
            structure.y
        );
    }


    void Decorator::createSlopeDecoration(
        EditorUI* editor,
        Structure const& structure
    ) {

        if (!editor)
            return;

        /*
         * Future slope decoration:
         *
         *     /
         *    /  decorative edge
         *   /
         *
         * The decoration will follow the slope's orientation.
         */

        log::info(
            "Auto Decorator: slope decoration at {}, {}",
            structure.x,
            structure.y
        );
    }


    void Decorator::createGroundDecoration(
        EditorUI* editor,
        Structure const& structure
    ) {

        if (!editor)
            return;

        /*
         * Future ground/ceiling details:
         *
         * - edge details
         * - small shapes
         * - glow
         * - repeating patterns
         */

        log::info(
            "Auto Decorator: ground/ceiling decoration at {}, {}",
            structure.x,
            structure.y
        );
    }


    void Decorator::createBackgroundDecoration(
        EditorUI* editor,
        Structure const& structure
    ) {

        if (!editor)
            return;

        /*
         * Future background generator:
         *
         * - background shapes
         * - particles/details
         * - theme-specific objects
         * - glow elements
         */

        log::info(
            "Auto Decorator: background decoration at {}, {}",
            structure.x,
            structure.y
        );
    }

}
