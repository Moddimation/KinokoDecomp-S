#pragma once

#include <basis/seadTypes.h>

class BadgeConditionInfo {
public:
    BadgeConditionInfo();

    void registerInfo(const char* pName, s32 param);
    s32 getTypeID(s32 index) const;
    s32 getParam(s32 index) const;

    s32 mInfoCount;  // _0
    s32* mTypeIDs;   // _8
    s32* mParams;    // _10
};

class StageDatabaseInfo {
public:
    StageDatabaseInfo();

    void initialize(int seasonId, int stageId, int courseId, int pageId, int collectItemNum,
                    int collectLockNum, int openPageNum, int challengeTime,
                    int badgeCondition1Param, char const* pBadgeCondition1, char const* pStageName,
                    char const* pStageType, char const* pPlayer, char const* pClipping,
                    bool offScreenBubble, bool disableStageEntry, bool showGhostTutorial,
                    bool isGhostBusterStage);
    bool isStageNormal() const;
    bool isStageBonus() const;
    bool isStageGameOverMiniGame() const;
    bool isStageTrickArt() const;
    bool isStagePictureDemo() const;
    bool isStagePicture() const;
    bool isStagePrologue() const;
    bool isStageSpecialBonus() const;
    bool isStageSpecial() const;
    bool isStageSpecial3DWorld() const;
    bool isStageSpecialManeck() const;
    bool isStageSpecialCherry() const;
    bool isStageSpecialPrologue() const;
    bool isStageSpecialOther() const;
    bool isStageLabyrs32h() const;
    bool isStageWhite() const;
    bool isPlayerKinopio() const;
    bool isPlayerKinopico() const;
    bool isPlayerKinopioAndKinopico() const;
    bool isBadgeInvalid(s32 index) const;
    bool isBadgeCoinNum(s32 index) const;
    bool isBadgeTouchNum(s32 index) const;
    bool isBadgeOnSwitchChecker(s32 index) const;
    bool isBadgeOffSwitchChecker(s32 index) const;
    bool isBadgeGetKinokoOneUp(s32 index) const;
    bool isBadgeRadishThrowNum(s32 index) const;
    bool isBadgeNoDamage(s32 index) const;
    bool isBadgeSwitchBlockNum(s32 index) const;
    bool isBadgeDoubleCherryNum(s32 index) const;
    bool isBadgeGetKinokoTreasure(s32 index) const;
    bool isBadgeNoFoundHeyho(s32 index) const;

    s32 mSeasonId = 0;                                  // _0
    s32 mStageId = 0;                                   // _4
    s32 mCourseId = 0;                                  // _8
    s32 mPageId = 0;                                    // _C
    s32 mStageType = 0;                                 // _10
    s32 mPlayerSelectType = 0;                          // _14
    s32 mCollectItemNum = 0;                            // _18
    s32 mCollectLockNum = 0;                            // _1C
    s32 mOpenPageNum = 0;                               // _20
    s32 mChallengeTime = 0;                             // _24
    const char* mStageName = 0;                         // _28
    BadgeConditionInfo* mBadgeConditionInfo = nullptr;  // _30
    bool mOffScreenBubble = false;                      // _38
    bool mIsValidClipping = false;                      // _39
    bool mDisableStageEntry = false;                    // _3A
    bool mShowGhostTutorial = false;                    // _3B
    bool mIsGhostBusterStage = false;                   // _3C
};
