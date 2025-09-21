#pragma once

#include <basis/seadTypes.h>

class StageUserData {
public:
    StageUserData();

    void init();
    void setFigureType(s32 figureType);
    void setAlive(bool alive);

    s32 mFigureType;  // _0
    bool mIsAlive;    // _4
};
