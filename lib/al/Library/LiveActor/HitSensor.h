#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class LiveActor;
class SensorHitGroup;

class HitSensor {
public:
    void setFollowPosPtr(sead::Vector3f*);
    void setFollowMtxPtr(sead::Matrix34f*);
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();

    void update();
    void addHitSensor(al::HitSensor*);

    al::LiveActor* mHostActor;  // _0
    u32 _8;
    f32 _C;
    f32 _10;
    f32 _14;
    f32 _18;
    u16 mMaxSensorCount;       // _1C
    u16 mCurSensorCount;       // _1E
    al::HitSensor** mSensors;  // _20
    char* _28;
    SensorHitGroup* mHitGroup;  // _30
    u8 _38;
    u8 _39;
    u8 _3A;
    u8 _3B;
    char* _3C;
    char* _40;
    sead::Vector3f* mFollowPos;   // _48
    sead::Matrix34f* mFollowMtx;  // _50
    f32 _58;
    f32 _5C;
    f32 _60;
};
};  // namespace al
