#pragma once

namespace AutoDecorator {

    // ============================================================
    // THEMES
    // ============================================================

    enum class Theme {
        Glow,
        Hell,
        Tech,
        Space,
        Nature,
        Fantasy,
        Ice,
        Modern,
        Minimal,
        Custom
    };


    // ============================================================
    // DECORATION SETTINGS
    // ============================================================

    struct DecorationSettings {

        Theme theme = Theme::Glow;

        // 0.0 = almost no decoration
        // 1.0 = very dense decoration
        float density = 0.70f;

        bool blockDetails = true;
        bool slopeDetails = true;
        bool groundDetails = true;
        bool ceilingDetails = true;

        bool backgroundDetails = true;
        bool glow = true;
        bool pulses = true;

        // Keeps decoration away from gameplay.
        float gameplayClearance = 15.0f;

        // Same seed = same generated decoration.
        unsigned int seed = 12345;
    };


    // ============================================================
    // DECORATION TYPES
    // ============================================================

    enum class DecorationType {

        BlockEdge,
        BlockCorner,

        SlopeEdge,

        GroundDetail,
        CeilingDetail,

        BackgroundShape,

        GlowDetail,

        SmallDetail
    };


    // ============================================================
    // LEVEL STRUCTURE TYPES
    // ============================================================

    enum class StructureType {

        Unknown,

        Block,
        Slope,

        Ground,
        Ceiling,

        Platform,

        Spike,
        Portal
    };


    // ============================================================
    // STRUCTURE INFORMATION
    // ============================================================

    struct Structure {

        StructureType type = StructureType::Unknown;

        float x = 0.0f;
        float y = 0.0f;

        float width = 0.0f;
        float height = 0.0f;

        int objectID = 0;
    };


    // ============================================================
    // THEME NAME
    // ============================================================

    inline const char* getThemeName(Theme theme) {

        switch (theme) {

            case Theme::Glow:
                return "Glow";

            case Theme::Hell:
                return "Hell";

            case Theme::Tech:
                return "Tech";

            case Theme::Space:
                return "Space";

            case Theme::Nature:
                return "Nature";

            case Theme::Fantasy:
                return "Fantasy";

            case Theme::Ice:
                return "Ice";

            case Theme::Modern:
                return "Modern";

            case Theme::Minimal:
                return "Minimal";

            case Theme::Custom:
                return "Custom";
        }

        return "Unknown";
    }


    // ============================================================
    // SHOULD THIS STRUCTURE BE DECORATED?
    // ============================================================

    inline bool shouldDecorate(
        Structure const& structure,
        DecorationSettings const& settings
    ) {

        switch (structure.type) {

            case StructureType::Block:
                return settings.blockDetails;

            case StructureType::Slope:
                return settings.slopeDetails;

            case StructureType::Ground:
                return settings.groundDetails;

            case StructureType::Ceiling:
                return settings.ceilingDetails;

            case StructureType::Platform:
                return settings.blockDetails;

            default:
                return false;
        }
    }


    // ============================================================
    // CHOOSE DECORATION
    // ============================================================

    inline DecorationType chooseDecoration(
        Structure const& structure
    ) {

        switch (structure.type) {

            case StructureType::Block:
                return DecorationType::BlockEdge;

            case StructureType::Slope:
                return DecorationType::SlopeEdge;

            case StructureType::Ground:
                return DecorationType::GroundDetail;

            case StructureType::Ceiling:
                return DecorationType::CeilingDetail;

            case StructureType::Platform:
                return DecorationType::BlockCorner;

            default:
                return DecorationType::SmallDetail;
        }
    }

}
