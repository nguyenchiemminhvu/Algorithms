/*
https://www.geeksforgeeks.org/the-skyline-problem-using-divide-and-conquer-algorithm/?ref=rp

Given n rectangular buildings in a 2-dimensional city, computes the skyline of these buildings, eliminating hidden lines. The main task is to view buildings from a side and remove all sections that are not visible.
All buildings share common bottom and every building is represented by triplet (left, ht, right)

‘left’: is x coordinated of left side (or wall).
‘right’: is x coordinate of right side
‘ht’: is height of building.
A skyline is a collection of rectangular strips. A rectangular strip is represented as a pair (left, ht) where left is x coordinate of left side of strip and ht is height of strip.

Examples:

Input: Array of buildings
       { (1, 11, 5), (2, 6, 7), (3, 13, 9), (12, 7, 16), (14, 3, 25),
         (19, 18, 22), (23, 13, 29), (24, 4, 28) }
Output: Skyline (an array of rectangular strips)
        A strip has x coordinate of left side and height 
        (1, 11), (3, 13), (9, 0), (12, 7), (16, 3), (19, 18),  
        (22, 3), (25, 0)

Input:  {(1, 11, 5)}
Output: (1, 11), (5, 0)

The idea is similar to Merge Sort, divide the given set of buildings in two subsets.
Recursively construct skyline for two halves and finally merge the two skylines.

How to Merge two Skylines?
==========================

The idea is similar to merge of merge sort, start from first strips of two skylines,
compare x coordinates. Pick the strip with smaller x coordinate and add it to result.
The height of added strip is considered as maximum of current heights from skyline1 and skyline2.

Example to show working of merge:

  Height of new Strip is always obtained by takin maximum of following
     (a) Current height from skyline1, say 'h1'.  
     (b) Current height from skyline2, say 'h2'
  h1 and h2 are initialized as 0. h1 is updated when a strip from
  SkyLine1 is added to result and h2 is updated when a strip from 
  SkyLine2 is added.
 
  Skyline1 = {(1, 11),  (3, 13),  (9, 0),  (12, 7),  (16, 0)}
  Skyline2 = {(14, 3),  (19, 18), (22, 3), (23, 13),  (29, 0)}
  Result = {}
  h1 = 0, h2 = 0
 
  Compare (1, 11) and (14, 3).  Since first strip has smaller left x,
  add it to result and increment index for Skyline1. 
  h1 = 11, New Height  = max(11, 0)   
  Result =   {(1, 11)}

  Compare (3, 13) and (14, 3). Since first strip has smaller left x,
  add it to result and increment index for Skyline1
  h1 = 13, New Height =  max(13, 0)
  Result =  {(1, 11), (3, 13)}   
  
  Similarly (9, 0) and (12, 7) are added.
  h1 = 7, New Height =  max(7, 0) = 7
  Result =   {(1, 11), (3, 13), (9, 0), (12, 7)}

  Compare (16, 0) and (14, 3). Since second strip has smaller left x, 
  it is added to result.
  h2 = 3, New Height =  max(7, 3) = 7
  Result =   {(1, 11), (3, 13), (9, 0), (12, 7), (14, 7)}

  Compare (16, 0) and (19, 18). Since first strip has smaller left x, 
  it is added to result.
  h1 = 0, New Height =  max(0, 3) = 3
  Result =   {(1, 11), (3, 13), (9, 0), (12, 7), (14, 7), (16, 3)}

Since Skyline1 has no more items, all remaining items of Skyline2 
are added 
  Result =   {(1, 11), (3, 13), (9, 0), (12, 7), (14, 7), (16, 3), 
              (19, 18), (22, 3), (23, 13), (29, 0)}

One observation about above output is, the strip (14, 7) is redundant
(There is already an strip of same height). We remove all redundant 
strips. 
  Result =   {(1, 11), (3, 13), (9, 0), (12, 7), (16, 3), (19, 18), 
              (22, 3), (23, 13), (29, 0)}

In below code, redundancy is handled by not appending a strip if the 
previous strip in result has same height.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Building
{
    float _left;
    float _height;
    float _right;
};

class Strip
{
public:

    float _left;
    float _height;

    Strip(float l = 0, float h = 0)
        : _left(l), _height(h)
    {

    }
};

class SkyLine
{
public:

    Strip * _arr;
    int _capacity;
    int _num_of_strip;

    SkyLine(int cap)
        : _capacity(cap)
    {
        _arr = new Strip[cap];
        _num_of_strip = 0;
    }

    ~SkyLine()
    {
        if (_arr)
            delete [] _arr;
    }

    void Append(Strip *st)
    {
        if (_num_of_strip > 0 && _arr[_num_of_strip - 1]._height == st->_height)
            return;
        
        if (_num_of_strip > 0 && _arr[_num_of_strip - 1]._left == st->_left)
        {
            _arr[_num_of_strip - 1]._height = std::max(_arr[_num_of_strip - 1]._height, st->_height);
            return;
        }

        _arr[_num_of_strip] = *st;
        _num_of_strip++;
    }

    SkyLine * Merge(SkyLine * other)
    {
        SkyLine * res = new SkyLine(this->_num_of_strip + other->_num_of_strip);
        
        int height1 = 0, height2 = 0;
        int index1 = 0, index2 = 0;
        while (index1 < this->_num_of_strip && index2 < other->_num_of_strip)
        {
            if (this->_arr[index1]._left <= other->_arr[index2]._left)
            {
                height1 = this->_arr[index1]._height;
                float maxHeight = std::max(height1, height2);
                float curLeft = this->_arr[index1]._left;

                res->Append(new Strip(curLeft, maxHeight));
                index1++;
            }
            else
            {
                height2 = other->_arr[index2]._height;
                float maxHeight = std::max(height1, height2);
                float curLeft = other->_arr[index2]._left;

                res->Append(new Strip(curLeft, maxHeight));
                index2++;
            }
        }

        while (index1 < this->_num_of_strip)
        {
            res->Append(&_arr[index1]);
            index1++;
        }

        while (index2 < other->_num_of_strip)
        {
            res->Append(&other->_arr[index2]);
            index2++;
        }
        
        return res;
    }

    void Print() 
    { 
        for (int i = 0; i < _num_of_strip; i++)
        { 
            std::cout << " (" << _arr[i]._left << ", " << _arr[i]._height << "), "; 
        }
        std::cout << std::endl;
    }
};

SkyLine * SolveSkyLineProblem(Building * arr, int left, int right)
{
    if (left == right)
    {
        SkyLine * res = new SkyLine(2);

        res->Append(new Strip(arr[left]._left, arr[left]._height));
        res->Append(new Strip(arr[left]._right, 0));

        return res;
    }

    int mid = (left + right) / 2;

    SkyLine * skyLeft = SolveSkyLineProblem(arr, left, mid);
    SkyLine * skyRight = SolveSkyLineProblem(arr, mid + 1, right);
    SkyLine * res = skyLeft->Merge(skyRight);

    if (skyLeft)
        delete skyLeft;
    if (skyRight)
        delete skyRight;
    
    return res;
}

int main()
{
    Building arr[] =
    {
        {1,4,5},
        {2,3,7},
        {3,6,6},
        {5.5,5,8.5},
        {10,2,12},
        {11,3,13}
    };
    int n = sizeof(arr) / sizeof(arr[0]); 

    SkyLine * res = SolveSkyLineProblem(arr, 0, n - 1);
    if (res)
    {
        res->Print();
        delete res;
    }

    return 0;
}