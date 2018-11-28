#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"


template <typename T>
class CList
{
private:
    std::shared_ptr<CNode<T>> m_fictionaHead;
    std::shared_ptr<CNode<T>> m_fictionalTail;

public:
    CList ();
    ~CList (){}
    void push_front (const T & val);
    void Show () const;
    std::shared_ptr<CNode<T>> Find (const T & val);
    void Add (const T & val, std::shared_ptr<CNode<T>>);
    void Delete (std::shared_ptr<CNode<T>>&);
    void push_back (const T & val);
    std::shared_ptr<CNode<T>> Begin () const;
    std::shared_ptr<CNode<T>> End() const;
    void AddAfter (std::shared_ptr<CNode<T>> ptrNext, const T & val);
    void AddBefore (const std::shared_ptr<CNode<T>> &ptrPrev, const T & val);
};

template <typename T>
std::shared_ptr<CNode<T>> CList<T>::Begin () const
{
    return m_fictionaHead;
}

template <typename T>
std::shared_ptr<CNode<T>> CList<T>::End () const
{
    return m_fictionalTail;
}

template <typename T>
void CList<T>::AddAfter (std::shared_ptr<CNode<T>> ptrNext, const T & val)
{
      std::shared_ptr<CNode<T>> Tmp(new CNode<T>(val, ptrNext->GetNextNode()));
      Tmp->SetNextNode(ptrNext->GetNextNode());
      ptrNext->SetNextNode(Tmp);
      Tmp->setPrev(ptrNext->GetPrev());
      ptrNext->setPrev(Tmp);
}

template <typename T>
void CList<T>::AddBefore(const std::shared_ptr<CNode<T>> &ptrPrev, const T &val)
{
    AddAfter(ptrPrev->GetPrev(), val);
}

template <typename T>
void CList<T>::Add (const T & val, std::shared_ptr<CNode<T>> ptr)
{
    std::shared_ptr<CNode<T>> ptrTmp (new CNode<T> (val, ptr -> GetNextNode ()));
    ptr -> SetNextNode (ptrTmp);
    if (ptr == m_fictionalTail) m_fictionalTail = ptr->GetNextNode ();
}

/*Ptr_t AjoutApres (Ptr_t Tete, int NewVal, Ptr_t PtrElem)
{
    if (! PtrElem) PtrElem = Tete;

    PtrElem->SetSuivant
           (new C1Link (NewVal, PtrElem->GetSuivant()));

    return PtrElem->GetSuivant();

} // AjoutApres()
*/

template <typename T>
CList<T>::CList () : m_fictionaHead (new CNode<T>()), m_fictionalTail (new CNode<T>()) {
    m_fictionaHead->SetNextNode(m_fictionalTail);
    m_fictionalTail->setPrev(m_fictionaHead);
}

template <typename T>
std::shared_ptr<CNode<T> > CList<T>::Find(const T & val)
{
    std::shared_ptr<CNode<T>> Ptr (m_fictionaHead->GetNextNode ());
    for (; Ptr != nullptr && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());
    AddAfter(m_fictionaHead, Ptr->GetData());
    Delete(Ptr);

    return Ptr;
}



template <typename T>
void CList<T>::push_front (const T & val)
{
    AddAfter(m_fictionaHead, val);
}

template <typename T>
void CList<T>::Show () const
{
    for (std::shared_ptr<CNode<T>> Ptr (m_fictionaHead -> GetNextNode()); Ptr!=m_fictionalTail; Ptr = Ptr->GetNextNode ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (std::shared_ptr<CNode<T>> & pDelete)
{
    std::shared_ptr<CNode<T>> pFind (m_fictionaHead);
    for ( ; pFind -> GetNextNode () != pDelete ; pFind = pFind -> GetNextNode ());

    pFind -> SetNextNode (pDelete -> GetNextNode ());
    if (pDelete == m_fictionalTail) m_fictionalTail = pFind;
    pDelete -> SetNextNode (nullptr);

    return pDelete;

}

template <typename T>
void CList<T>::push_back (const T & val)
{
    AddBefore(m_fictionalTail, val);
}


#endif // LIST_HPP
