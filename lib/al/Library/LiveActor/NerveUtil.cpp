#include "Library/LiveActor/NerveUtil.h"

#include "Library/Interfaces.h"
#include "Library/LiveActor/NerveKeeper.h"

namespace al {
void setNerve(IUseNerve* pUseNerve, const Nerve* pNerve) {
    pUseNerve->getNerveKeeper()->setNerve(pNerve);
}

void setNerveAtStep(IUseNerve* pUseNerve, const Nerve* pNerve, s32 step) {
    if (pUseNerve->getNerveKeeper()->mStep == step)
        pUseNerve->getNerveKeeper()->setNerve(pNerve);
}

bool isStep(const IUseNerve* pUseNerve, s32 step) {
    return pUseNerve->getNerveKeeper()->mStep == step;
}

bool isNerve(const IUseNerve* pUseNerve, const Nerve* pNerve) {
    return pUseNerve->getNerveKeeper()->getCurrentNerve() == pNerve;
}

int getNerveStep(const IUseNerve* pUseNerve) {
    return pUseNerve->getNerveKeeper()->mStep;
}

bool isFirstStep(const IUseNerve* pUseNerve) {
    return pUseNerve->getNerveKeeper()->mStep == 0;
}

bool isLessStep(const IUseNerve* pUseNerve, s32 step) {
    return pUseNerve->getNerveKeeper()->mStep < step;
}

bool isLessEqualStep(const IUseNerve* pUseNerve, s32 step) {
    return pUseNerve->getNerveKeeper()->mStep <= step;
}

bool isGreaterStep(const IUseNerve* pUseNerve, s32 step) {
    return pUseNerve->getNerveKeeper()->mStep > step;
}

bool isGreaterEqualStep(const IUseNerve* pUseNerve, s32 step) {
    return pUseNerve->getNerveKeeper()->mStep >= step;
}

bool isIntervalStep(const IUseNerve* pUseNerve, s32 interval, s32 startStep) {
    return (pUseNerve->getNerveKeeper()->mStep - startStep) % interval == 0;
}

bool isIntervalOnOffStep(const IUseNerve* pUseNerve, s32 interval, s32 startStep) {
    return ((pUseNerve->getNerveKeeper()->mStep - startStep) / interval & 1) == 0;
}
}  // namespace al
