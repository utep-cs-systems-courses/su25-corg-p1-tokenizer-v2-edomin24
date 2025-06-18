#ifndef BST_INCLUDED
#define BST_INCLUDED

typedef struct BstNode_s {
  struct BstNode_s *children[2];
  char *str;
} BstNode;

extern BstNode *bstRoot;

void bstInsert(BstNode **rootp, char *str);
void bstPrint(BstNode *root);
void bstClear(BstNode **rootp);

#endif // included
