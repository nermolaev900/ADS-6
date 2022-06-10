// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T arr[100];
    int first, last;
 public:
    TPQueue() : first(0), last(0) {}
    void push(T x) {
        if ((last - first < size)) {
            int a = last++;
            while (--a >= first) {
                if (x.prior > arr[a % size].prior) {
                    arr[(a + 1) % size] = arr[a % size];
                } else {
                    break;
                }
            }
            arr[(a + 1) % size] = x;
        }
    }
    T pop() {
        return arr[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
