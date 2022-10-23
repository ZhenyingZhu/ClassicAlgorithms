#include <iostream>
#include "BulkItem.h"

using std::size_t;
using std::string;
using std::cout;
using std::endl;

namespace cppprimer {

BulkItem::BulkItem(std::string book, double p, double disc, int m):
        /* Source: Chapter 15.4.2
         * Description: Use parent constructor.
         */
                 ItemBase(book, p), minQty(m), discount(disc) {
    /* Source: Chapter 15.2.4
     * Description: Call parent method.
     */
    // ItemBase::setIsbn(book);
}

double BulkItem::net_price(size_t cnt) const {
    if (cnt < minQty) {
        return cnt * price;
    } else {
        return cnt * price * (1 - discount);
    }
}

void BulkItem::memfcn(const BulkItem &d, const ItemBase &b) const {
    /* Source: Chapter 15.2.2
     * Description: see how protected var works.
     * Since ItemBase use protected on price,
     * BulkItem cannot access other ItemBase entities' price.
     * But BulkItem entities can access other BulkItems' price.
     */
    cout << "Self price: " << price << endl;
    // Cannot access self isbn because this is private in parent class
    //cout << "Self book: " << isbn << endl;
    cout << "Self discount: " << discount << endl;
    cout << "Self minQty: " << minQty << endl;
    // Protected
    cout << "Other's price: " << d.price << endl;
    // Private
    cout << "Other's discount: " << d.discount << endl;
    // Cannot access parent entity's price because it is protected
    //cout << "Base's price: " << b.price << endl;
}

} // cppprimer
