#include <iostream>
#include <cassert>

const int* highest(int val, const int* start, const int* finish)

{   
     
    if (start == finish)
    {
        return nullptr;

    }
    if (*(finish - 1) == val)
    {
        return finish - 1;
    }
    else if(finish - start == 2 && *start == val) //checks for 1 element list w/ val
    {
        return start;
    }
    else if(finish - start == 1) // checks 
    {
        return nullptr;
    }
    else
    {
        const int* mid = (((finish - start) / 2) + start);
        if (*mid <= val)
        {   
            return highest(val, mid, finish);
        }
        else
        {
            return highest(val, start, mid);
        }
        
    }

    return nullptr;
    
}

int main()
{
    const int DATA_LEN = 9;
    const int data[DATA_LEN] = {1, 1, 1, 4, 4, 5, 6, 7, 10 };

    for (auto search : { -1, 1, 2, 4, 7, 8, 9, 10, 11 }) {
        const auto where = highest(search, data, data + DATA_LEN);
        std::cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            std::cout << "not found!" << std::endl;
        } else {
            std::cout << (where-data) << std::endl;
        }

    }
    return 0;

}
