#include <vector> 
#include <iostream>
#include <chrono>

void swapVectElements(std::vector<int> &vect, int firstIndex, int secondIndex)
{
    int temp = vect[firstIndex];
    vect[firstIndex] = vect[secondIndex];
    vect[secondIndex] = temp; 
}

void quickSortIndexMapped(std::vector<int> &vector, std::vector<int> indexMap, int left, int right)
{
    int i, j, mid, piv;
    i = left;
    j = right;

    mid = left + (right - left) / 2;
    piv = vector[indexMap[mid]];

    while(i < right || j > left)
    {
        while (vector[indexMap[i]] < piv) {i++;}
        while (vector[indexMap[j]] > piv) {j--;}
        if (i <= j)
        {
            swapVectElements(vector,indexMap[i],indexMap[j]);
            i++;
            j--;
        } else {
            if (i < right) {quickSortIndexMapped(vector,indexMap,i,right);}
            if (j > left) {quickSortIndexMapped(vector,indexMap,left,j);}
            return;
        }

    }
}

/**
 * @brief Quicksort a given vector for ONLY odd array elements.
 * 
 * @param target Input vector to be sorted
 * @return std::vector<int> Sorted vector
 */
std::vector<int> sortArrayExcludingEvens(std::vector<int> target)
{
    std::vector<int> oddIndexes;
    std::vector<int> evenIndexes;

    for(int i = 0; i < target.size(); i++)
    {
        if(/*target[i]*/ i % 2 == 1) 
        {
            oddIndexes.push_back(i);
        } else {
            evenIndexes.push_back(i);
        }
    }

    quickSortIndexMapped(target,oddIndexes,0,(oddIndexes.size()-1));
    //quickSortIndexMapped(target,evenIndexes,0,(evenIndexes.size()-1));

    return target;
}

int main()
{
    
    int num = 0;
    std::cin >> num; 

    std::vector<int> testInput{10,9,8,7,6,5,4,3,2,1};
    std::vector<int> testInput2{10,9,8,7,6,5,4,3,2,1};

    for(int i = 0; i < num; i++)
    {
        testInput.insert(std::end(testInput), std::begin(testInput2), std::end(testInput2));

    }

    for(int i = 0 ; i < 10 ; i++)
    {
        testInput.insert(std::end(testInput), std::begin(testInput2), std::end(testInput2));

        auto t1 = std::chrono::high_resolution_clock::now();
        
        std::vector<int> output = sortArrayExcludingEvens(testInput);

        auto t2 = std::chrono::high_resolution_clock::now();
        auto time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1);
        std::cout << " Elements : " << testInput.size() << " Time : " << time_ms.count() << " ms." << std::endl;

    }
    
    std::vector<int> output = sortArrayExcludingEvens(testInput);

    for(int i = 0 ; i < testInput.size(); i++)
    {
        std::cout << output[i] << " ";
    }
}