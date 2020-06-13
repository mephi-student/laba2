#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <ctime>

#include"sequence.h"
#include"array.h"
#include"list.h"
#include"d_matrix.h"
#include"linked_linst.h"

using namespace std;

struct Student
{
    string name;
    int age;
    Student(string name, int age)
    {
        this->name=name;
        this->age=age;
    }
    Student()
    {
        this->name="";
        this->age=0;
    }

    void Student_Output()
    {
       cout<<this->name<<this->age;
    }
     friend ostream& operator<<(ostream& os, const Student& st);

};

ostream& operator<<(ostream& os, const Student& st)
{
    os<<st.name<<" "<<st.age<<"\n";
}

template<class>

void arr_rand(int*arr,int size)
{
    for(int i=0;i<size;i++)
        arr[i]=rand();
}

void print_arr(int*arr,int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void print_ob(Sequence<int>* ob)
{
    int size=ob->get_length();

    for(int i=0;i<size;i++)
    {
        cout<<i<<": "<<ob->get_index(i)<<"\n";
    }
    cout<<endl;
}


int main()
{
    setlocale(LC_ALL,"RUS");
    srand((time(0)));

  int size=0;

  Student masha("Maria", 18);
  Student ilyua("Ilya", 28);
  Student kostya("Konstantin", 22);
  Student sasha("Alexandra", 28);
  Student ilyusha("Ilya", 18);
  std::vector<Student> a{masha, ilyua, kostya, sasha, ilyusha};
  auto newEnd = std::remove_if(a.begin(), a.end(), [](Student x)->bool{
          if(x.name=="Ilya")
              return true;
          else
              return false;
});
  a.erase(newEnd, a.end());
  for(Student x : a){
      std::cout<<x<<"\n";
  }

    return 0;
}
