#pragma once

struct CSuperClassImpl_;

typedef struct CSuperClass_ CSuperClass;

struct CSuperClass_
{
    struct CSuperClassImpl_* impl;

    void(*Print)(CSuperClass* self);
    void(*SetValue)(CSuperClass* self, int a, int b);
    int(*Add)(CSuperClass* self);
    int(*Sub)(CSuperClass* self);
    int(*GetA)(CSuperClass* self);
    int(*GetB)(CSuperClass* self);
};

CSuperClass* CSuperClass_Construct1();

CSuperClass* CSuperClass_Construct2(int a, int b);

void CSuperClass_Destruct(CSuperClass* self);

