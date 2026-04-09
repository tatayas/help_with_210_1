#pragma once

#include "Shape.h"

class List {
private:
    class Node {
        friend class List;
        friend std::ostream& operator<<(std::ostream& os, const List& l);

        Node* pPrev;
        Node* pNext;
        Shape* pData; 

        Node() : pPrev(NULL), pNext(NULL), pData(NULL) {}

        Node(Node* p, const Shape& s) : pData(s.copy_()) {
            pPrev = p;
            pNext = p->pNext;
            p->pNext = this;
            pNext->pPrev = this;
        }

        ~Node() {
            delete pData; 
            if (pPrev) pPrev->pNext = pNext;
            if (pNext) pNext->pPrev = pPrev;
        }
    };

    Node Head;
    Node Tail;
    size_t m_size;

public:
    List();
    ~List();

    List(const List& other);
    List& operator=(const List& other);


    //move semantics
    List(List&& other);
    List& operator=(List&& other);

    void AddToTail(const Shape& s);
    void AddToHead(const Shape& s);

    bool Remove(const Shape& s);
    void clean();

    // Сортировка по критерию (указатель на функцию)
    typedef bool (*func_sravn)(const Shape*, const Shape*);
    void Sort(func_sravn srv);

    // Оператор вывода всего списка
    friend std::ostream& operator<<(std::ostream& os, const List& l);
};
