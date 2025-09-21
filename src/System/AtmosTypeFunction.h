#pragma once

#include <basis/seadTypes.h>

#define ATMOS_TYPE_UNUSE 0
#define ATMOS_TYPE_SCATTER 1
#define ATMOS_TYPE_AGL_LIGHT_SCATTER 2

class AtmosTypeFunction {
public:
    static s32 calcAtmosTypeID(const char* pType);
    static bool isUnuse(const char* pType);
    static bool isUseAtmosScatter(const char* pType);
    static bool isUseAglLightScatter(const char* pType);
};
