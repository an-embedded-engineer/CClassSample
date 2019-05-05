#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <stdbool.h>

#define new_object(type) (type*)malloc(sizeof(type));

#define delete_object(instance) free(instance); instance = NULL;

#define this self->impl

#define base self->impl->super


