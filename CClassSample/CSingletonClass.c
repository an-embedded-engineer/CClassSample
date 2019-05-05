#include "Common.h"
#include "CSingletonClass.h"

typedef struct CSingletonClassImpl_
{
    int m_A;
    int m_B;
}CSingletonClassImpl;

static CSingletonClass_Init();
static CSingletonClassImpl* CSingletonClass_GetImpl();
static CSingletonClass* CSingletonClass_Get();


static void CSingletonClass_Print(CSingletonClass* self);
static void CSingletonClass_SetValue(CSingletonClass* self, int a, int b);
static int CSingletonClass_Add(CSingletonClass* self);
static int CSingletonClass_Sub(CSingletonClass* self);
static int CSingletonClass_GetA(CSingletonClass* self);
static int CSingletonClass_GetB(CSingletonClass* self);

static bool s_Initialized = false;

static CSingletonClassImpl s_SingletonClassImplInstance;
static CSingletonClass s_SingletonClassInstance;


CSingletonClass* CSingletonClass_GetInstancce()
{
    if (s_Initialized == false)
    {
        CSingletonClass_Init();
    }

    return CSingletonClass_Get();
}


static CSingletonClass_Init()
{
    CSingletonClassImpl* impl = CSingletonClass_GetImpl();

    impl->m_A = 0;
    impl->m_B = 0;

    CSingletonClass* instance = CSingletonClass_Get();

    instance->impl = impl;
    instance->Print = CSingletonClass_Print;
    instance->SetValue = CSingletonClass_SetValue;
    instance->Add = CSingletonClass_Add;
    instance->Sub = CSingletonClass_Sub;
    instance->GetA = CSingletonClass_GetA;
    instance->GetB = CSingletonClass_GetB;

}

static CSingletonClassImpl* CSingletonClass_GetImpl()
{
    return &s_SingletonClassImplInstance;
}

static CSingletonClass* CSingletonClass_Get()
{
    return &s_SingletonClassInstance;
}

static void CSingletonClass_Print(CSingletonClass* self)
{
    printf("A : %d, B : %d\n", this->m_A, this->m_B);
}

static void CSingletonClass_SetValue(CSingletonClass* self, int a, int b)
{
    this->m_A = a;

    this->m_B = b;
}

static int CSingletonClass_Add(CSingletonClass* self)
{
    return this->m_A + this->m_B;
}

static int CSingletonClass_Sub(CSingletonClass* self)
{
    return this->m_A - this->m_B;
}

static int CSingletonClass_GetA(CSingletonClass* self)
{
    return this->m_A;
}

static int CSingletonClass_GetB(CSingletonClass* self)
{
    return this->m_B;
}
