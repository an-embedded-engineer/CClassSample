#include "Common.h"
#include "CSuperClass.h"

typedef struct CSuperClassImpl_
{
    int m_A;
    int m_B;
}CSuperClassImpl;

static void CSuperClass_Print(CSuperClass* self);
static void CSuperClass_SetValue(CSuperClass* self, int a, int b);
static int CSuperClass_Add(CSuperClass* self);
static int CSuperClass_Sub(CSuperClass* self);
static int CSuperClass_GetA(CSuperClass* self);
static int CSuperClass_GetB(CSuperClass* self);


CSuperClass* CSuperClass_Construct1()
{
    return CSuperClass_Construct2(0, 0);
}

CSuperClass* CSuperClass_Construct2(int a, int b)
{
    CSuperClassImpl* impl = new_object(CSuperClassImpl)
    {
        impl->m_A = a;
        impl->m_B = b;
    };

    CSuperClass* instance = new_object(CSuperClass)
    {
        instance->impl = impl;
        instance->Print = CSuperClass_Print;
        instance->SetValue = CSuperClass_SetValue;
        instance->Add = CSuperClass_Add;
        instance->Sub = CSuperClass_Sub;
        instance->GetA = CSuperClass_GetA;
        instance->GetB = CSuperClass_GetB;
    };

    return instance;
}

void CSuperClass_Destruct(CSuperClass* self)
{
    delete_object(self->impl);

    delete_object(self);
}

static void CSuperClass_Print(CSuperClass* self)
{
    printf("A : %d, B : %d\n", this->m_A, this->m_B);
}

static void CSuperClass_SetValue(CSuperClass* self, int a, int b)
{
    this->m_A = a;

    this->m_B = b;
}

static int CSuperClass_Add(CSuperClass* self)
{
    return this->m_A + this->m_B;
}

static int CSuperClass_Sub(CSuperClass* self)
{
    return this->m_A - this->m_B;
}

static int CSuperClass_GetA(CSuperClass* self)
{
    return this->m_A;
}

static int CSuperClass_GetB(CSuperClass* self)
{
    return this->m_B;
}
