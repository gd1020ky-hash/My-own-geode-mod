#pragma once

namespace AutoDecorator {

    // ------------------------------------------------------------
    // Auto-Decoration settings
    // ------------------------------------------------------------

    struct DecorationSettings {

        // Overall amount of decoration.
        float density = 0.65f;

        // Decoration around the level's main structures.
        bool blockDetails = true;
        bool slopeDetails = true;
        bool groundDetails = true;
        bool ceilingDetails = true;

        // Decorative background elements.
        bool backgroundDetails = true;

        // Extra visual effects.
        bool glow = true;
        bool pulses = true;

        // Keep decoration away from gameplay.
        float gameplayClearance = 15.0f;

        // Random seed.
        unsigned int seed = 12345;
    };


    // ------------------------------------------------------------
    // Decoration types
    // ------------------------------------------------------------

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


    // ------------------------------------------------------------
    // Structure types
    // ------------------------------------------------------------

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


    // ------------------------------------------------------------
    // Basic structure information
    // ------------------------------------------------------------

    struct Structure {

        StructureType type = StructureType::Unknown;

        float x = 0.0f;
        float y = 0.0f;

        float width = 0.0f;
        float height = 0.0f;

        int objectID = 0;
    };


    // ------------------------------------------------------------
    // Decide whether decoration should be generated
    // ------------------------------------------------------------

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


    // ------------------------------------------------------------
    // Convert a structure into a decoration type
    // ------------------------------------------------------------

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
