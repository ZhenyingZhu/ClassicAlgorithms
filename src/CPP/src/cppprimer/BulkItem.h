#ifndef SRC_CPPPRIMER_BULKITEM_H_
#define SRC_CPPPRIMER_BULKITEM_H_

#include <string>
#include "ItemBase.h"

namespace cppprimer {

class BulkItem: public ItemBase {
    /* Source: Chapter 15.2.3
     * Description: derive class
     */
public:
    BulkItem(std::string book, double p = 0.0, double disc = 0.0, int m = 1);
    double net_price(std::size_t) const;
    void memfcn(const BulkItem&, const ItemBase&) const;

    virtual ~BulkItem(){};
private:
    std::size_t minQty;
    double discount;
};

} // cppprimer

#endif /* SRC_CPPPRIMER_BULKITEM_H_ */
