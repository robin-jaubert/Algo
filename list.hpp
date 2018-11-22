#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"

template <typename T>
class CList
{
private:
    CNode<T>* m_Head;
public:
    CList();
    ~CList();
    void push_front(const T & val);
    void Show() const;
    CNode<T>* Find(const T & val) const;
    void Add(const T & val, CNode<T>*);
    void Delete(CNode<T>*);
    CNode<T> *getHead() const;
    void setHead(CNode<T> *Head);
};

#endif // LIST_HPP

template<typename T>
CList<T>::CList(){}

template<typename T>
CList<T>::~CList(){}

template<typename T>
void CList<T>::push_front(const T &val)
{
    m_Head = new CNode<T>(val, m_Head);
}

template<typename T>
void CList<T>::Show() const
{
    for(CNode<T>* ptr(m_Head); ptr != nullptr; ptr = ptr->getMNext()){
        std::cout << ptr->getMData() << "; ";
    }
}

template<typename T>
CNode<T> *CList<T>::Find(const T &val) const
{
    CNode<T>* ptr(getHead());
    for ( ; ptr != nullptr && ptr->getMData() != val; ptr = ptr->getMNext());
    return ptr;
}

template<typename T>
void CList<T>::Add(const T &val, CNode<T> *ptr)
{
    if (nullptr == ptr) return;
    CNode<T>* ptrTmp = new CNode<T> (val, ptr->getMNext());
    ptr->setMNext(ptrTmp);
}

template<typename T>
void CList<T>::Delete(CNode<T> *pDelete)
{
    CNode<T>* pFind (m_Head);
    for (; pFind->getMNext() != pDelete ; pFind = pFind->getMNext())
        if (pFind->getMNext() == nullptr) return;
    pFind->setMNext(pDelete->getMNext());
    pDelete->setMNext(nullptr);

    delete pDelete;
}

template<typename T>
CNode<T> *CList<T>::getHead() const
{
    return this->m_Head;
}

template<typename T>
void CList<T>::setHead(CNode<T> *Head)
{
    m_Head = Head;
}
