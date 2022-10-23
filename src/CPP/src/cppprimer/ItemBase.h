#ifndef SRC_CPPPRIMER_ITEMBASE_H_
#define SRC_CPPPRIMER_ITEMBASE_H_

#include <string>

namespace cppprimer {

class ItemBase {
    /* Source: Chapter 15.2.1
     * Description: base class.
     */
public:
    ItemBase(std::string book = "", double sales_price = 0.0):
        isbn(book), price(sales_price){}

    std::string book() {
        return isbn;
    }

    virtual double netPrice(std::size_t n) const {
        return n * price;
    }

    virtual ~ItemBase() {};
private:
    std::string isbn;
protected:
    void setIsbn(std::string book) {
        isbn = book;
    }

    double price;
};

} // cppprimer

#endif /* SRC_CPPPRIMER_ITEMBASE_H_ */
