#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(std::vector<int> sorted_list, int item)
{
      if(sorted_list.empty())
      {
          return false;
      }

    auto litr = sorted_list.begin();
    auto ritr = sorted_list.end()-1;

    while(litr <= ritr)
    {

        int leftindex = std::distance(sorted_list.begin(), litr);
        int rightindex = std::distance(sorted_list.begin(), ritr);

        int mid = (leftindex + ((rightindex-leftindex)/2));

        if(sorted_list.at(mid) == item)
        {
            return true;
        }

        if(item < sorted_list.at(mid))
        {
            ritr = sorted_list.begin() + mid-1;
        }
        else
        {
            litr = sorted_list.begin()+ mid+1;

        }
    }

    return false;
}


int main()
{

    std::vector<int> sorted_list{};

    int item  = -10;


    bool result = binarySearch(sorted_list, item);
    if(result)
    {
        cout << "item " <<item << "is found" <<endl;
    }
    else
    {
        cout << "not found" << endl;
    }

   return 0;
}
