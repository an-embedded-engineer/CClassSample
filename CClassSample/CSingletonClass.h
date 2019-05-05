#pragma once

struct CSingletonClassImpl_;

typedef struct CSingletonClass_ CSingletonClass;

struct CSingletonClass_
{
    struct CSingletonClassImpl_* impl;

    void(*Print)(CSingletonClass* self);
    void(*SetValue)(CSingletonClass* self, int a, int b);
    int(*Add)(CSingletonClass* self);
    int(*Sub)(CSingletonClass* self);
    int(*GetA)(CSingletonClass* self);
    int(*GetB)(CSingletonClass* self);
};

CSingletonClass* CSingletonClass_GetInstancce();

