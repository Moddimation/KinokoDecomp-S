#pragma once

#include <basis/seadTypes.h>

namespace al {
class HitSensor;

class SensorHitGroup {
public:
    SensorHitGroup(s32, const char*);

    void add(al::HitSensor*);
    void remove(al::HitSensor*);
    al::HitSensor* getSensor(s32) const;
    void clear() const;

    s32 mMaxSensorCount;       // _0
    s32 mSensorCount;          // _4
    al::HitSensor** mSensors;  // _8
};
};  // namespace al
