#include "Library/LiveActor/LiveActor.h"

#include "Library/LiveActor/LiveActorFlag.h"

namespace al {
LiveActor::LiveActor(const char* pName) {
    mName = pName;
    mFlags = new LiveActorFlag();
}

/*LiveActor::~LiveActor() {
    delete mFlags;
    delete mStageSwitchKeeper;
    delete mScreenPointKeeper;
    delete mHitSensorKeeper;
    delete mModelKeeper;
    delete mCollider;
    delete mScoreKeeper;
    delete mItemKeeper;
}*/

void LiveActor::init(const ActorInitInfo& rInfo) {}
};  // namespace al
