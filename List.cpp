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

//êîíñòðóêòîð êîïèðîâàíèÿ
List::List(const List& other) :m_size(other.m_size)
{

    Head.pNext = &Tail;
    Tail.pPrev = &Head;
    Node* pThis = &Head;
    Node* pOther = other.Head.pNext;
    for (int i = 0; i < m_size; i++)
    {
        pThis = new Node(pThis, *(pOther->pData));
        pOther = pOther->pNext;
    }

}

List& List::operator=(const List& other)
{
    if (this != &other)
    {
        clean();
        Head.pNext = &Tail;
        Tail.pPrev = &Head;

        Node* pOther = other.Head.pNext;
        //for (int i = 0; i < m_size; i++)
        while (pOther != &other.Tail)
        {
            this->AddToTail(*pOther->pData);
           //std::cout << *this << std::endl;	 //îòëàäî÷íàÿ ïå÷àòü
            pOther = pOther->pNext;
        }
        return *this;
    }
}

List::List(List&& other) :m_size(other.m_size)
{

    if ((other.m_size != 0) && (this!=&other))
    {
        Head.pNext = other.Head.pNext; //ïåðåêèäûâàþ óêàçàòåëè ãîëîâ
        Tail.pPrev = other.Tail.pPrev; //ïåðåêèäûâàþ óêàçàòåëè õâîñòîâ
        Head.pNext->pPrev = &Head;
        Tail.pPrev->pNext = &Tail;
        m_size = other.m_size;
        other.Head.pNext = &other.Tail;
        other.Tail.pPrev = &other.Head;
        other.clean();
    }
    else
    {
        Head.pNext = &Tail;
        Tail.pPrev = &Head;
    }
}


List& List::operator=(List&& other)
{
    if (this != &other)
    {
        clean();
        if (other.m_size != 0)
        {
            Head.pNext = other.Head.pNext;
            Tail.pPrev = other.Tail.pPrev;
            Head.pNext->pPrev = &Head;
            Tail.pPrev->pNext = &Tail;
            m_size = other.m_size;
            other.Head.pNext = &other.Tail;
            other.Tail.pPrev = &other.Head;
            other.m_size = 0;
        }

    }
    return *this;

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

/*
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
*/

// Ðåàëèçàöèÿ ñðàâíåíèÿ

bool List::srav_area(const Shape* first_sh, const Shape* second_sh) {
    return first_sh->area() > second_sh->area();
}

bool List::srav_color(const Shape* first_sh, const Shape* second_sh) {
    return first_sh->Color_get() > second_sh->Color_get();
}

void List::Sort(SortType type) {
    if (m_size < 2) return;

    bool (List::*pSRAV)(const Shape*, const Shape*) = nullptr;

    if (type == AREA) pSRAV = &List::srav_area;
    else if (type == COLOR) pSRAV = &List::srav_color;

    if (pSRAV == nullptr) return;

    bool swap;
    do {
        swap = false;
        for (Node* current = Head.pNext; current->pNext != &Tail; current = current->pNext) {
            if ((this->*pSRAV)(current->pData, current->pNext->pData)) {
                // Ìåíÿåì ìåñòàìè óêàçàòåëè íà äàííûå
                Shape* tmp = current->pData;
                current->pData = current->pNext->pData;
                current->pNext->pData = tmp;
                swap = true;
            }
        }
    } while (swap);
}

// Âûâîä ñïèñêà â ñòîëáèê
std::ostream& operator<<(std::ostream& os, const List& l) {
    for (List::Node* current = l.Head.pNext; current != &l.Tail; current = current->pNext) {
        current->pData->print(os);
        //std::cout << "----------------" << std::endl;
        //os << "\n";        
    }
    return os;
}