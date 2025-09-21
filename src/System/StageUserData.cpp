#include "System/StageUserData.h"

#include "Util.h"

StageUserData::StageUserData() {
    mFigureType = kp::getPlayerFigureTypeDefault();
    mIsAlive = false;
}

void StageUserData::init() {
    mFigureType = kp::getPlayerFigureTypeDefault();
    mIsAlive = false;
}

void StageUserData::setFigureType(s32 figureType) {
    mFigureType = figureType;
}

void StageUserData::setAlive(bool alive) {
    mIsAlive = alive;
}
