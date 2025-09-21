#pragma once

#include <basis/seadTypes.h>

#include "Library/Interfaces.h"
#include "Library/LiveActor/NerveKeeper.h"

namespace al {
class NerveExecutor : public al::IUseNerve {
public:
    NerveExecutor(const char*);

    virtual NerveKeeper* getNerveKeeper() const { return mNerveKeeper; }

    virtual ~NerveExecutor();

    void initNerve(const Nerve* nerve, s32 stateCount);
    void updateNerve();

    NerveKeeper* mNerveKeeper;  // _8
};
};  // namespace al
