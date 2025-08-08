#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

static void tree_printLeaf(FILE *f, Tree *tree);
static void tree_printBranch(FILE *f, Tree *tree);
static char *escape(char *dest, const char *src);
static char *prettyPrintName(char *dest, Tree *tree);

void tree_Print(Tree *tree, int level) {
  int i;
  for(i=0; i<level; i++)
    printf(" ");

  if (tree->tok.id != 0) {
    printf("%d   %s (%d): %d\n", tree->id, tree->tok.text, tree->tok.cat, tree->tok.lineno);
  } else {
    printf("%d   %s (%d): %d\n", tree->id, tree->sym, tree->rule, tree->nkids);
  }

  for(i=0; i<tree->nkids; i++)
    tree_Print(tree->kids[i], level+1);
}

void tree_PrintGraph(FILE *f, Tree *tree) {
  int i;
  if (tree->tok.id != 0) {
    tree_printLeaf(f, tree);
    return;
  }

  // from here on out, we know we are not a leaf
  tree_printBranch(f, tree);

  for(i=0; i<tree->nkids; i++) {
    Tree *child = tree->kids[i];
    fprintf(f, "N%d -> N%d;\n", tree->id, child->id);
    tree_PrintGraph(f, child);
  }
}

void tree_Free(Tree *tree) {
  if (!tree)
    return;

  for (int i = 0; i < tree->nkids; i++) {
    Tree *child = tree->kids[i];
    tree_Free(child);
  }
  free(tree->kids);

  free(tree->tok.text);
  free(tree);
}

static void tree_printLeaf(FILE *f, Tree *tree) {
  const char *s = token_Name(tree->tok.cat);
  tree_printBranch(f, tree);
  fprintf(f, "N%d [shape=box style=dotted label=\" %s \\n ", tree->id, s);

  char escapedText[strlen(tree->tok.text)+3];
  fprintf(f, "text = %s \\l lineno = %d \\l\"];\n", escape(escapedText, tree->tok.text), tree->tok.lineno);
}

static void tree_printBranch(FILE *f, Tree *tree) {
  fprintf(f, "N%d ", tree->id);

  int prettyNameLen = tree->tok.id == 0 ? (strlen(tree->sym)+3) : (strlen(tree->tok.text)+10);
  char prettyName[prettyNameLen];
  fprintf(f, "[shape=box label=\"%s", prettyPrintName(prettyName, tree));

  if (tree->tok.id != 0)
    fprintf(f, "struct token* leaf %d", tree->tok.id);

  fprintf(f, "\"];\n");
}

static char *escape(char *dest, const char *src) {
  if (src[0] == '"') {
    int len = strlen(src);
    dest[0] = '\\';
    strncat(dest, src, len-1);
    strcat(dest, "\\\"");
  } else {
    strcpy(dest, src);
  }

  return dest;
}

static char *prettyPrintName(char *dest, Tree *tree) {
  if (tree->tok.id == 0) {
    sprintf(dest, "%s#%d", tree->sym, tree->rule%10);
  } else {
    char escapedText[strlen(tree->tok.text)+3];
    sprintf(dest, "%s:%d", escape(escapedText, tree->tok.text), tree->tok.cat);
  }

  return dest;
}
