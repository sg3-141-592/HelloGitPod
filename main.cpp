#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
using namespace std;

vector<int> countSort(vector<int> a) {
    // Get the max of the sequence
    const int MAX_VAL = *max_element(a.begin(), a.end());
    // Count the frequency of the values
    vector<int> countArray(MAX_VAL+1, 0);
    for(auto val : a) {
        countArray.at(val) += 1;
    }
    // Aggregate the counts across the array
    for(int index = 1; index < countArray.size(); index++)
    {
        countArray.at(index) = countArray.at(index) + countArray.at(index-1);
    }
    //
    vector<int> outputSequence(a.size(), -1);
    for(auto val : a) {
        int targetIndex = countArray.at(val) - 1;
        countArray.at(val) -= 1;
        outputSequence.at(targetIndex) = val;
    }
    return outputSequence;
}

int main()
{
    //
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(1,10000);

    const int TEST_SIZE = 1000000;
    vector<int> a(TEST_SIZE);
    for(int i = 0;i < a.size();i++) {
        a.at(i) = uni(rng);
    }

    //
    auto outputSequence = countSort(a);

    return 0;
}
