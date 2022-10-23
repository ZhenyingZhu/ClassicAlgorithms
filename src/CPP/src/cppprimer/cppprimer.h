#ifndef SRC_CPPPRIMER_CPPPRIMER_H_
#define SRC_CPPPRIMER_CPPPRIMER_H_

#include "TextQuery.h"
#include "ItemBase.h"
#include "BulkItem.h"
#include "QueryBase.h"
#include "Query.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "BinaryQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

namespace cppprimer {

int printHello();
int stringOperations();
int collectionErase();
int queueOperations();
int mapOperations();
int wordsTransform(int argc, char **argv);
// Class methods no need to add to here.
int testQuery(int argc, char **argv);
int testWordQuery(int argc, char **argv);
}

#endif /* SRC_CPPPRIMER_CPPPRIMER_H_ */
