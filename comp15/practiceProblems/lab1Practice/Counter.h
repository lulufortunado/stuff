#include <iostream>
using namespace std;

template<typename T>
class Counter {
public:
    Counter()
    {
      ++count;
    }
    Counter(const Counter&)
    {
      ++count;
    }
    ~Counter()
    {
      --count;
    }

    static int getCount()
    {
      return count;
    }

private:
    static int count;
};

template<typename T> int Counter<T>::count = 0;
