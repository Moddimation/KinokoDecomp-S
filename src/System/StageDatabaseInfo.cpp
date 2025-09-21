#include "System/StageDatabaseInfo.h"

#include <Library/Base/StringUtil.h>

#include "System/BadgeConditionType.h"
#include "System/PlayerSelectType.h"
#include "System/StageType.h"

BadgeConditionInfo::BadgeConditionInfo() {
    mInfoCount = 0;
    mTypeIDs = new s32[1];
    mParams = new s32[1];
    *mTypeIDs = BADGE_CONDITION_TYPE_INVALID;
    *mParams = 0;
}

void BadgeConditionInfo::registerInfo(const char* pName, s32 param) {
    mTypeIDs[mInfoCount] = BadgeConditionType::calcBadgeConditionTypeID(pName);
    mParams[mInfoCount] = param;
    mInfoCount++;
}

s32 BadgeConditionInfo::getTypeID(s32 index) const {
    return mTypeIDs[index];
}

s32 BadgeConditionInfo::getParam(s32 index) const {
    return mParams[index];
}

#ifdef NON_MATCHING
StageDatabaseInfo::StageDatabaseInfo() {
    mOpenPageNum = 1;
    mOffScreenBubble = true;
    mBadgeConditionInfo = new BadgeConditionInfo();
}
#endif

#ifdef NON_MATCHING  // mStageType = StageType::calcStageTypeID loads the pointer param later than
                     // char*32ended
void StageDatabaseInfo::initialize(
    int seasonId, int stageId, int courseId, int pageId, int collectItemNum, int collectLockNum,
    int openPageNum, int challengeTime, int badgeCondition1Param, char const* pBadgeCondition1,
    char const* pStageName, char const* pStageType, char const* pPlayer, char const* pClipping,
    bool offScreenBubble, bool disableStageEntry, bool showGhostTutorial, bool isGhostBusterStage) {
    mStageId = stageId;
    mCollectItemNum = collectItemNum;
    mCollectLockNum = collectLockNum;
    mStageName = pStageName;
    mCourseId = courseId;
    mPageId = pageId;
    mOpenPageNum = openPageNum;
    mChallengeTime = challengeTime;
    mStageType = StageType::calcStageTypeID(pStageType);
    mPlayerSelectType = PlayerSelectType::calcPlayerSelectTypeID(pPlayer);
    mOffScreenBubble = offScreenBubble;
    mDisableStageEntry = disableStageEntry;
    mShowGhostTutorial = showGhostTutorial;
    mIsGhostBusterStage = isGhostBusterStage;

    if (!BadgeConditionType::isInvalid(pBadgeCondition1))
        mBadgeConditionInfo->registerInfo(pBadgeCondition1, badgeCondition1Param);

    mIsValidClipping = !al::isEqualString(pClipping, "無効");
}
#endif

bool StageDatabaseInfo::isPlayerKinopio() const {
    return mPlayerSelectType == PLAYER_SELECT_TYPE_KINOPIO;
}

bool StageDatabaseInfo::isPlayerKinopico() const {
    return mPlayerSelectType == PLAYER_SELECT_TYPE_KINOPICO;
}

bool StageDatabaseInfo::isPlayerKinopioAndKinopico() const {
    return mPlayerSelectType == PLAYER_SELECT_TYPE_KINOPIO_AND_KINOPICO;
}

bool StageDatabaseInfo::isBadgeInvalid(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_INVALID;
}

bool StageDatabaseInfo::isBadgeCoinNum(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_COIN_NUM;
}

bool StageDatabaseInfo::isBadgeTouchNum(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_TOUCH_NUM;
}

bool StageDatabaseInfo::isBadgeOnSwitchChecker(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_ON_SWITCH_CHECKER;
}

bool StageDatabaseInfo::isBadgeOffSwitchChecker(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_OFF_SWITCH_CHECKER;
}

bool StageDatabaseInfo::isBadgeGetKinokoOneUp(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_GET_KINOKO_ONE_UP;
}

bool StageDatabaseInfo::isBadgeRadishThrowNum(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_RADISH_THROW_NUM;
}

bool StageDatabaseInfo::isBadgeNoDamage(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_NO_DAMAGE;
}

bool StageDatabaseInfo::isBadgeSwitchBlockNum(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_SWITCH_BLOCK_NUM;
}

bool StageDatabaseInfo::isBadgeDoubleCherryNum(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_DOUBLE_CHERRY_NUM;
}

bool StageDatabaseInfo::isBadgeGetKinokoTreasure(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_GET_KINOKO_TREASURE;
}

bool StageDatabaseInfo::isBadgeNoFoundHeyho(s32 index) const {
    return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_NO_FOUND_HEYHO;
}
