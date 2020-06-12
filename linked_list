#ifndef LINKED_LINST_H
#define LINKED_LINST_H
#include "sequence.h"

template <typename T>
class My_Linked_List : public Sequence<T>
{
  private:

    struct l_list
    {
        T data;
        l_list* p_next;
        int id;
    };

    l_list* head;

public:

    My_Linked_List ()
    {
        this->head=new l_list;
        this->head->data=(T)0;
        this->head->id=0;
        this->head->p_next=nullptr;
        this->set_length(1);
    }

    My_Linked_List(int size)
    {
        l_list* temp_n=nullptr;
        l_list* temp_p=nullptr;
        this->set_length(size);
        this->head=new l_list;
        this->head->id=0;
        this->head->data=0;
        this->head->p_next=nullptr;
        temp_p=this->head;
        for(int i=1;i<size;i++)
        {
            temp_n=new l_list;
            temp_n->data=0;
            temp_n->id=i;
            temp_n->p_next=nullptr;
            temp_p->p_next=temp_n;
            temp_p=temp_n;
            temp_n=nullptr;
        }
    }

    My_Linked_List (T* items,int size)
    {
        l_list* temp_n=nullptr;
        l_list* temp_p=nullptr;
        this->set_length(size);
        this->head=new l_list;
        this->head->id=0;
        this->head->data=items[0];
        this->head->p_next=nullptr;
        temp_p=this->head;
        for(int i=1;i<size;i++)
        {
            temp_n=new l_list;
            temp_n->data=items[i];
            temp_n->id=i;
            temp_n->p_next=nullptr;
            temp_p->p_next=temp_n;
            temp_p=temp_n;
            temp_n=nullptr;
        }
    }

    My_Linked_List (const My_Linked_List <T>& other)
    {
        int size=other.get_length();
        l_list* temp_n=nullptr;
        l_list* temp_p=nullptr;
        this->set_length(size);
        this->head=new l_list;
        this->head->id=0;
        this->head->data=other.get_index(0);
        this->head->p_next=nullptr;
        temp_p=this->head;
        for(int i=1;i<size;i++)
        {
            temp_n=new l_list;
            temp_n->data=other.get_index(i);
            temp_n->id=i;
            temp_n->p_next=nullptr;
            temp_p->p_next=temp_n;
            temp_p=temp_n;
            temp_n=nullptr;
        }
    }

    ~My_Linked_List()
    {
        l_list* temp=this->head;
        while(temp->p_next!=nullptr)
        {
            temp=temp->p_next;
            delete temp->p_next;
        }
        delete this->head;
    }

    T* return_head()
    {
        return head;
    }

    T get_first() override
    {
        return this->head->data;
    }

    T get_last() override
    {
        l_list* temp;
        temp=this->head;
        while(temp->p_next!=nullptr)
        {
            temp=temp->p_next;
        }
        return temp->data;
    }

    T get_index(int index) override
    {
        if(index<this->get_length())
        {
            l_list* temp=this->head;
            while (temp->id!=index)
            {
                temp=temp->p_next;
            }
            return temp->data;
        }
        else
            cout<<"IndexOutOfRange"<<endl;
    }

    void set_index(int index, T dat) override
    {
        if(index<this->get_length())
        {
            l_list* temp=this->head;
            while (temp->id!=index)
            {
                temp=temp->p_next;
            }
            temp->data=dat;
        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }

    void append (T item) override
    {
        int n_len=this->get_length()+1;
        this->set_length(n_len);
        l_list* temp=new l_list;
        temp->data=item;
        temp->id=0;
        temp->p_next=this->head;
        this->head=temp;
        temp=temp->p_next;
        while(temp!=nullptr)
        {
            temp->id+=1;
            temp=temp->p_next;
        }
    }

    void prepend(T item) override
    {
        int n_len=this->get_length()+1;
        this->set_length(n_len);
        l_list* temp=new l_list;
        temp->data=item;
        temp->id=n_len-1;
        temp->p_next=nullptr;
        l_list* temp_l=this->head;
        while (temp_l->p_next!=nullptr)
        {
            temp_l=temp_l->p_next;
        }
        temp_l->p_next=temp;
    }

    void insert_at(T item, int index) override
    {
        if(index<this->get_length())
        {
            int n_len=this->get_length()+1;
            this->set_length(n_len);
            l_list* temp=new l_list;
            temp->data=item;
            temp->id=index;
            l_list* tp=this->head;
            while(tp->id!=index-1)
                tp=tp->p_next;
            l_list* tmp=tp->p_next;
            tp->p_next=temp;
            temp->p_next=tmp;
            while(tmp!=nullptr)
            {
                tmp->id+=1;
                tmp=tmp->p_next;
            }
        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }

    void remove_by_index(int index) override
    {
        int n_len=this->get_length()-1;
        this->set_length(n_len);
        l_list* tp=this->head;
        while(tp->id!=index-1)
            tp=tp->p_next;
        tp->p_next=tp->p_next->p_next;
        tp=tp->p_next;
        for(int i=index;i<n_len;i++)
        {
            tp->id=i;
            tp=tp->p_next;
        }
    }

    void remove_by_function(function<bool(T)> func) override
    {
        int len=this->get_length();

        for(int i=0;i<len;i++)
        {
            if(func(this->get_index(i)))
            {
                this->remove_by_index(i);
                --i;
                --len;
            }
        }

    }

    My_Linked_List* get_subsequence(int startIndex, int endIndex) override
    {
        if((startIndex>0) & (endIndex>0) & (endIndex>=startIndex) & (startIndex<this->get_length()) & (endIndex<this->get_length()))
        {
            int len=endIndex-startIndex+1;
            T*arr=new T[len];
            for(int i=0;i<len;i++)
            {
                *(arr+i)=this->get_index(i+startIndex);
            }
            My_Linked_List* temp= new My_Linked_List<T>(arr,len);
            return temp;
        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }

    My_Linked_List* concat(Sequence<T> *list) override
    {
        int n_len=this->get_length()+list->get_length();
        int len=this->get_length();
        T* temp= new T[n_len];
        for(int i=0;i<this->get_length();i++)
        {
            *(temp+i)=this->get_index(i);
        }
        for(int i=0;i<list->get_length();i++)
        {
            *(temp+len+i)=list->get_index(i);
        }
        My_Linked_List* res= new My_Linked_List<T>(temp,len);
        return res;
    }

    void List_Output()
    {
        l_list* temp=this->head;
        while(temp->p_next!=nullptr)
        {
            cout<<temp->data;
            temp=temp->p_next;
        }
    }

};

#endif // LINKED_LINST_H
