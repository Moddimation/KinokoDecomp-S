#pragma once

#include <basis/seadTypes.h>

class CourseCollectItemInfo {
public:
    CourseCollectItemInfo();

    void initialize();
    void copy(const CourseCollectItemInfo& rSrc);
    s32 calcCollectItemAcquireNum(s32) const;
    bool isCompleteAcquire(s32 numCollectItem) const;

    s32 mCollectItemFlags;
};
