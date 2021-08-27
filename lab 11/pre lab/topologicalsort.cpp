//topologicalsort.cpp
//Lab 11: Pre-Lab
//Name: Gizella Wade
//ID: grw7b

/**
 * @author Gizella Wade
 * @details 
 *
 * Title: topologicalsort.cpp
 * Lab 11: Pre-Lab
 * ID: grw7b
 *
 */

// /Users/gizellawade/Desktop/CS 2150/lab 11/pre lab
// clang++ topologicalsort.cpp

//This program shows how C++-based file I/O works.
//It will open a file, read in the first two strings, and print them to the screen.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


/**
 * @class node
 * @brief creates nodes.
 *
 * This class stores each input (s1) into a node and assigns the class name 
 * to s1, then keeps track of adjacent nodes (s2) and n degree
 *
 *
 * @return is void
 * string $name tracks class name
 * int $ndegree tracks ndegree for each course
 * vector<node*> $adjacents stores each node the given node is adjacent to
 * addAdjacents pushes adjacent nodes into adjacents member
 */

class node{
public:
    string name;
    int ndegree;
    vector<node*> adjacents;
    node();
    void addAdjacents(node* n);
};

/**
 * @brief node class constructor
 * initiliazes node to have ndegree 0
 *
 */

node::node(){
    ndegree = 0;
}

/**
 * @brief keeps track of adjacent nodes
 * @param n is the adjacent node that is 
 * being pushed into the vector tracking
 * all adjacent nodes
 */

void node::addAdjacents(node* n){
    adjacents.push_back(n);
}

/**
 * input - tracking nodes
 * names - tracking node courses
 */

vector<node*> input;
vector<string> names;

/**
 * @brief sorting function sorts vector of input ndoes
 * @implements some alphabetical ordering
 *
 * @param v is the input vector
 * 
 * pushes nodes with ndegree of 0 onto a vector x (variable)
 * pushes the classes stored in the node into a vector result (variable)
 * sorts the result vector alphabetically then stores the sorted vector into another vector (sorted - variable)
 * empties queue and checks the adjacent nodes of the nodes on queue and decrements their ndegree variable
 * repeats steps until initial vector, x, empty 
 * @return returns the completely sorted vector
 *
 */

vector<string> sorting(vector<node*> v){

    vector<string> result;
    vector<string> sorted;

    queue<node*> q;
    vector<node*> x;

    
    node* temp1;
    node* temp2;
  
  
    for (int i = 0; i < v.size(); i++){
        temp1 = v[i];
        if(temp1->ndegree == 0){
            x.push_back(temp1);
            result.push_back(temp1->name);
               
            
        }
    }

    

    while (x.empty()==false){

        sort(result.begin(),result.end());

        while(result.empty()==false){
            for(int i = 0; i < x.size(); i++){
                if (x[i]->name == result.front()){
                    sorted.push_back(x[i]->name);
                    result.erase(result.begin());


                    q.push(x[i]);
                    x.erase(x.begin() + i);
            

                } 
            }  

        }
        
        

        while(q.empty()==false){
            temp1 = q.front();
            q.pop();
            
            for (int i = 0; i < temp1->adjacents.size(); i++){
            
            temp2 = temp1->adjacents[i];
            temp2->ndegree--;

                if(temp2->ndegree==0){

                    x.push_back(temp2);
                    result.push_back(temp2->name);
            
                }
            }

        }
           

    }
    
    return sorted;

}


/**
 * @brief print function sorts vector of input ndoes
 * @implements printing of sorted vector
 *
 * @param stringVec is the sorted vector
 * @param r is the returned string
 * recursively pops value from sorted vector
 * and adds the node's class name to the string
 * until/unless size is 0
 * @return returns a string of sorted classes
 */
string printVector(vector<string> stringVec, string r){
    if (stringVec.size() == 0){
        return r;
    }
    if (stringVec.size() > 0){
        r += stringVec.front();
        r += " ";
        stringVec.erase(stringVec.begin());
        return printVector(stringVec, r);
    }

}



// we want to use parameters
int main(int argc, char** argv) {
    
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    
    
    
    // read in two strings
   
    while (true){

        int index1 = 0;
        int index2 = 0;

        string s1, s2;
        file >> s1; //edge
        file >> s2; //vertex

        if (s1 == "0" && s2 == "0"){
            break;
        }

        if (s1.size() == 0 || s2.size() == 0){
            continue;
        }

        if(find(names.begin(), names.end(), s1) != names.end()){
            auto it = find(names.begin(), names.end(), s1);
            index1 = it - names.begin();

        }
        else{
            node* courses = new node();
            courses->name = s1;

            input.push_back(courses);
            names.push_back(s1);

            index1=input.size()-1;

        }

        
        if(find(names.begin(), names.end(), s2) != names.end()){
            auto it = find(names.begin(), names.end(), s2);
            index2 = it - names.begin();

        }
        else{

            node* courses = new node();
            courses->name = s2;

            input.push_back(courses);
            names.push_back(s2);

            index2=input.size()-1;

        }


        input[index1]->addAdjacents(input[index2]);
        input[index2]->ndegree++;

       

    }

   
    string sortedOutput = "";

    
    if (names.size() > 0){

        vector<string> output = sorting(input);
        sortedOutput = printVector(output, ""); 

       
        cout << sortedOutput;
    
    }
    
    else{

        cout<<sortedOutput; //if input is empty, just print empty string
    
    }

  
    // close the file before exiting
    file.close();
    
    return 0;
}

   



