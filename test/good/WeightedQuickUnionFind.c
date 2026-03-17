#include <stdio.h>
#include <stdlib.h>
#include "tgc.h"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
struct array { int* array; int length; };
tgc_t gc;
struct Main;
struct UF;
void* Main_start(struct Main* this);
void* UF_init(struct UF* this, int N);
void* UF_count(struct UF* this);
void* UF_connected(struct UF* this, int p, int q);
void* UF_find(struct UF* this, int p);
void* UF_union(struct UF* this, int p, int q);
struct Main {
  void* (**vtable)();
};
struct UF {
  void* (**vtable)();
  int UF_count;
  struct array* UF_id;
  struct array* UF_sz;
};
void* (*Main_vtable[])() = { Main_start };
void* (*UF_vtable[])() = { UF_init, UF_count, UF_connected, UF_find, UF_union };
void* Main_start(struct Main* this) {
  int ignore;
  struct UF* uf;
  uf = ({ struct UF* res = tgc_calloc(({ extern tgc_t gc; &gc; }), 1, sizeof(*res)); res->vtable = UF_vtable; res; });
  ignore = ({ struct UF* tmp1 = uf; (int) tmp1->vtable[0](tmp1, 1000); });
  printf("%d\n", ({ struct UF* tmp1 = uf; (int) tmp1->vtable[4](tmp1, 1, 2); }));
  printf("%d\n", ({ struct UF* tmp1 = uf; (int) tmp1->vtable[4](tmp1, 3, 4); }));
  if (({ struct UF* tmp1 = uf; (int) tmp1->vtable[2](tmp1, 1, 2); })) {
    printf("%d\n", 1);
  }
  else {
    printf("%d\n", 0);
  }
  printf("%d\n", ({ struct UF* tmp1 = uf; (int) tmp1->vtable[4](tmp1, 5, 9); }));
  printf("%d\n", ({ struct UF* tmp1 = uf; (int) tmp1->vtable[4](tmp1, 9, 1); }));
  if (({ struct UF* tmp1 = uf; (int) tmp1->vtable[2](tmp1, 9, 4); })) {
    printf("%d\n", 1);
  }
  else {
    printf("%d\n", 0);
  }
  printf("%d\n", ({ struct UF* tmp1 = uf; (int) tmp1->vtable[1](tmp1); }));
  printf("%d\n", ({ struct UF* tmp1 = uf; (int) tmp1->vtable[4](tmp1, 3, 4); }));
  if (({ struct UF* tmp1 = uf; (int) tmp1->vtable[2](tmp1, 100, 200); })) {
    printf("%d\n", 1);
  }
  else {
    printf("%d\n", 0);
  }
  printf("%d\n", ({ struct UF* tmp1 = uf; (int) tmp1->vtable[4](tmp1, 200, 4); }));
  printf("%d\n", ({ struct UF* tmp1 = uf; (int) tmp1->vtable[1](tmp1); }));
  printf("%d\n", ({ struct UF* tmp1 = uf; (int) tmp1->vtable[4](tmp1, 200, 1); }));
  if (({ struct UF* tmp1 = uf; (int) tmp1->vtable[2](tmp1, 4, 300); })) {
    printf("%d\n", 1);
  }
  else {
    printf("%d\n", 0);
  }
  return (void*)(0);
}
void* UF_init(struct UF* this, int N) {
  int i;
  this->UF_count = N;
  this->UF_id = (void*)({ int tmp1 = N; if (tmp1 < 0) exit(1); struct array* res = tgc_alloc(({ extern tgc_t gc; &gc; }), sizeof(struct array)); res->array = (int*) tgc_calloc(({ extern tgc_t gc; &gc; }), tmp1, sizeof(int)); res->length = tmp1; res; });
  this->UF_sz = (void*)({ int tmp1 = N; if (tmp1 < 0) exit(1); struct array* res = tgc_alloc(({ extern tgc_t gc; &gc; }), sizeof(struct array)); res->array = (int*) tgc_calloc(({ extern tgc_t gc; &gc; }), tmp1, sizeof(int)); res->length = tmp1; res; });
  i = 0;
  while ((i < N)) {
    (this->UF_id)->array[i] = i;
    (this->UF_sz)->array[i] = 1;
    i = (i + 1);
  }
  return (void*)(0);
}
void* UF_count(struct UF* this) {
  return (void*)(this->UF_count);
}
void* UF_connected(struct UF* this, int p, int q) {
  int fp;
  int fq;
  fp = ({ struct UF* tmp1 = this; (int) tmp1->vtable[3](tmp1, p); });
  fq = ({ struct UF* tmp1 = this; (int) tmp1->vtable[3](tmp1, q); });
  return (void*)((!((fp < fq)) && !((fq < fp))));
}
void* UF_find(struct UF* this, int p) {
  while (!((!((p < ({ int tmp1 = p; struct array* tmp2 = this->UF_id; int res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; }))) && !((({ int tmp1 = p; struct array* tmp2 = this->UF_id; int res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; }) < p))))) {
    p = ({ int tmp1 = p; struct array* tmp2 = this->UF_id; int res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; });
  }
  return (void*)(p);
}
void* UF_union(struct UF* this, int p, int q) {
  int res;
  int i;
  int j;
  i = ({ struct UF* tmp1 = this; (int) tmp1->vtable[3](tmp1, p); });
  j = ({ struct UF* tmp1 = this; (int) tmp1->vtable[3](tmp1, q); });
  if ((!((i < j)) && !((j < i)))) {
    res = 0;
  }
  else {
    if ((({ int tmp1 = i; struct array* tmp2 = this->UF_sz; int res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; }) < ({ int tmp1 = j; struct array* tmp2 = this->UF_sz; int res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; }))) {
      (this->UF_id)->array[i] = j;
      (this->UF_sz)->array[j] = (({ int tmp1 = j; struct array* tmp2 = this->UF_sz; int res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; }) + ({ int tmp1 = i; struct array* tmp2 = this->UF_sz; int res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; }));
    }
    else {
      (this->UF_id)->array[j] = i;
      (this->UF_sz)->array[i] = (({ int tmp1 = i; struct array* tmp2 = this->UF_sz; int res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; }) + ({ int tmp1 = j; struct array* tmp2 = this->UF_sz; int res; if (tmp1 < 0 || tmp1 >= tmp2->length) exit(1); else res = tmp2->array[tmp1]; res; }));
    }
    this->UF_count = (this->UF_count - 1);
    res = 1;
  }
  return (void*)(res);
}
int main(int argc, char *argv[]) {
  tgc_start(&gc, &argc);
  printf("%d\n", ({ struct Main* tmp1 = ({ struct Main* res = tgc_calloc(({ extern tgc_t gc; &gc; }), 1, sizeof(*res)); res->vtable = Main_vtable; res; }); (int) tmp1->vtable[0](tmp1); }));
  tgc_stop(&gc);

  return 0;
}
