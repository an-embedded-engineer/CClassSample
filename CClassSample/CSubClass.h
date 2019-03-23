#pragma once

struct CSubClassImpl_;

typedef struct CSubClass_ CSubClass;

struct CSubClass_
{
    struct CSubClassImpl_* impl;

    void(*Print)(CSubClass* self);
    void(*SetValue)(CSubClass* self, int a, int b);
    int(*Add)(CSubClass* self);
    int(*Sub)(CSubClass* self);
    int(*Mul)(CSubClass* self);
    int(*Div)(CSubClass* self);
    int(*Mod)(CSubClass* self);
};

CSubClass* CSubClass_Construct1();

CSubClass* CSubClass_Construct2(int a, int b);

void CSubClass_Destruct(CSubClass* self);

