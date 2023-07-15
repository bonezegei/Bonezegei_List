#ifndef __BONEZEGEI_LIST_H_INCLUDED__
#define __BONEZEGEI_LIST_H_INCLUDED__

template<class T>
class Bonezegei_List {
public:
  struct list_obj {
    list_obj()
      : next(0), prev(0){};

    list_obj* next;
    list_obj* prev;
    T object;
  };

  class iterator {
  public:
    iterator()
      : current(0){};
    iterator(list_obj* begin)
      : current(begin){};
    void operator++() {
      current = current->next;
    };
    void operator--() {
      current = current->prev;
    };
    bool operator==(const iterator& other) const {
      return current == other.current;
    };
    bool operator!=(const iterator& other) const {
      return current != other.current;
    };
    T& operator*() {
      return current->object;
    };
  private:
    friend class Bonezegei_List<T>;
    list_obj* current;
  };

  iterator begin() const {
    return iterator(root);
  }


  iterator end() const {
    return iterator(0);
  }

  iterator getLast() const {
    return iterator(last);
  }

  Bonezegei_List()
    : root(0), last(0), size(0) {}

  ~Bonezegei_List() {
    clear();
  }

  void clear() {
    list_obj* obj = root;
    while (obj) {
      list_obj* next = obj->next;
      delete obj;
      obj = next;
    }
    root = 0;
    last = 0;
    size = 0;
  }

  void push_back(const T& object) {
    list_obj* obj = new list_obj;
    obj->object = object;
    size++;
    if (root == 0)
      root = obj;
    obj->prev = last;
    if (last != 0)
      last->next = obj;
    last = obj;
  }

  void push_front(const T& object) {
    list_obj* obj = new list_obj;
    obj->object = object;

    size++;

    if (root == 0) {
      last = obj;
      root = obj;
    } else {
      obj->next = root;
      root->prev = obj;
      root = obj;
    }
  }

  iterator erase(iterator& it) {
    iterator returnIterator(it);
    ++returnIterator;

    if (it.current == root)
      root = it.current->next;

    if (it.current == last)
      last = it.current->prev;

    if (it.current->next)
      it.current->next->prev = it.current->prev;

    if (it.current->prev)
      it.current->prev->next = it.current->next;

    delete it.current;
    it.current = 0;
    --size;

    return returnIterator;
  }


  list_obj* root;
  list_obj* last;
  int size;
};

#endif
