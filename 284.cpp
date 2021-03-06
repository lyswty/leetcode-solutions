// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool _flag;
    int _data;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    _flag=false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(_flag) return _data;
        _flag=true;
        _data=Iterator::next();
        return _data;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(_flag){
            _flag=false;
            return _data;
        }
        return Iterator::next();
	}

	bool hasNext() const {
	    if(_flag) return true;
        if(Iterator::hasNext()) return true;
        return false;
	}
};
