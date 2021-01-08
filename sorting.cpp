#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void bubbleSort(vector<int> &unsorted_list)
{
   std::vector<int>::iterator itr;
   std::vector<int>::iterator itr_next;

   bool swapped =true;
   while(swapped)
   {
       swapped =false;
       for(itr = unsorted_list.begin() ; itr != unsorted_list.end(); itr++)
       {
          if(next(itr)!= unsorted_list.end())
          {
              itr_next = std::next(itr,1);

          }
          if(*itr > *itr_next)
          {

             std::swap(*itr,*itr_next);
             swapped =true;
          }
       }
   }
}

void selectionSort(vector<int> &unsorted_list)
{

   std::vector<int>::iterator nextitr;
   std::vector<int>::iterator smallestitr = unsorted_list.begin();

   for(auto itr = unsorted_list.begin(); itr != unsorted_list.end(); itr++)
   {
       int smallest = *itr;
       bool need_swap  =false;

       for( auto inneritr = itr; inneritr != unsorted_list.end(); inneritr++)
       {
          if(next(inneritr) != unsorted_list.end())
          {
             nextitr = next(inneritr);
          }
          if(*inneritr > *nextitr && smallest > *nextitr)
          {
             smallest = *nextitr;
             smallestitr = nextitr;
             need_swap =true;
          }

       }
       if(need_swap)
       {
           swap(*itr,*smallestitr);
       }

   }

}

void insertionSort(vector<int> unsorted_list)
{
    std::vector<int> sorted_list;
    std::vector<int>::iterator nextitr;
    int index;
    for(auto uitr : unsorted_list)
    {
        if(sorted_list.empty())
        {
           sorted_list.push_back(uitr);


        }
        else
        {
            index =0;
            bool found =false;
            for(auto sitr: sorted_list)
            {
                if(uitr > sitr)
                {
                   found =true;
                   index++;

                }
                else
                {
                    if(found ==false)
                    {
                        sorted_list.insert(sorted_list.begin(),uitr);
                    }
                    break;
                }

            }

            if(found){
                    sorted_list.insert(sorted_list.begin()+index, uitr);
            }


        }

    }

    for(auto newitr : sorted_list)
    {
        cout << newitr <<endl;
    }
}

vector<int> mergestep(vector<int> left, vector<int> right)
{
    vector<int> sorted_list;
    left.push_back(1250);  //any large number
    right.push_back(1260); //any large number

    auto leftitr = left.begin();
    auto rightitr = right.begin();


    for(leftitr,rightitr; leftitr !=left.end() &&  rightitr !=right.end();)
    {
        if(*leftitr < *rightitr)
        {
            sorted_list.push_back(*leftitr);
            leftitr++;
        }
        else
        {
            sorted_list.push_back(*rightitr);
            rightitr++;
        }
    }
    sorted_list.pop_back();
    return sorted_list;
}

std::vector<int> mergeSort(vector<int> &unsorted_list)
{


    if(unsorted_list.size() ==  1)
    {
        return unsorted_list;

    }
    std::vector<int> leftList;
    std::vector<int> rightList;
    std::vector<int> sorted_list;

    int mid = unsorted_list.size()/2;
    int i=0;
    for(auto itr = unsorted_list.begin(); itr !=unsorted_list.end(); itr++)
    {
        if(i < mid)
        {
            leftList.push_back(*itr);
        }
        else
        {
            rightList.push_back(*itr);

        }
        i++;
    }

    return mergestep(mergeSort(leftList),mergeSort(rightList));

}


int main()
{

    vector<int> unsorted_list {15,5,4,3,11,16,19,20,-1};
    vector<int> sorted_list;

    sorted_list = mergeSort(unsorted_list);

    for(auto itr :sorted_list)
    {
        cout << itr << endl;
    }
    return 0;
}
