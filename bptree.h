#ifndef BPTREE_H
#define BPTREE_H

#include "array_util.h"
#include <iostream>
using namespace std;

template <class T>
class BPlusTree
{
public:

    class Iterator
    {
    public:
        friend class BPlusTree;

        Iterator(BPlusTree<T>* ptr=nullptr, int _key_ptr=0):it(ptr), key_ptr(_key_ptr){}

        T operator *()
        {
            return it->data[key_ptr];
        }

        T* operator->()
        {
            return &it->data[key_ptr];
        }

        Iterator operator++(int unused)
        {
            Iterator tmp=*this;
            if(key_ptr<it->data_count-1)
            {
                key_ptr++;
            }
            else
            {
                it=it->next;
                key_ptr=0;
            }
            return tmp;
        }

        Iterator operator++()
        {
            if(key_ptr<it->data_count-1)
            {
                key_ptr++;
            }
            else
            {
                it=it->next;
                key_ptr=0;
            }
            return *this;
        }

        friend bool operator ==(const Iterator& lhs, const Iterator& rhs)
        {
            return lhs.it==rhs.it && lhs.key_ptr==rhs.key_ptr;
        }

        friend bool operator !=(const Iterator& lhs, const Iterator& rhs)
        {
            return lhs.it!=rhs.it || lhs.key_ptr!=rhs.key_ptr;
        }
        friend bool operator==(const Iterator& lhs, nullptr_t)
        {
            return lhs.it == nullptr;
        }
        friend bool operator!=(const Iterator& lhs, nullptr_t)
        {
            return lhs.it != nullptr;
        }



        bool is_null(){return !it;}

    private:
        BPlusTree<T>* it;
        int key_ptr;

    };

    BPlusTree(bool duplicates_allowed = false);
    BPlusTree(const BPlusTree<T>& other);
    ~BPlusTree();
    BPlusTree<T>& operator=(const BPlusTree<T>& other);
    void insert(const T& entry);
    void clear_tree();
    void copy_tree(const BPlusTree<T>& other);
    void remove(const T& entry);
    Iterator search(const T& entry) const;
    Iterator lower_bound(const T& entry) const;
    Iterator upper_bound(const T& entry) const;
    int size() const;
    bool empty() const;
    void print_tree(ostream& outs=cout, int level=0) const;
    void print_as_linked(std::ostream& outs = cout) const;
    void print_as_list(std::ostream& outs = cout) const;
    BPlusTree<T>* get_small()const;
    BPlusTree<T>* get_largest() const;
    Iterator find2(const T& entry)
    {
        Iterator tmp=begin();
        while(tmp!=end())
        {
            if(*tmp==entry)
            {
                return tmp;
            }
            else {
                tmp++;
            }
        }
        return Iterator(NULL);
    }
    friend ostream& operator <<(ostream& outs, const BPlusTree<T>& tree)
    {
        tree.print_tree(outs);
        return outs;
    }
    bool is_valid();
    Iterator begin() const;
    Iterator end() const;

private:

    static const int MAXIMUM = 2;
    static const int MINIMUM = MAXIMUM/2;
    static const int data_cap=MAXIMUM+1;
    static const int child_cap=MAXIMUM+2;
    int data_count=0;
    int child_count=0;
    bool dups_ok;

    T data[MAXIMUM + 1];
    BPlusTree* subset[MAXIMUM + 2];
    BPlusTree<T>* next=nullptr;
    bool is_leaf() const
    {
        return child_count==0;
    }

    T* find_ptr(const T& entry);
    void erase_node();
    void loose_insert(const T& entry);
    void fix_excess(int i);
    void loose_remove(const T& entry, BPlusTree<T>* start=nullptr, int level=0);
    void fix_shortage(int i);
    BPlusTree<T>* get_smallest_node();
    BPlusTree<T>* link_nodes(BPlusTree<T>* previous = nullptr);
    void get_smallest(T& entry);
    void get_biggest(T& entry);
    T remove_biggest();
    void transfer_left(int i);
    void transfer_right(int i);
    void merge_with_next_subset(int i);
    void rotate_left(int i);
    void rotate_right(int i);
    bool contains(const T& entry) const;
    const T& get(const T& entry) const;
    T& get(const T& entry);
    T* find(const T& entry);



};

template <class T>
BPlusTree<T>::BPlusTree(bool duplicates_allowed): dups_ok(duplicates_allowed){}

