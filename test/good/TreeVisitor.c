#include <stdio.h>
#include <stdlib.h>
#include "tgc.h"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
struct array { int* array; int length; };
tgc_t gc;
struct TV;
struct Tree;
struct Visitor;
struct MyVisitor;
void* TV_Start(struct TV* this);
void* Tree_Init(struct Tree* this, int v_key);
void* Tree_SetRight(struct Tree* this, struct Tree* rn);
void* Tree_SetLeft(struct Tree* this, struct Tree* ln);
void* Tree_GetRight(struct Tree* this);
void* Tree_GetLeft(struct Tree* this);
void* Tree_GetKey(struct Tree* this);
void* Tree_SetKey(struct Tree* this, int v_key);
void* Tree_GetHas_Right(struct Tree* this);
void* Tree_GetHas_Left(struct Tree* this);
void* Tree_SetHas_Left(struct Tree* this, int val);
void* Tree_SetHas_Right(struct Tree* this, int val);
void* Tree_Compare(struct Tree* this, int num1, int num2);
void* Tree_Insert(struct Tree* this, int v_key);
void* Tree_Delete(struct Tree* this, int v_key);
void* Tree_Remove(struct Tree* this, struct Tree* p_node, struct Tree* c_node);
void* Tree_RemoveRight(struct Tree* this, struct Tree* p_node, struct Tree* c_node);
void* Tree_RemoveLeft(struct Tree* this, struct Tree* p_node, struct Tree* c_node);
void* Tree_Search(struct Tree* this, int v_key);
void* Tree_Print(struct Tree* this);
void* Tree_RecPrint(struct Tree* this, struct Tree* node);
void* Tree_accept(struct Tree* this, struct Visitor* v);
void* Visitor_visit(struct Visitor* this, struct Tree* n);
void* MyVisitor_visit(struct MyVisitor* this, struct Tree* n);
struct TV {
  void* (**vtable)();
};
struct Tree {
  void* (**vtable)();
  int Tree_has_left;
  int Tree_has_right;
  int Tree_key;
  struct Tree* Tree_left;
  struct Tree* Tree_my_null;
  struct Tree* Tree_right;
};
struct Visitor {
  void* (**vtable)();
  struct Tree* Visitor_l;
  struct Tree* Visitor_r;
};
struct MyVisitor {
  void* (**vtable)();
  struct Tree* Visitor_l;
  struct Tree* Visitor_r;
};
void* (*TV_vtable[])() = { TV_Start };
void* (*Tree_vtable[])() = { Tree_Init, Tree_SetRight, Tree_SetLeft, Tree_GetRight, Tree_GetLeft, Tree_GetKey, Tree_SetKey, Tree_GetHas_Right, Tree_GetHas_Left, Tree_SetHas_Left, Tree_SetHas_Right, Tree_Compare, Tree_Insert, Tree_Delete, Tree_Remove, Tree_RemoveRight, Tree_RemoveLeft, Tree_Search, Tree_Print, Tree_RecPrint, Tree_accept };
void* (*Visitor_vtable[])() = { Visitor_visit };
void* (*MyVisitor_vtable[])() = { MyVisitor_visit };
void* TV_Start(struct TV* this) {
  struct Tree* root;
  int ntb;
  int nti;
  struct MyVisitor* v;
  root = ({ struct Tree* res = tgc_calloc(({ extern tgc_t gc; &gc; }), 1, sizeof(*res)); res->vtable = Tree_vtable; res; });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[0](tmp1, 16); });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[18](tmp1); });
  printf("%d\n", 100000000);
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[12](tmp1, 8); });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[12](tmp1, 24); });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[12](tmp1, 4); });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[12](tmp1, 12); });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[12](tmp1, 20); });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[12](tmp1, 28); });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[12](tmp1, 14); });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[18](tmp1); });
  printf("%d\n", 100000000);
  v = ({ struct MyVisitor* res = tgc_calloc(({ extern tgc_t gc; &gc; }), 1, sizeof(*res)); res->vtable = MyVisitor_vtable; res; });
  printf("%d\n", 50000000);
  nti = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[20](tmp1, v); });
  printf("%d\n", 100000000);
  printf("%d\n", ({ struct Tree* tmp1 = root; (int) tmp1->vtable[17](tmp1, 24); }));
  printf("%d\n", ({ struct Tree* tmp1 = root; (int) tmp1->vtable[17](tmp1, 12); }));
  printf("%d\n", ({ struct Tree* tmp1 = root; (int) tmp1->vtable[17](tmp1, 16); }));
  printf("%d\n", ({ struct Tree* tmp1 = root; (int) tmp1->vtable[17](tmp1, 50); }));
  printf("%d\n", ({ struct Tree* tmp1 = root; (int) tmp1->vtable[17](tmp1, 12); }));
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[13](tmp1, 12); });
  ntb = ({ struct Tree* tmp1 = root; (int) tmp1->vtable[18](tmp1); });
  printf("%d\n", ({ struct Tree* tmp1 = root; (int) tmp1->vtable[17](tmp1, 12); }));
  return (void*)(0);
}
void* Tree_Init(struct Tree* this, int v_key) {
  this->Tree_key = v_key;
  this->Tree_has_left = 0;
  this->Tree_has_right = 0;
  return (void*)(1);
}
void* Tree_SetRight(struct Tree* this, struct Tree* rn) {
  this->Tree_right = rn;
  return (void*)(1);
}
void* Tree_SetLeft(struct Tree* this, struct Tree* ln) {
  this->Tree_left = ln;
  return (void*)(1);
}
void* Tree_GetRight(struct Tree* this) {
  return (void*)(this->Tree_right);
}
void* Tree_GetLeft(struct Tree* this) {
  return (void*)(this->Tree_left);
}
void* Tree_GetKey(struct Tree* this) {
  return (void*)(this->Tree_key);
}
void* Tree_SetKey(struct Tree* this, int v_key) {
  this->Tree_key = v_key;
  return (void*)(1);
}
void* Tree_GetHas_Right(struct Tree* this) {
  return (void*)(this->Tree_has_right);
}
void* Tree_GetHas_Left(struct Tree* this) {
  return (void*)(this->Tree_has_left);
}
void* Tree_SetHas_Left(struct Tree* this, int val) {
  this->Tree_has_left = val;
  return (void*)(1);
}
void* Tree_SetHas_Right(struct Tree* this, int val) {
  this->Tree_has_right = val;
  return (void*)(1);
}
void* Tree_Compare(struct Tree* this, int num1, int num2) {
  int ntb;
  int nti;
  ntb = 0;
  nti = (num2 + 1);
  if ((num1 < num2)) ntb = 0;
  else if (!((num1 < nti))) ntb = 0;
  else ntb = 1;
  return (void*)(ntb);
}
void* Tree_Insert(struct Tree* this, int v_key) {
  struct Tree* new_node;
  int ntb;
  struct Tree* current_node;
  int cont;
  int key_aux;
  new_node = ({ struct Tree* res = tgc_calloc(({ extern tgc_t gc; &gc; }), 1, sizeof(*res)); res->vtable = Tree_vtable; res; });
  ntb = ({ struct Tree* tmp1 = new_node; (int) tmp1->vtable[0](tmp1, v_key); });
  current_node = this;
  cont = 1;
  while (cont) {
    key_aux = ({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[5](tmp1); });
    if ((v_key < key_aux)) {
      if (({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[8](tmp1); })) current_node = ({ struct Tree* tmp1 = current_node; (struct Tree*) tmp1->vtable[4](tmp1); });
      else {
        cont = 0;
        ntb = ({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[9](tmp1, 1); });
        ntb = ({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[2](tmp1, new_node); });
      }
    }
    else {
      if (({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[7](tmp1); })) current_node = ({ struct Tree* tmp1 = current_node; (struct Tree*) tmp1->vtable[3](tmp1); });
      else {
        cont = 0;
        ntb = ({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[10](tmp1, 1); });
        ntb = ({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[1](tmp1, new_node); });
      }
    }
  }
  return (void*)(1);
}
void* Tree_Delete(struct Tree* this, int v_key) {
  struct Tree* current_node;
  struct Tree* parent_node;
  int cont;
  int found;
  int ntb;
  int is_root;
  int key_aux;
  current_node = this;
  parent_node = this;
  cont = 1;
  found = 0;
  is_root = 1;
  while (cont) {
    key_aux = ({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[5](tmp1); });
    if ((v_key < key_aux)) if (({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[8](tmp1); })) {
      parent_node = current_node;
      current_node = ({ struct Tree* tmp1 = current_node; (struct Tree*) tmp1->vtable[4](tmp1); });
    }
    else cont = 0;
    else if ((key_aux < v_key)) if (({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[7](tmp1); })) {
      parent_node = current_node;
      current_node = ({ struct Tree* tmp1 = current_node; (struct Tree*) tmp1->vtable[3](tmp1); });
    }
    else cont = 0;
    else {
      if (is_root) if ((!(({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[7](tmp1); })) && !(({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[8](tmp1); })))) ntb = 1;
      else ntb = ({ struct Tree* tmp1 = this; (int) tmp1->vtable[14](tmp1, parent_node, current_node); });
      else ntb = ({ struct Tree* tmp1 = this; (int) tmp1->vtable[14](tmp1, parent_node, current_node); });
      found = 1;
      cont = 0;
    }
    is_root = 0;
  }
  return (void*)(found);
}
void* Tree_Remove(struct Tree* this, struct Tree* p_node, struct Tree* c_node) {
  int ntb;
  int auxkey1;
  int auxkey2;
  if (({ struct Tree* tmp1 = c_node; (int) tmp1->vtable[8](tmp1); })) ntb = ({ struct Tree* tmp1 = this; (int) tmp1->vtable[16](tmp1, p_node, c_node); });
  else if (({ struct Tree* tmp1 = c_node; (int) tmp1->vtable[7](tmp1); })) ntb = ({ struct Tree* tmp1 = this; (int) tmp1->vtable[15](tmp1, p_node, c_node); });
  else {
    auxkey1 = ({ struct Tree* tmp1 = c_node; (int) tmp1->vtable[5](tmp1); });
    auxkey2 = ({ struct Tree* tmp1 = ({ struct Tree* tmp1 = p_node; (struct Tree*) tmp1->vtable[4](tmp1); }); (int) tmp1->vtable[5](tmp1); });
    if (({ struct Tree* tmp1 = this; (int) tmp1->vtable[11](tmp1, auxkey1, auxkey2); })) {
      ntb = ({ struct Tree* tmp1 = p_node; (int) tmp1->vtable[2](tmp1, this->Tree_my_null); });
      ntb = ({ struct Tree* tmp1 = p_node; (int) tmp1->vtable[9](tmp1, 0); });
    }
    else {
      ntb = ({ struct Tree* tmp1 = p_node; (int) tmp1->vtable[1](tmp1, this->Tree_my_null); });
      ntb = ({ struct Tree* tmp1 = p_node; (int) tmp1->vtable[10](tmp1, 0); });
    }
  }
  return (void*)(1);
}
void* Tree_RemoveRight(struct Tree* this, struct Tree* p_node, struct Tree* c_node) {
  int ntb;
  while (({ struct Tree* tmp1 = c_node; (int) tmp1->vtable[7](tmp1); })) {
    ntb = ({ struct Tree* tmp1 = c_node; (int) tmp1->vtable[6](tmp1, ({ struct Tree* tmp1 = ({ struct Tree* tmp1 = c_node; (struct Tree*) tmp1->vtable[3](tmp1); }); (int) tmp1->vtable[5](tmp1); })); });
    p_node = c_node;
    c_node = ({ struct Tree* tmp1 = c_node; (struct Tree*) tmp1->vtable[3](tmp1); });
  }
  ntb = ({ struct Tree* tmp1 = p_node; (int) tmp1->vtable[1](tmp1, this->Tree_my_null); });
  ntb = ({ struct Tree* tmp1 = p_node; (int) tmp1->vtable[10](tmp1, 0); });
  return (void*)(1);
}
void* Tree_RemoveLeft(struct Tree* this, struct Tree* p_node, struct Tree* c_node) {
  int ntb;
  while (({ struct Tree* tmp1 = c_node; (int) tmp1->vtable[8](tmp1); })) {
    ntb = ({ struct Tree* tmp1 = c_node; (int) tmp1->vtable[6](tmp1, ({ struct Tree* tmp1 = ({ struct Tree* tmp1 = c_node; (struct Tree*) tmp1->vtable[4](tmp1); }); (int) tmp1->vtable[5](tmp1); })); });
    p_node = c_node;
    c_node = ({ struct Tree* tmp1 = c_node; (struct Tree*) tmp1->vtable[4](tmp1); });
  }
  ntb = ({ struct Tree* tmp1 = p_node; (int) tmp1->vtable[2](tmp1, this->Tree_my_null); });
  ntb = ({ struct Tree* tmp1 = p_node; (int) tmp1->vtable[9](tmp1, 0); });
  return (void*)(1);
}
void* Tree_Search(struct Tree* this, int v_key) {
  struct Tree* current_node;
  int ifound;
  int cont;
  int key_aux;
  current_node = this;
  cont = 1;
  ifound = 0;
  while (cont) {
    key_aux = ({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[5](tmp1); });
    if ((v_key < key_aux)) if (({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[8](tmp1); })) current_node = ({ struct Tree* tmp1 = current_node; (struct Tree*) tmp1->vtable[4](tmp1); });
    else cont = 0;
    else if ((key_aux < v_key)) if (({ struct Tree* tmp1 = current_node; (int) tmp1->vtable[7](tmp1); })) current_node = ({ struct Tree* tmp1 = current_node; (struct Tree*) tmp1->vtable[3](tmp1); });
    else cont = 0;
    else {
      ifound = 1;
      cont = 0;
    }
  }
  return (void*)(ifound);
}
void* Tree_Print(struct Tree* this) {
  int ntb;
  struct Tree* current_node;
  current_node = this;
  ntb = ({ struct Tree* tmp1 = this; (int) tmp1->vtable[19](tmp1, current_node); });
  return (void*)(1);
}
void* Tree_RecPrint(struct Tree* this, struct Tree* node) {
  int ntb;
  if (({ struct Tree* tmp1 = node; (int) tmp1->vtable[8](tmp1); })) {
    ntb = ({ struct Tree* tmp1 = this; (int) tmp1->vtable[19](tmp1, ({ struct Tree* tmp1 = node; (struct Tree*) tmp1->vtable[4](tmp1); })); });
  }
  else ntb = 1;
  printf("%d\n", ({ struct Tree* tmp1 = node; (int) tmp1->vtable[5](tmp1); }));
  if (({ struct Tree* tmp1 = node; (int) tmp1->vtable[7](tmp1); })) {
    ntb = ({ struct Tree* tmp1 = this; (int) tmp1->vtable[19](tmp1, ({ struct Tree* tmp1 = node; (struct Tree*) tmp1->vtable[3](tmp1); })); });
  }
  else ntb = 1;
  return (void*)(1);
}
void* Tree_accept(struct Tree* this, struct Visitor* v) {
  int nti;
  printf("%d\n", 333);
  nti = ({ struct Visitor* tmp1 = v; (int) tmp1->vtable[0](tmp1, this); });
  return (void*)(0);
}
void* Visitor_visit(struct Visitor* this, struct Tree* n) {
  int nti;
  if (({ struct Tree* tmp1 = n; (int) tmp1->vtable[7](tmp1); })) {
    this->Visitor_r = ({ struct Tree* tmp1 = n; (struct Tree*) tmp1->vtable[3](tmp1); });
    nti = ({ struct Tree* tmp1 = this->Visitor_r; (int) tmp1->vtable[20](tmp1, this); });
  }
  else nti = 0;
  if (({ struct Tree* tmp1 = n; (int) tmp1->vtable[8](tmp1); })) {
    this->Visitor_l = ({ struct Tree* tmp1 = n; (struct Tree*) tmp1->vtable[4](tmp1); });
    nti = ({ struct Tree* tmp1 = this->Visitor_l; (int) tmp1->vtable[20](tmp1, this); });
  }
  else nti = 0;
  return (void*)(0);
}
void* MyVisitor_visit(struct MyVisitor* this, struct Tree* n) {
  int nti;
  if (({ struct Tree* tmp1 = n; (int) tmp1->vtable[7](tmp1); })) {
    this->Visitor_r = ({ struct Tree* tmp1 = n; (struct Tree*) tmp1->vtable[3](tmp1); });
    nti = ({ struct Tree* tmp1 = this->Visitor_r; (int) tmp1->vtable[20](tmp1, this); });
  }
  else nti = 0;
  printf("%d\n", ({ struct Tree* tmp1 = n; (int) tmp1->vtable[5](tmp1); }));
  if (({ struct Tree* tmp1 = n; (int) tmp1->vtable[8](tmp1); })) {
    this->Visitor_l = ({ struct Tree* tmp1 = n; (struct Tree*) tmp1->vtable[4](tmp1); });
    nti = ({ struct Tree* tmp1 = this->Visitor_l; (int) tmp1->vtable[20](tmp1, this); });
  }
  else nti = 0;
  return (void*)(0);
}
int main(int argc, char *argv[]) {
  tgc_start(&gc, &argc);
  printf("%d\n", ({ struct TV* tmp1 = ({ struct TV* res = tgc_calloc(({ extern tgc_t gc; &gc; }), 1, sizeof(*res)); res->vtable = TV_vtable; res; }); (int) tmp1->vtable[0](tmp1); }));
  tgc_stop(&gc);

  return 0;
}
