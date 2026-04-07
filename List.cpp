#include "List.h"

List::List() {
    Head.pNext = &Tail;
    Tail.pPrev = &Head;
    m_size = 0;
}

List::~List() {
    clean();
}

void List::clean() {
    while (Head.pNext != &Tail) {
        delete Head.pNext; 
    }
    m_size = 0;
}

void List::AddToTail(const Shape& s) {
    new Node(Tail.pPrev, s); 
    m_size++;
}

void List::AddToHead(const Shape& s) {
    new Node(&Head, s); 
    m_size++;
}

bool List::Remove(const Shape& s) {
    for (Node* current = Head.pNext; current != &Tail; current = current->pNext) {
        if (*(current->pData) == s) {
            delete current;
            m_size--;
            return true;
        }
    }
    return false;
}

void List::Sort(func_sravn srv) {
    if (m_size < 2) return;
    bool swap;
    do {
        swap = false;
        for (Node* current = Head.pNext; current->pNext != &Tail; current = current->pNext) {
            if (srv(current->pData, current->pNext->pData)) {
                Shape* tmp = current->pData;
                current->pData = current->pNext->pData;
                current->pNext->pData = tmp;
                swap = true;
            }
        }
    } while (swap);
}

// Вывод списка в столбик
std::ostream& operator<<(std::ostream& os, const List& l) {
    for (List::Node* current = l.Head.pNext; current != &l.Tail; current = current->pNext) {
        current->pData->print(os);
        os << "\n";
    }
    return os;
}