template <class T>
BPlusTree<T>::BPlusTree(const BPlusTree<T>& other)
{
    //copy and link the nodes
    copy_tree(other);
    link_nodes();
}

template <class T>
BPlusTree<T>::~BPlusTree<T>()
{
    //clear the tree
    clear_tree();
}

template <class T>
BPlusTree<T>& BPlusTree<T>::operator=(const BPlusTree<T>& other)
{
    if(this == &other)
    {
        return *this;
    }
    clear_tree();
    copy_tree(other);
    link_nodes();
    return *this;
}

template <class T>
void BPlusTree<T>::clear_tree()
{
    //clears the whole tree
    for(int i=0; i<child_count; i++)
    {
        if(subset[i]!=nullptr)
        {
            subset[i]->clear_tree();
            delete subset[i];
            subset[i]=nullptr;
        }
    }
    erase_node();
}

template <class T>
void BPlusTree<T>::copy_tree(const BPlusTree<T>& other)
{
    //copy tree
    copy_array(other.data,data,other.data_count,data_count);
    dups_ok=other.dups_ok;
    child_count=other.child_count;
    for(int i=0; i<other.child_count; i++)
    {
        if(other.subset[i]!=nullptr)
        {
            subset[i]=new BPlusTree<T>(other.dups_ok);
            subset[i]->copy_tree(*(other.subset[i]));
        }
    }
}

template <class T>
bool BPlusTree<T>::contains(const T& entry) const
{
    return data[first_ge(data, data_count, entry)] == entry;
}

template <class T>
const T& BPlusTree<T>::get(const T& entry) const
{
    int index=first_ge(data,data_count,entry);
    bool found=index<data_count && data[index]==entry;
    if(found && is_leaf())
    {
        return data[index];
    }
    else if(found && !is_leaf())
    {
        return subset[index+1]->find(entry);
    }
    else if(!found && !is_leaf())
    {
        return subset[index]->find(entry);
    }
    else if(!found && is_leaf())
    {
        cout<<"Not in tree";
    }
}

template <class T>
T& BPlusTree<T>::get(const T& entry)
{
    T* item=find(entry);
    if(item==nullptr)
    {
        insert(entry);
    }
    return *find(entry);
}

template <class T>
T* BPlusTree<T>::find(const T& entry)
{
    int index=first_ge(data,data_count,entry);
    bool found=index<data_count && data[index]==entry;
    //recursivley go down tree until item is found and return
    if(found && is_leaf())
    {
        return &data[index];
    }
    else if(found && !is_leaf())
    {
        return subset[index+1]->find(entry);
    }
    else if(!found && !is_leaf())
    {
        return subset[index]->find(entry);
    }
    else if(!found && is_leaf())
    {
        return nullptr;
    }
    return nullptr;
}

template <typename T>
void BPlusTree<T>::erase_node()
{
    //clear the nodes data
    data_count = 0;
    next = nullptr;
    child_count = 0;
    for (int i = 0; i < child_cap; i++)
    {
        if (i < data_cap)
        {
            data[i] = T();
        }
        subset[i] = nullptr;
    }
}

template <class T>
void BPlusTree<T>::loose_insert(const T& entry)
{
    //check for item
    T* item=find(entry);
    if(item != nullptr)
    {
        if(!dups_ok)
        {
            *item=entry;
        }
        else
        {
            *item+= entry;
        }
        return;
    }
    //item not there insert somewhere
    int index=first_ge(data,data_count,entry);
    if(!is_leaf()&& data[index] != entry)
    {
        subset[index]->loose_insert(entry);
    }
    else
    {
        if(data[index]!=entry)
        {
            insert_item(data,index,data_count,entry);
        }
        return;
    }
    if(subset[index]->data_count>MAXIMUM)
    {
        fix_excess(index);
    }
}

template <class T>
void BPlusTree<T>::fix_excess(int index)
{
    BPlusTree<T>* node=subset[index];
    if(node->data_count <= MAXIMUM)
    {
        return;
    }
    BPlusTree<T>* split_tree=new BPlusTree<T>(dups_ok);
    //split both data and subset
    split(node->data,node->data_count,split_tree->data,split_tree->data_count);
    split(node->subset,node->child_count,split_tree->subset,split_tree->child_count);
    //connect the nodes
    split_tree->next=node->next;
    node->next=split_tree;

    //insert the last item
    T item=detach_item(node->data,node->data_count);
    ordered_insert(data,data_count,item);
    insert_item(subset,index+1,child_count,split_tree);

    if(split_tree->is_leaf())
    {
        ordered_insert(split_tree->data,split_tree->data_count,item);
    }
}

