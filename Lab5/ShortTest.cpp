#include <assert.h>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testAll() {
    SortedMultiMap smm(relation1);
    assert(smm.size() == 0);
    assert(smm.isEmpty());
    smm.add(1, 2);
    smm.add(1, 3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v = smm.search(1);
    assert(v.size() == 2);
    v = smm.search(3);
    assert(v.size() == 0);
    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()) {
        TElem e = it.getCurrent();
        it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());

    SortedMultiMap smm(r);
    smm.add(1, 10);
    smm.add(2, 20);
    smm.add(2, 25);
    smm.add(3, 30);
    smm.add(3, 35);
    smm.add(3, 40);

//    SMMIterator it = smm.iterator();
//
//    it.first();
//    assert(it.valid());
//    assert(it.getCurrent().second == 10);
//    it.previous();
//    assert(!it.getCurrent().second == 0);
//

}