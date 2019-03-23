#include "Common.h"
#include "CSuperClass.h"
#include "CSubClass.h"

void ExecuteSuperClassSample(void);
void ExecuteSubClassSample(void);

int main(void)
{
    printf("Start Super Class Sample : \n");

    ExecuteSuperClassSample();

    printf("\n\n");

    printf("Start Sub Class Sample : \n");

    ExecuteSubClassSample();

    return 0;
}

void ExecuteSuperClassSample(void)
{
    int result = 0;

    CSuperClass* super_class = CSuperClass_Construct2(1, 2);

    super_class->Print(super_class);

    result = super_class->Add(super_class);

    printf("Add Result : %d\n", result);

    result = super_class->Sub(super_class);

    printf("Sub Result : %d\n", result);

    super_class->SetValue(super_class, 3, 5);

    super_class->Print(super_class);

    result = super_class->Add(super_class);

    printf("Add Result : %d\n", result);

    result = super_class->Sub(super_class);

    printf("Sub Result : %d\n", result);

    CSuperClass_Destruct(super_class);
}

void ExecuteSubClassSample(void)
{
    int result = 0;

    CSubClass* sub_class = CSubClass_Construct2(5, 2);

    sub_class->Print(sub_class);

    result = sub_class->Add(sub_class);

    printf("Add Result : %d\n", result);

    result = sub_class->Sub(sub_class);

    printf("Sub Result : %d\n", result);

    result = sub_class->Mul(sub_class);

    printf("Mul Result : %d\n", result);

    result = sub_class->Div(sub_class);

    printf("Div Result : %d\n", result);

    result = sub_class->Mod(sub_class);

    printf("Mod Result : %d\n", result);

    sub_class->SetValue(sub_class, 11, 3);

    sub_class->Print(sub_class);

    result = sub_class->Add(sub_class);

    printf("Add Result : %d\n", result);

    result = sub_class->Sub(sub_class);

    printf("Sub Result : %d\n", result);

    result = sub_class->Mul(sub_class);

    printf("Mul Result : %d\n", result);

    result = sub_class->Div(sub_class);

    printf("Div Result : %d\n", result);

    result = sub_class->Mod(sub_class);

    printf("Mod Result : %d\n", result);

    CSubClass_Destruct(sub_class);
}

