#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"

template <typename T>
class CList
{
private:
    CNode<T>* m_Head;
    CNode<T>* m_End;
public:
    CList();
    ~CList();
    void push_front(const T & val);
    void push_back(const T & val);
    void Show() const;
    CNode<T>* Find(const T & val) const;
    void Add(const T & val, CNode<T>*);
    void Delete(CNode<T>*);
    CNode<T> *getHead() const;
    void setHead(CNode<T> *Head);
    CNode<T> *getEnd() const;
    void setEnd(CNode<T> *End);
};

#endif // LIST_HPP

//template<typename T>
//CList<T>::CList(){this->m_Head = nullptr; this->m_End = nullptr;}

template<typename T>
CList<T>::CList():m_Head(new CNode<T>()), m_End(m_Head){}

template<typename T>
CList<T>::~CList(){delete m_Head;}

template<typename T>
void CList<T>::push_front(const T &val)
{
    m_Head->setMNext(new CNode<T>(val, m_Head->getMNext()));
    if(m_End == m_Head){
        m_End = m_Head->getMNext();
    }
}

template<typename T>
void CList<T>::push_back(const T &val){
    CNode<T>* tmp = new CNode<T>(val, nullptr);
    m_End->setMNext(tmp);
    m_End=tmp;
}

template<typename T>
void CList<T>::Show() const
{
    for(CNode<T>* ptr(m_Head->getMNext()); ptr; ptr = ptr->getMNext()){
        std::cout << ptr->getMData() << "; ";
    }
}

template<typename T>
CNode<T> *CList<T>::Find(const T &val) const
{
    CNode<T>* ptr(getHead()->getMNext());
    for ( ; ptr != nullptr && ptr->getMData() != val; ptr = ptr->getMNext());
    return ptr;
}

template<typename T>
void CList<T>::Add(const T &val, CNode<T> *ptr)
{
    CNode<T>* tmp = new CNode<T>(val, ptr->getMNext());
    ptr->setMNext(tmp);
    if (m_End == ptr) m_End = ptr->getMNext();
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

template<typename T>
CNode<T> *CList<T>::getEnd() const
{
    return this->m_End;
}

template<typename T>
void CList<T>::setEnd(CNode<T> *End)
{
    m_End = End;
}
