#include <cassert>
#include "Set.h"
#include "SetIterator.h"

void testPrevious() {
    Set set;
    assert(set.add(1) == true);
    assert(set.add(2) == true);
    assert(set.add(3) == true);
    assert(set.add(4) == true);

    SetIterator it = set.iterator();

    assert(it.getCurrent() == 1);
    assert(it.valid() == true);

    it.next();
    assert(it.getCurrent() == 2);
    assert(it.valid() == true);

    it.next();
    assert(it.getCurrent() == 3);
    assert(it.valid() == true);

    it.next();
    assert(it.getCurrent() == 4);
    assert(it.valid() == true);

    it.previous();
    assert(it.getCurrent() == 3);
    assert(it.valid() == true);

}
