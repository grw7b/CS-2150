//traveling.cpp
//Lab 11: Pre-Lab
//Name: Gizella Wade
//ID: grw7b

/**
 * @author Gizella Wade
 * @details 
 *
 * Title: traveling.cpp
 * Lab 11: In-Lab
 * ID: grw7b
 *
 */


// /Users/gizellawade/Desktop/CS 2150/lab 11/in lab
// clang++ traveling.cpp middleearth.cpp


#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE

    sort(dests.begin()+1,dests.end());

    float dist = 0.0;
    vector<string> minPath;
    float min = 100000000000.0;


    if (dests.size() < 3){

        min = computeDistance(me, dests[0], dests);
        minPath = dests;

    }
    
    while (next_permutation(dests.begin()+1, dests.end())){
        
        dist = computeDistance(me, dests[0], dests);

        if(dist < min){
            min = dist;
            minPath = dests;
        }

    }

    
    


    

    cout << "Minimum path has distance " << min << ": ";
    printRoute(minPath[0], minPath);
    
    return 0;

}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.

/**
 * @brief computeDistance function
 * @param me takes in the middleearth
 * @param start is the starting point
 * @param dests are all the destinations that need to be visited and added to the total distance
 * @return returns total distance of trip
 */

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE

    float totalDist = 0.0;
    string s = start;

    for(auto i: dests){

        totalDist += me.getDistance(s,i);
        s = i;

    }

    totalDist += me.getDistance(start, dests[dests.size()-1]);
    return totalDist;

}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
/**
 * @brief printRoute function
 * @param start is the starting point
 * @param dests are all the destinations that need to be visited and added to the total distance
 * there is no return, only prints each city visited
 */
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE

    for(auto i: dests){
        cout << i << " -> ";
    }

    cout << start;


}