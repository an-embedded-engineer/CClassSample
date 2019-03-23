#include "Common.h"
#include "CSuperClass.h"
#include "CSubClass.h"

typedef struct CSubClassImpl_
{
    CSuperClass* super;
}CSubClassImpl;

static CSubClass* CSubClass_Init(CSuperClass* super);

static void CSubClass_Print(CSubClass* self);
static void CSubClass_SetValue(CSubClass* self, int a, int b);
static int CSubClass_Add(CSubClass* self);
static int CSubClass_Sub(CSubClass* self);
static int CSubClass_Mul(CSubClass* self);
static int CSubClass_Div(CSubClass* self);
static int CSubClass_Mod(CSubClass* self);


CSubClass* CSubClass_Construct1()
{
    CSuperClass* super = CSuperClass_Construct1();

    CSubClass* instance = CSubClass_Init(super);

    return instance;
}

CSubClass* CSubClass_Construct2(int a, int b)
{
    CSuperClass* super = CSuperClass_Construct2(a, b);

    CSubClass* instance = CSubClass_Init(super);

    return instance;
}

void CSubClass_Destruct(CSubClass* self)
{
    CSuperClass_Destruct(self->impl->super);

    delete_object(self->impl);

    delete_object(self);
}

static CSubClass* CSubClass_Init(CSuperClass* super)
{
    CSubClassImpl* impl = new_object(CSubClassImpl)
    {
        impl->super = super;
    };

    CSubClass* instance = new_object(CSubClass)
    {
        instance->impl = impl;
        instance->Print = CSubClass_Print;
        instance->SetValue = CSubClass_SetValue;
        instance->Add = CSubClass_Add;
        instance->Sub = CSubClass_Sub;
        instance->Mul = CSubClass_Mul;
        instance->Div = CSubClass_Div;
        instance->Mod = CSubClass_Mod;
    };

    return instance;
}

static void CSubClass_Print(CSubClass* self)
{
    base->Print(base);
}

static void CSubClass_SetValue(CSubClass* self, int a, int b)
{
    base->SetValue(base, a, b);
}

static int CSubClass_Add(CSubClass* self)
{
    return base->Add(base);
}

static int CSubClass_Sub(CSubClass* self)
{
    return base->Sub(base);
}

static int CSubClass_Mul(CSubClass* self)
{
    return base->GetA(base) * base->GetB(base);
}

static int CSubClass_Div(CSubClass* self)
{
    return base->GetA(base) / base->GetB(base);
}

static int CSubClass_Mod(CSubClass* self)
{
    return base->GetA(base) % base->GetB(base);
}

