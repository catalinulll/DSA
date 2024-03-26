#include "Bag.h"
#include <cassert>
#include "TestMethod.h"
#include "BagIterator.h"

void testMethod() {
    Bag b1;
    assert(b1.isEmpty() == true);
    assert(b1.size() == 0);
    b1.add(5);
    b1.add(1);
    b1.add(10);
    b1.add(7);
    b1.add(1);
    b1.add(11);
    b1.add(-3);
    assert(b1.size() == 7);
    assert(b1.search(10) == true);
    assert(b1.search(16) == false);
    assert(b1.nrOccurrences(1) == 2);
    assert(b1.nrOccurrences(7) == 1);
    assert(b1.remove(1) == true);
    assert(b1.remove(6) == false);
    assert(b1.size() == 6);
    assert(b1.nrOccurrences(1) == 1);

    Bag b2;
    assert(b2.isEmpty() == true);
    assert(b2.size() == 0);
    b2.add(5);
    b2.add(1);
    b2.add(10);
    b2.add(7);
    b2.add(1);
    b2.add(11);
    b2.add(-3);
    assert(b2.size() == 7);
    assert(b2.search(10) == true);
    assert(b2.search(16) == false);
    assert(b2.nrOccurrences(1) == 2);
    assert(b2.nrOccurrences(7) == 1);
    assert(b2.remove(1) == true);
    assert(b2.remove(6) == false);
    assert(b2.size() == 6);
    assert(b2.nrOccurrences(1) == 1);

    b2.reverse();
    BagIterator it1 = b1.iterator();
    BagIterator it2 = b2.iterator();
    it1.first();
    it2.last();

    while (it1.valid() and it2.valid()) {
        TElem element1 = it1.getCurrent();
        TElem element2 = it2.getCurrent();
        assert(element1 == element2);
        it1.next();
        it2.previous();
    }
}
