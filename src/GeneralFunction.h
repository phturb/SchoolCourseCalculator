
#include <map>
#include <iostream>

using namespace std;

template <typename T>
class GeneralFunction {
public:
  GeneralFunction();
  ~GeneralFunction();
  void addItem(T* item);
  void removeExam(string itemName);
protected:
  pair<string, T*> itemList_;
};

template<typename T>
void GeneralFunction<T>::addItem(T *item) {
  string name = item->getName();
  auto it = itemList_.find(name);
  if (it != itemList_.end()) {
    cout << "Exam deja existant" << endl;
  } else {
    itemList_.insert(std::pair<string, T *>(name, item));
  }
};