template <class T>
void BPlusTree<T>::insert(const T& entry)
{
    //loosly insert
    loose_insert(entry);
    if(data_count>MAXIMUM)
    {
        BPlusTree<T>* temp=new BPlusTree<T>(dups_ok);
        //create new node
        //copy the data over
        copy_array(data,temp->data,data_count,temp->data_count);
        copy_array(subset,temp->subset,child_count,temp->child_count);
        //erase the data from the node
        erase_node();
        subset[0]=temp;
        child_count=1;
        //clean up excess
        fix_excess(0);
    }
}

template <class T>
BPlusTree<T>* BPlusTree<T>::link_nodes(BPlusTree<T>* previous)
{
    if(is_leaf())
    {
        return nullptr;
    }
    //link the nodes when it is below a leaf
    if(child_count>0 && subset[0]->is_leaf())
    {
        if(previous!=nullptr)
        {
            previous->next=subset[0];
        }
        for(int i=0; i<child_count-1; i++)
        {
            subset[i]->next=subset[i+1];
        }
        return subset[child_count-1];
    }
    //recursivly go down tree to link the nodes
    else
    {
        BPlusTree<T>* last=previous;
        for(int i=0; i<child_count-1; i++)
        {
            BPlusTree<T>* left=subset[i];
            BPlusTree<T>* right=subset[i+1];
            last=left->link_nodes(last);
            BPlusTree<T>* right_side=right->link_nodes(last);
            last=right_side;
        }
        return last;
    }
}

template <class T>
void BPlusTree<T>:: print_tree(ostream& outs,int level) const
{
    //when not leaf recursively go down until you find a leaf
    if(child_count>1)
    {
        //print half of the subset
        for(int i=child_count-1; i>=child_count/2; i--)
        {
            if(subset[i]!=nullptr)
            {
                subset[i]->print_tree(outs,level+1);
            }
            else
            {
                print_array(data,0,level+1,outs);
                outs<<endl;
            }
        }
    }
    //print parent array
    print_array(data,data_count,level,outs);
    outs<<endl;
    if(child_count>1)
    {
        //print the rest of the tree
        for(int i=(child_count/2)-1;i>=0; i--)
        {
            if(subset[i]!=nullptr)
            {
                subset[i]->print_tree(outs,level+1);
            }
            else
            {
                print_array(data,0,level+1,outs);
                outs<<endl;
            }
        }
    }
}



template <class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::search(const T& entry) const
{
    int index=first_ge(data,data_count,entry);
    bool found=index<data_count && data[index]==entry;
    if(found && is_leaf())
    {
        return Iterator((BPlusTree<T>*)this, index);
    }
    else if(found && !is_leaf())
    {
        return subset[index+1]->search(entry);
    }
    else if(!found && !is_leaf())
    {
        return subset[index]->search(entry);
    }
    else if(!found && is_leaf())
    {
        return Iterator(nullptr);
    }
    return Iterator(nullptr);
}

template <class T>
void BPlusTree<T>::transfer_left(int i)
{
    //attach to left from deleted right
    attach_item(subset[i]->data,subset[i]->data_count,delete_item(subset[i + 1]->data, 0, subset[i + 1]->data_count));
     //update right side
    data[i] = subset[i + 1]->data[0];
}

template <class T>
void BPlusTree<T>::transfer_right(int i)
{
    //insert to right side from detached left
    insert_item(subset[i + 1]->data,0,subset[i + 1]->data_count,detach_item(subset[i]->data, subset[i]->data_count));
    //update right side
    data[i] = subset[i + 1]->data[0];
}

template <class T>
bool BPlusTree<T>::is_valid()
{
    if(is_leaf())
    {
        return true;
    }
    if(!is_le(subset[child_count - 1]->data,subset[child_count - 1]->data_count,data[data_count - 1]))
    {
        return false;
    }
    for(int i=0; i<data_count; i++)
    {
        if(!is_gt(subset[i]->data,subset[i]->data_count,data[data_count - 1]))
        {
            return false;
        }
        if(find(data[i])==nullptr)
        {
            return false;
        }
    }
    for(int i=0; i<child_count; i++)
    {
        if(!subset[i]->is_valid())
        {
            return false;
        }
    }
    return true;
}

