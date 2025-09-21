#include "Library/LiveActor/SensorHitGroup.h"
#include "Library/LiveActor/HitSensor.h"

namespace al {
SensorHitGroup::SensorHitGroup(s32 maxCount, const char* pName) {
    mMaxSensorCount = maxCount;
    mSensorCount = 0;
    mSensors = new al::HitSensor*[maxCount];

    if (maxCount >= 1)
        for (s32 i = 0; i < mMaxSensorCount; i++)
            mSensors[i] = nullptr;
}

void SensorHitGroup::add(al::HitSensor* pSensor) {
    mSensors[mSensorCount] = pSensor;
    mSensorCount++;
}

al::HitSensor* SensorHitGroup::getSensor(s32 idx) const {
    return mSensors[idx];
}

void SensorHitGroup::clear() const {
    if (mSensorCount >= 1)
        for (s32 i = 0; i < mSensorCount; i++)
            mSensors[i]->mCurSensorCount = 0;
}
};  // namespace al
