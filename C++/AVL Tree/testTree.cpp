#include "BinarySearchTree.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

template <typename KeyType, typename ElementType>
void insertAllWords(BinarySearchTree<KeyType, ElementType>& T, int partition, const char* fileName)
{
    Timer t;
    double eTime;
    t.start();

    ifstream in(fileName);
    string l;
    int limit = 4539 * partition;
    for (int j = 0; j < limit; ++j)
    {
        in >> l;
        T.insert(l, 1);
    }

    t.elapsedUserTime(eTime);
    cout << "File: " << fileName << ". Partition: " << partition << "/10, time of insertAllWords: " << eTime << endl;
}

template <typename KeyType, typename ElementType>
void findAllWords(BinarySearchTree<KeyType, ElementType>& T, int partition, const char* fileName)
{
    Timer t;
    double eTime;
    t.start();

    ifstream in(fileName);
    string l;
    int limit = 4539 * partition;
    for (int j = 0; j < limit; ++j)
    {
        in >> l;
        T.find(l);
    }

    t.elapsedUserTime(eTime);
    cout << "File: " << fileName << ". Partition: " << partition << "/10, time of findAllWords: " << eTime << endl;
}

template <typename KeyType, typename ElementType>
void removeAllWords(BinarySearchTree<KeyType, ElementType>& T, int partition, const char* fileName)
{
    Timer t;
    double eTime;
    t.start();

    ifstream in(fileName);
    string l;
    int limit = 4539 * partition;
    for (int j = 0; j < limit; ++j)
    {
        in >> l;
        T.remove(l);
    }

    t.elapsedUserTime(eTime);
    cout << "File: " << fileName << ". Partition: " << partition << "/10, time of removeAllWords: " << eTime << endl;
}

void measureAll(const char* fileName)
{
    for (int i = 1; i <= 10; ++i)
    {
        BinarySearchTree<string, int> T;
        insertAllWords(T, i, fileName);
        findAllWords(T, i, fileName);
        removeAllWords(T, i, fileName);
        
        cout << "\n---------------------------------------------------\n" << endl;
    }
}

int main()
{
    measureAll("Random.txt");
    measureAll("Words.txt");
    
    BinarySearchTree<int,  int> bst;
    ifstream in("Random.txt");
    string l;

    while (in >> l)
        bst.insert(l.size(), 1);
    
    cout << bst;
    return 0;
}


