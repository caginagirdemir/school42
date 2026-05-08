#include <iostream>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <list>
#include <set>

template<typename T>
typename T::iterator easyfind(T &cont, int data) {

    //find function

    //first, last:
    /*Input iterators to the initial and final positions in a sequence.
    The range searched is(first, last), which contains all the elements between
    first and last, including the element by first but not the element pointed by last.
    */

    // val:
    /*
        Value to be search in the range
    */

    // return value:
    /*
        An iterator to the first element in the range the compares equal to val.
        If no elements match, the function returns last.
    */
    return std::find(cont.begin(), cont.end(), data);
}

int main() {
    {
        //std::vector is a sequence container that encapsulates dynamic size arrays
        /*


        ## Element access
        at          access specified element with bound checking.
        opeartor[]  access specified element
        front       access the first element
        back        access the last element
        data        direct access to the underlying array

        ## Iterators
        begin       returns an iterator to the beginning
        end         returns an iterator to the end
        rbegin      returns a reverse iterator to there beginning
        rend        returns reverse iterator to the end

        ## Capacity
        empty       checks whether the container is empty
        size        returns the number of elements
        max_size    returns the maximum possible number of elements

        ## Modifiers
        clear       clears the contets
        insert      inserts elements
        erase       erases elements
        push_back   adds an element to the end
        pop_back    removes the last element
        resize      changes the number of elements stored

        */
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(5);
        vec.push_back(2);
        std::cout << *easyfind(vec, 5) << std::endl;
    }
    {
        //std::list is a container that supports constant time insertion
        //and removal of elements from anywhere in the container.

        /*
        ## Element access
        front       access the iterator to the beginning
        end         returns an itera

        ## Iterators
        begin       returns an iterator to the beginning
        end         returns an iterator to the end
        rbegin      returns a reverse iterator to the beginning
        rend        returns a reverse iterator to the end

        ## Capacity
        empty       checks whether the container is empty
        size        returns the number of elements
        max_size    returns the maximum possible number of elements

        ## Modifiers
        clear       clears the contents
        insert      inserts elements
        erase       erases elements
        push_back   adds an element to the end
        pop_back    removes the last element
        push_front  inserts an element to the beginning
        pop_front   removes the first element

        ## Operations
        merge       merges two sorted lists
        splice      moves elements from another list
        remove      removes elements satisfying specific criteria
        unique      removes consecutive duplicate elemenets
        sort        sorts the elements

        */

        std::list<int> l;
        l.push_front(1);
        l.push_front(5);
        l.push_front(2);
        std::cout << *easyfind(l, 5) << std::endl;
    }
    {
        //std::set is an associative container that contains a sorted
        //set of unique objects of type Key.

        /*
        ## Iterators

        begin       returns an iterator to the beginning
        end         returns an iterator to the end
        rbegin      returns a reverse iterator to the beginning
        rend        returns a reverse iterator to the end

        ## Capacity
        empty       checks whether the container is empty
        size        returns the number of elements
        max_size    returns the maximum possible number of elements

        ## Modifiers
        clear       clears the contents
        insert      inserts elements or nodes
        erase       erases elements
        
        ## Lookup
        count       returns the number of elements matching specific key
        find        finds element with specific key
        equal_range returns rangeof elements matching a specific key
        lower_bound returns an iterator to the first element not less than the given key
        upper_bound returns an iterator to the first element greater than the given key

        ## Observers
        key_comp    returns the function that compares keys
        value_comp  returns the function that compares keys in objects of type value_type

        */

        std::set<int> s;
        s.insert(1);
        s.insert(5);
        s.insert(2);
        std::cout << *easyfind(s, 5) << std::endl;
    }
}