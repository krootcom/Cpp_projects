#include <list>
class Item {
    private:
        int Value;
    
    public:
        Item(int value) {
            Value = value;
        }
};

template <class Item>
class Iterator {
    public:
        virtual void First() = 0;
        virtual void Next() = 0;
        virtual bool IsDone() = 0;
        virtual Item CurrentItem() const = 0;
    protected:
        Iterator();
};

template <class Item>
class ListIterator : public Iterator<Item> {
    public:
        ListIterator(const List<Item>* aList);
        virtual void First();
        virtual void Next();
        virtual bool IsDone() const;
        virtual Item CurrentItem() const;

    private:
        const List<Item>* _list;
        long _current;
};

template <class Item>
ListIterator<Item>::ListIterator(const List<Item>* aList): _list(aList), _current(0) {}

template <class Item>
void ListIterator<Item>::First () {
    _current = 0;
}

template <class Item>
void ListIterator<Item>::Next () {
    _current++;
}

template <class Item>
bool ListIterator<Item>::IsDone () const {
    if(IsDone()) {
        throw IteratorOutOfBounds;
    }
    return _list->Get(_current);
}

int main() {

}
