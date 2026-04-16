#include <stdio.h>
#include <stdlib.h>
#include "tgc.h"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
struct array { int* array; int length; };
struct arrayfloat { float* array; int length; };
struct arraychar { char** array; int length; };
tgc_t gc;
struct Fac;
void* Fac_computeFac(struct Fac* this, int num);
struct Fac {
  void* (**vtable)();
};
void* (*Fac_vtable[])() = { Fac_computeFac };
void* Fac_computeFac(struct Fac* this, int num) {
  struct arraychar* s;
  int i;
  s = (void*)({ int tmp1 = 5; if (tmp1 < 0) exit(1); struct arraychar* res = tgc_alloc(({ extern tgc_t gc; &gc; }), sizeof(struct arraychar)); res->array = tgc_calloc(({ extern tgc_t gc; &gc; }), tmp1, sizeof(int)); res->length = tmp1; res; });
  i = 0;
  while ((i < 5)) {
    (s)->array[i] = "toto";
    i = (i + 1);
  }
  printf("%s\n", ({ int tmp1 = 0; struct arraychar* tmp2 = s; char* res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; }));
  return (void*)(0);
}
int main(int argc, char *argv[]) {
  tgc_start(&gc, &argc);
  printf("%d\n", ({ struct Fac* tmp1 = ({ struct Fac* res = tgc_calloc(({ extern tgc_t gc; &gc; }), 1, sizeof(*res)); res->vtable = Fac_vtable; res; }); (int) tmp1->vtable[0](tmp1, 0); }));
  tgc_stop(&gc);

  return 0;
}
