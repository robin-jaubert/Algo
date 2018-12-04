#ifndef CRDTREE_H
#define CRDTREE_H
#include <memory>
#include <stdlib.h>
#include "cnode.hpp"

template <typename T>
class CRDTree{
private:
    std::shared_ptr <CNode<T>> treeRoot;
  //  void localShow(const std::shared_ptr<CNode<T> > &root);
  //  void localAdd(const T &val, const std::shared_ptr<CNode<T> > &ptr);
public:
    CRDTree(const CNode<T> &root);
    ~CRDTree(){}

    std::shared_ptr<CNode<T> > getTreeRoot() const;
    void setTreeRoot(const std::shared_ptr<CNode<T> > &value);
    std::shared_ptr<CNode<T> > getFictionalTail() const;
    void setFictionalTail(const std::shared_ptr<CNode<T> > &fictionalTail);

    void Show() const;
    void Add(const T &val);
    bool Find(const T &val) const;

};


template<typename T>
CRDTree<T>::CRDTree(const CNode<T> &root): treeRoot(new CNode<T>(root)){}

template<typename T>
std::shared_ptr<CNode<T> > CRDTree<T>::getTreeRoot() const
{
    return treeRoot;
}

template<typename T>
void CRDTree<T>::setTreeRoot(const std::shared_ptr<CNode<T> > &value)
{
    treeRoot = value;
}



template<typename T>
void localShow(const std::shared_ptr <CNode<T>> &root)
{
    if (root == nullptr) return;

    localShow(root->GetLC());
    std::cout << root->GetData() << std::endl;
    localShow(root->GetRC());
}

template<typename T>
void CRDTree<T>::Show() const
{

    localShow(treeRoot->GetLC());
    std::cout << treeRoot->GetData() << std::endl;
    localShow(treeRoot->GetRC());

}

template <typename T>
void localAdd(const T &val, const std::shared_ptr <CNode<T>> &ptr){
    if (ptr->GetData() > val)
    {
        if(ptr->GetLC() == nullptr)
        {
            std::shared_ptr <CNode<T>> add (new CNode<T>(val));
            ptr->SetLC(add);
            return;
        }
        else localAdd(val, ptr->GetLC());
    }
    else
    {
        if(ptr->GetRC()==nullptr)
        {
            std::shared_ptr <CNode<T>> add (new CNode<T>(val));
            ptr->setRC(add);
            return;
        }
        else localAdd(val, ptr->GetRC());
    }
}

template <typename T>
void CRDTree<T>::Add (const T &val)
{
    localAdd(val, treeRoot);
}



#endif // CRDTREE_H