template <class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::lower_bound(const T& entry) const
{
    int index=first_ge(data,data_count,entry);
    bool found=index<data_count && data[index]==entry;
    //recursivly go thru tree and return lower bound
    if (found && is_leaf())
    {
        return Iterator((BPlusTree<T>*)this, index);
    }
    else if (found && !is_leaf())
    {
       return subset[index + 1]->lower_bound(entry);
    }
    else if (!found && !is_leaf())
    {
       return subset[index]->lower_bound(entry);
    }
    else if (!found && is_leaf())
    {
       if (index < data_count)
       {
           return Iterator((BPlusTree<T>*)this, index);
       }
       else
       {
           return Iterator(next);
       }
    }
    return Iterator(nullptr);
}

template <typename T>
typename BPlusTree<T>::Iterator
BPlusTree<T>::upper_bound(const T& entry) const
{
    int index = first_ge(data, data_count, entry);
    bool found = index < data_count && data[index] == entry;
    //recursivly go thru tree and return upperbound bound
    if (found && is_leaf())
    {
        Iterator lower((BPlusTree<T>*)this, index);
        return ++lower;
    }
    else if (found && !is_leaf())
    {
        return subset[index + 1]->upper_bound(entry);
    }
    else if (!found && !is_leaf())
    {
        return subset[index]->upper_bound(entry);
    }
    else if (!found && is_leaf())
    {
        if (index <= data_count - 1)
        {
            return Iterator((BPlusTree<T>*)this, index);
        }
        else
        {
            return Iterator(next, 0);
        }
    }
    return Iterator(nullptr);
}

template <class T>
void BPlusTree<T>::rotate_left(int i)
{
    if(subset[i]==nullptr)
    {
        subset[i]=new BPlusTree<T>(dups_ok);
        child_count++;
    }
    attach_item(subset[i]->data,subset[i]->data_count,data[i]);
    data[i]=delete_item(subset[i+1]->data,0,subset[i+1]->data_count);
    if(subset[i+1]->child_count>0)
    {
        if(subset[i+1]->subset[0]!=nullptr)
        {
            //rotate the pointers to the left
            attach_item(subset[i]->subset,subset[i]->child_count,
                        delete_item(subset[i+1]->subset,0,subset[i+1]->child_count));
        }
    }
}

template <class T>
void BPlusTree<T>::rotate_right(int i)
{
    if(subset[i+1]==nullptr)
    {
        subset[i+1]=new BPlusTree<T>(dups_ok);
        child_count++;
    }
    insert_item(subset[i+1]->data,0,subset[i+1]->data_count,data[i]);
    data[i]=detach_item(subset[i]->data,subset[i]->data_count);

    if(subset[i]->child_count>0)
    {
        if(subset[i]->subset[subset[i]->child_count-1]!=nullptr)
        {
            //rotate the pointers to the right
            insert_item(subset[i+1]->subset,0,subset[i+1]->child_count,
                    detach_item(subset[i]->subset,subset[i]->child_count));
        }
    }
}

template <class T>
void BPlusTree<T>::merge_with_next_subset(int i)
{
    //merge subset into next subset
    merge(subset[i]->data,subset[i+1]->data, subset[i]->data_count,subset[i+1]->data_count);
    merge(subset[i]->subset,subset[i+1]->subset,subset[i]->child_count,subset[i+1]->child_count);
    //update the next node
    subset[i]->next=subset[i+1]->next;
    subset[i+1]->erase_node();
    //delete information
    delete subset[i+1];
    delete_item(subset,i+1,child_count);
}

template <class T>
void BPlusTree<T>::remove(const T& entry)
{
    //loosly remove
    loose_remove(entry);
    if(data_count<MINIMUM && child_count>0)
    {
        auto shrink=subset[0];
        subset[0]=nullptr;
         //shrink the data
        copy_array(shrink->data,data,shrink->data_count,data_count);
        copy_array(shrink->subset,subset,shrink->child_count, child_count);
        shrink->erase_node();
        delete shrink;
    }
}

template <class T>
void BPlusTree<T>::loose_remove(const T& entry, BPlusTree<T>* start,int level)
{
    int index=first_ge(data,data_count,entry);
    bool found=index<data_count && data[index]==entry;
    //remove the entry
    if(found && is_leaf())
    {
        delete_item(data,index,data_count);
        if(start != nullptr)
        {
            if(data_count>0)
            {
                start->data[level]=data[0];
            }
            else
            {
                if(next!= nullptr)
                {
                    start->data[level]=next->data[0];
                }
            }
        }
    }
     //recursevly go down and fix shortage
    else if(found && !is_leaf())
    {
        subset[index+1]->loose_remove(entry,this,index);
        if(index==data_count)
        {
            index--;
        }
        fix_shortage(index);
    }
    //recursevly go down and fix shortage
    else if(!found && !is_leaf())
    {
        subset[index]->loose_remove(entry,start,level);
        if(index==data_count)
        {
            index--;
        }
        fix_shortage(index);
    }
    //no item
    else if(!found && is_leaf())
    {
        cout<<"Not in tree";
    }
    //fix the tree
    for(int i=0; i<data_count; i++)
    {
        fix_shortage(i);
    }
}

