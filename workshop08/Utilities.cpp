// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/17
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;

        for (auto i = 0u; i < desc.size(); i++) {
            for (auto a = 0u; a < price.size(); a++) {
                if (desc[i].code == price[a].code) {
                    Product* p = new Product(desc[i].desc, price[a].price);
                    p->validate();
                    priceList += p;
                    delete p;
                }
            }
        }
        return priceList;
    }

    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        for (auto i = 0u; i < desc.size(); i++) {
            for (auto a = 0u; a < price.size(); a++) {
                if (desc[i].code == price[a].code) {
                    unique_ptr<Product> p(new Product(desc[i].desc, price[a].price));
                    p->validate();
                    priceList += std::move(p);
                }
            }
        }
        return priceList;
    }
}