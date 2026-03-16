#include <stdio.h>
#include <stdlib.h>
#include "tgc.h"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
struct array { int* array; int length; };
tgc_t gc;
struct Fac;
void* Fac_computeFac(struct Fac* this);
struct Fac {
  void* (**vtable)();
};
void* (*Fac_vtable[])() = { Fac_computeFac };
void* Fac_computeFac(struct Fac* this) {
  