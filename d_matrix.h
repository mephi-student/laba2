#ifndef D_MATRIX_H
#define D_MATRIX_H
#include <iostream>
#include <string>
#include "sequence.h"
#include "array.h"
#include "list.h"
using namespace std;

template <typename T>
class Matrix
{
private:

    Sequence<Sequence<T>*>* ptr;
    int type;

public:

    Matrix (int size, int type=3)
    {
        this->type=type;
        if(type==0)
        {
            My_List<Sequence<T>*>* temp= new My_List<Sequence<T>*>(size);
            for(int i=0;i<size;i++)
            {
                My_List<T>* tp= new My_List<T>(i+1);
                temp->set_index(i,tp);
            }
            this->ptr= temp;
        }
        else if(type==1)
        {
            My_List<Sequence<T>*>* temp= new My_List<Sequence<T>*>(size);
            for(int i=0;i<size;i++)
            {
                D_Array<T>* tp= new D_Array<T>(i+1);
                temp->set_index(i,tp);
            }
            this->ptr=temp;
        }
        else if(type==2)
        {
            D_Array<Sequence<T>*>* temp= new D_Array<Sequence<T>*>(size);
            for(int i=0;i<size;i++)
            {
                My_List<T>* tp= new My_List<T>(i+1);
                temp->set_index(i,tp);
            }
            this->ptr= temp;
        }
        else
        {
            D_Array<Sequence<T>*>* temp= new D_Array<Sequence<T>*>(size);
            for(int i=0;i<size;i++)
            {
                D_Array<T>* tp= new D_Array<T>(i+1);
                temp->set_index(i,tp);
            }
            this->ptr= temp;
        }
    }

    Matrix(T* items,int size,int type=3) : Matrix(size,type)
    {
       int num=0;

        for(int col=0;col<size;col++)
        {

            for(int row=0;row<=col;row++)
            {
                this->set_index(col,row,*(items+num));
                num+=1;
            }
        }
    }

    Matrix(Sequence<Sequence<T>*>* str) //1-arr, 2-list
    {
        this->ptr= *str;


    }


    ~Matrix()
    {
       delete[] this->ptr;
    }


    void set_index(int col,int row,T data)
    {
        Sequence<T>* temp=this->ptr->get_index(col);
        temp->set_index(row,data);
    }

    T get_index(int col,int row)
    {
        T res;
        Sequence<T>* temp=this->ptr->get_index(col);
        res = temp->get_index(row);
        return res;
    }

    Matrix<T>* Matrix_Sum(Matrix<T>& other)
    {
        int t_size=this->ptr->get_length();
        int o_size=other.ptr->get_length();
        if(t_size==o_size)
        {
            Matrix* res=new Matrix<T>(t_size,this->type);
            T temp;
            for(int col=0;col<t_size;col++)
            {
                for(int row=0;row<=col;row++)
                {
                    temp=this->get_index(col,row)+other.get_index(col,row);
                    res->set_index(col,row,temp);
                }
            }
            return res;

        }
        else
        {
            cout<<"Matrices of different sizes";
            return nullptr;
        }
    }

    Matrix<T>* Matrix_Multi(T scalar)
    {
        int t_size=this->ptr->get_length();
        Matrix* res=new Matrix<T>(t_size,this->type);
        T temp;
        for(int col=0;col<t_size;col++)
        {
            for(int row=0;row<=col;row++)
            {
                temp=this->get_index(col,row)*scalar;
                res->set_index(col,row,temp);
            }
        }
        return res;
    }

    T Matrix_Norm ()
    {
        T sum=0;
        int t_size=this->ptr->get_length();
        int count=((t_size*(t_size-1))/2+t_size);
        for(int col=0;col<t_size;col++)
        {
            for(int row=0;row<=col;row++)
            {
                int temp=this->get_index(col,row);
                sum+=temp*temp;
            }
        }
        return sqrt(sum/count);
    }
    void Matrix_Output()
    {
        int t_size=this->ptr->get_length();
        for(int col=0;col<t_size;col++)
        {
            for(int row=0;row<=col;row++)
            {
                cout<<this->get_index(col,row)<<" ";
            }
            cout<<"\n";
        }
    }


};

#endif // D_MATRIX_H
