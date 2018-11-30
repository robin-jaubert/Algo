#ifndef CRDTREE_H
#define CRDTREE_H
#include <memory>
#include "cnode.hpp"

template <typename T>
class CRDTree{
private:
    std::shared_ptr <CNode<T>> treeRoot;
    std::shared_ptr <CNode<T>> m_fictionalTail;
public:
    CRDTree(const CNode<T> &root);
    ~CRDTree(){}

    std::shared_ptr<CNode<T> > getTreeRoot() const;
    void setTreeRoot(const std::shared_ptr<CNode<T> > &value);
    std::shared_ptr<CNode<T> > getFictionalTail() const;
    void setFictionalTail(const std::shared_ptr<CNode<T> > &fictionalTail);

    void Show() const;
};

#endif // CRDTREE_H

CRDTree::CRDTree(const CNode<T> &root): treeRoot(new CNode<T>(root)){}

template<typename T>
std::shared_ptr<CNode<T> > CRDTree::getTreeRoot() const
{
    return treeRoot;
}

void CRDTree::setTreeRoot(const std::shared_ptr<CNode<T> > &value)
{
    treeRoot = value;
}

std::shared_ptr<CNode<T> > CRDTree::getFictionalTail() const
{
return m_fictionalTail;
}

void CRDTree::setFictionalTail(const std::shared_ptr<CNode<T> > &fictionalTail)
{
    m_fictionalTail = fictionalTail;
}

template<typename T>
void CRDTree::Show() const
{

}


