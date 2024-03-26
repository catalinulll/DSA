#include "Bag.h"

class BagIterator
{
    //DO NOT CHANGE THIS PART
    friend class Bag;

private:
    const Bag& bag;
    int currentElement;
    int currentFrequency;
    BagIterator(const Bag& c);

public:
    void first();
    void last();
    void next();
    void previous();
    TElem getCurrent() const;
    bool valid() const;
};
