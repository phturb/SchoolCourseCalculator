#ifndef GENERALFUNCTION_H
#define GENERALFUNCTION_H

#include <iostream>
#include <map>

using namespace std;

template <typename T> class GeneralFunction {
public:
  map<string, T *> getItemList();
  string getName();
  void setName(string name);
  void addItem(T *item);
  void removeItem(string itemName);
  T *getItem(string itemName);
  void deleteItemList();
  void showItems();

protected:
  string name_;
  map<string, T *> itemList_;
};

template <typename T> string GeneralFunction<T>::getName()
{return name_;};
template <typename T> void GeneralFunction<T>::setName(string name)
{name_ = name;};

template <typename T> void GeneralFunction<T>::addItem(T *item) {
  string name = item->getName();
  auto it = itemList_.find(name);
  if (it != itemList_.end()) {
    cout << "Exam deja existant" << endl;
  } else {
    itemList_.insert(std::pair<string, T *>(name, item));
  }
};

template <typename T> void GeneralFunction<T>::removeItem(string itemName) {
  auto it = itemList_.find(itemName);
  if (it != itemList_.end()) {
    itemList_.erase(it);
  } else {
    cout << "The item doesn't exist" << endl;
  }
};

template <typename T> T *GeneralFunction<T>::getItem(string itemName) {
  auto it = itemList_.find(itemName);
  if (it != itemList_.end()) {
    return it->second;
  }
  return new T;
};

template <typename T> map<string, T *> GeneralFunction<T>::getItemList() {
  return itemList_;
};
template <typename T> void GeneralFunction<T>::deleteItemList() {
  for (auto it = itemList_.begin(); it != itemList_.end(); it++) {
    delete it->second;
    itemList_.erase(it);
  }
}

template <typename T> void GeneralFunction<T>::showItems() {
  for (auto it = itemList_.begin(); it != itemList_.end(); it++) {
    cout << *(it->second);
  }
}

#endif
