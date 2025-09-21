#pragma once

#include <basis/seadTypes.h>

#define PLAYER_SELECT_TYPE_KINOPIO 0
#define PLAYER_SELECT_TYPE_KINOPICO 1
#define PLAYER_SELECT_TYPE_KINOPIO_AND_KINOPICO 2

class PlayerSelectType {
public:
    static s32 calcPlayerSelectTypeID(const char* pType);
    static bool isKinopio(const char* pType);
    static bool isKinopico(const char* pType);
    static bool isKinopioAndKinopico(const char* pType);
};
