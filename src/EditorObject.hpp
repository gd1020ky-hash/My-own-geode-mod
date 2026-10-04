#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace AutoDecorator {

    struct ObjectInfo {
        GameObject* object = nullptr;

        float x = 0.0f;
        float y = 0.0f;

        float width = 0.0f;
        float height = 0.0f;

        int objectID = 0;
    };

    inline ObjectInfo getObjectInfo(GameObject* object) {

        ObjectInfo info;

        if (!object)
            return info;

        info.object = object;

        info.x = object->getPositionX();
        info.y = object->getPositionY();

        info.width = object->getContentSize().width;
        info.height = object->getContentSize().height;

        info.objectID = object->m_objectID;

        return info;
    }

}