template <class T>
T BPlusTree<T>::remove_biggest()
{
    //if leaf deatch
    if(is_leaf())
    {
        return detach_item(data,data_count);
    }
    T item=subset[child_count-1]->remove_biggest();
    //go down tree to find biggest and detach
    if(subset[child_count-1]->data_count<=0)
    {
        delete detach_item(subset,child_count);
    }
    //fix the shortage
    fix_shortage(data_count-1);
    return item;
}

template <class T>
void BPlusTree<T>::fix_shortage(int i)
{
    BPlusTree<T>* left=subset[i];
    BPlusTree<T>* right=subset[i+1];
    //nothing to do
    if(is_leaf())
    {
        return;
    }
    //nothing to do
    if(left!=nullptr && right!=nullptr)
    {
        if(left->data_count>=MINIMUM && right->data_count>=MINIMUM)
        {
            return;
        }
    }
    //left or right not a leaf
    if(!left->is_leaf() || !right->is_leaf())
    {
        //take from left side
        if(left!=nullptr && left->data_count>MINIMUM && (right==nullptr || right->data_count<=MINIMUM))
        {
            rotate_right(i);
        }
        //take from right
        else if(right != nullptr && right->data_count>MINIMUM && (left==nullptr || left->data_count<=MINIMUM))
        {
            rotate_left(i);
        }
        //nothing to take so move root down and merge
        else
        {
            T item=delete_item(data,i,data_count);
            if(right==nullptr)
            {
                auto temp=new BPlusTree<T>(dups_ok);
                insert_item(subset,i+1,child_count,temp);
                right=subset[i+1];
            }
            ordered_insert(right->data,right->data_count,item);
            merge_with_next_subset(i);
        }
    }
    //node before the leaf
    else
    {
        //take from left
        if(left != nullptr && left->data_count>MINIMUM && (right==nullptr || right->data_count<=MINIMUM))
        {
            transfer_right(i);
        }
         //take from right
        else if(right != nullptr && right->data_count>MINIMUM && (left==nullptr || left->data_count<= MINIMUM))
        {
            transfer_left(i);
        }
        //nothing to take move down and merge
        else
        {
            delete_item(data,i,data_count);
            if(right==nullptr)
            {
                auto temp=new BPlusTree<T>(dups_ok);
                insert_item(subset,i+1,child_count,temp);
                right=subset[i+1];
            }
            merge_with_next_subset(i);
        }
    }

}

template <class T>
BPlusTree<T>* BPlusTree<T>::get_small()const
{
    BPlusTree<T>* smallest=(BPlusTree<T>*)this;
    while(!smallest->is_leaf())
    {
        smallest=smallest->subset[0];
    }
    return smallest;
}

template <class T>
BPlusTree<T>* BPlusTree<T>::get_largest()const
{
    BPlusTree<T>* largest=(BPlusTree<T>*)this;
    while(!largest->is_leaf())
    {
        largest=largest->subset[largest->child_count-1];
    }
    return largest;
}

template<class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::begin() const
{
    auto node=get_small();
    if(node->data_count==0)
    {
        return Iterator(nullptr,0);
    }
    return Iterator(node);
}

template <class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::end() const
{
    auto node=get_largest();
    if(node->data_count==0)
    {
        return Iterator(nullptr);
    }
    return Iterator(node);
}

template <typename T>
void BPlusTree<T>::print_as_list(ostream& outs) const {
    for (auto it = begin(); it != nullptr; it++) {
        if (it != nullptr)
            outs << *it << endl;
    }
}

template <typename T>
void BPlusTree<T>::print_as_linked(std::ostream& outs) const {
    BPlusTree<T>* current_node = get_small();
    while (current_node != nullptr)
    {
        print_array(current_node->data, current_node->data_size, 0, outs);
        outs << " -> ";
        current_node = current_node->next;
    }
    outs << " |||";
}
#endif // BPTREE_H
