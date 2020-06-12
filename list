#ifndef LIST_H
#define LIST_H
#include "sequence.h"

template <typename T>
class My_List : public Sequence<T>
{
  private:

    struct list
    {
        T data;
        list* p_next;
        list* p_prev;
        int id;
    };
    list* head;
    list* end;

public:

  My_List ()
  {
      this->head=new list;
      this->end=head;
      this->head->data=(T)0;
      this->head->id=0;
      this->head->p_next=nullptr;
      this->head->p_prev=nullptr;
      this->set_length(1);
  }

  My_List (int size)
  {
     list* temp;
     this->end=nullptr;
     this->head=nullptr;
     this->set_length(size);
     for(int i=0;i<size;i++)
     {
         temp=new list;
         temp->id=i;
         temp->data=0;
         temp->p_next=nullptr;
         temp->p_prev=end;
         if(this->head==nullptr)
         {
             this->head=temp;
             this->end=head;
         }
         else
         {
             this->end->p_next=temp;
             this->end=temp;
         }
     }
  }

  My_List (T* items,int size)
  {
     list* temp;
     this->end=nullptr;
     this->head=nullptr;
     this->set_length(size);
     for(int i=0;i<size;i++)
     {
         temp=new list;
         temp->id=i;
         temp->data=items[i];
         temp->p_next=nullptr;
         temp->p_prev=end;
         if(this->head==nullptr)
         {
             this->head=temp;
             this->end=head;
         }
         else
         {
             this->end->p_next=temp;
             this->end=temp;
         }
     }
  }

  My_List (const My_List <T>& other)
  {
      int size=other.get_length();
      list* temp;
      this->end=nullptr;
      this->head=nullptr;
      this->set_length(size);
      for(int i=0;i<size;i++)
      {
          temp=new list;
          temp->id=i;
          temp->data=other.get_index(i);
          temp->p_next=nullptr;
          temp->p_prev=end;
          if(this->head==nullptr)
          {
              this->head=temp;
              this->end=head;
          }
          else
          {
              this->end->p_next=temp;
              this->end=temp;
          }
      }
  }

  ~My_List()
  {
      list* temp=this->end;
      while(temp->p_prev!=nullptr)
      {
          temp=temp->p_prev;
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
      return this->end->data;
  }

  T get_index(int index) override
  {
      if(index<this->get_length())
      {
          list* temp=this->head;
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
          list* temp=this->head;
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
      list* temp=new list;
      temp->data=item;
      temp->id=0;
      temp->p_next=this->head;
      temp->p_prev=nullptr;
      this->head->p_prev=temp;
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
      list* temp=new list;
      temp->data=item;
      temp->id=n_len-1;
      temp->p_next=nullptr;
      temp->p_prev=this->end;
      this->end->p_next=temp;
      this->end=temp;

  }

  void insert_at(T item, int index) override
  {
      if(index<this->get_length())
      {
          int n_len=this->get_length()+1;
          this->set_length(n_len);
          list* temp=new list;
          temp->data=item;
          temp->id=index;
          list* tp=this->head;
          while(tp->id!=index)
              tp=tp->p_next;
          temp->p_prev=tp->p_prev;
          temp->p_next=tp;
          while(tp!=nullptr)
          {
              tp->id+=1;
              tp=tp->p_next;
          }


      }
      else
          cout<<"IndexOutOfRange"<<endl;
  }

  void del_last()
  {
      int n_len=this->get_length();
      if(n_len>1)
      {
          n_len-=1;
          list*temp=this->end->p_prev;
          temp->p_next=nullptr;
          delete this->end;
          this->end=temp;
          this->set_length(n_len);

      }
      else if(n_len==1)
      {
          this->set_length(0);
          delete this->head;
          this->head=nullptr;
          this->end=nullptr;
      }
      else
          cout<<"list empty"<<endl;

  }

  void del_first()
  {
      int n_len=this->get_length();
      if(n_len>1)
      {
          n_len-=1;
          list*temp=this->head->p_next;
          temp->p_prev=nullptr;
          delete this->head;
          this->head=temp;
          this->set_length(n_len);

          for(int i=0;i<n_len;i++)
          {
              temp->id-=1;
              temp=temp->p_next;
          }

      }
      else if(n_len==1)
      {
          this->set_length(0);
          delete this->head;
          this->head=nullptr;
          this->end=nullptr;
      }
      else
          cout<<"list empty"<<endl;

  }

  void remove_by_index(int index) override
  {
      int n_len=this->get_length();
      if(index<n_len)
      {
          if(index==0)
              this->del_first();
          else if(index==n_len-1)
              this->del_last();
          else if(n_len>1)
          {
              n_len-=1;
              list* temp=this->head;
              while(temp->id!=index)
                  temp=temp->p_next;
              temp->p_prev->p_next=temp->p_next;
              temp->p_next->p_prev=temp->p_prev;
              temp=temp->p_next;
              for(int i=index;i<n_len;i++)
              {
                  temp->id=i;
                  temp=temp->p_next;
              }
              this->set_length(n_len);

          }
          else if(n_len==1)
          {
              this->set_length(0);
              delete this->head;
              this->head=nullptr;
              this->end=nullptr;
          }
          else
              cout<<"list empty"<<endl;
      }
      else
          cout<<"IndexOutOfRange\n";

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

  My_List* get_subsequence(int startIndex, int endIndex) override
  {
      if((startIndex>0) & (endIndex>0) & (endIndex>=startIndex) & (startIndex<this->get_length()) & (endIndex<this->get_length()))
      {
          int len=endIndex-startIndex+1;
          T*arr=new T[len];
          for(int i=0;i<len;i++)
          {
              *(arr+i)=this->get_index(i+startIndex);
          }
          My_List* temp= new My_List<T>(arr,len);
          return temp;
      }
      else
          cout<<"IndexOutOfRange"<<endl;


  }

  My_List* concat(Sequence<T> *list) override
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
      My_List* res= new My_List<T>(temp,len);
      return res;

  }

};

#endif // LIST_H
