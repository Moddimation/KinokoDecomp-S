#pragma once

#include <basis/seadTypes.h>

namespace al {
class Nerve;
class NerveActionCtrl;
class NerveStateCtrl;

class NerveKeeper {
public:
    NerveKeeper(void*, const Nerve*, s32);

    void update();
    void tryChangeNerve();
    void setNerve(const Nerve* pNerve);
    Nerve* getCurrentNerve();
    void initNerveAction(NerveActionCtrl* pActionCtrl);

    NerveStateCtrl* mStateCtrl;  // _0
    const Nerve* mCurrentNerve = nullptr;
    const Nerve* mNextNerve;
    s32 mStep;  // _18
    NerveActionCtrl* _20;
    NerveActionCtrl* mActionCtrl;  // _28
};
};  // namespace al
