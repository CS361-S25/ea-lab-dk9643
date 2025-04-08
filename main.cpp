/*
AUTHOR: DEXTER KONG
notes: This was an inclass lab assignment for digital evolution
*/

#include <iostream>
#include "Empirical/include/emp/math/Random.hpp"

const int NUM_ORGANISMS = 100;
const int NUM_TRIALS = 1000;

/*
class defines an organism that has a fitness level
it can produce offspring with slight variation in fitness
*/
class Organism {
public:
    double behavior;
    Organism(double in_behavior): behavior(in_behavior) {}
    Organism * reproduce(emp::Random random) {
        Organism * child = (Organism *) malloc(sizeof(Organism));
        *child = Organism(behavior);
        child->mutate(random);
        return child;
    }
    void mutate(emp::Random random) {
        behavior += random.GetRandNormal(0.0, 0.02);
    }
};

/*
Main function just tests some of the in class assignments prompts
the code left uncommented is testing evolution with a simple algorithm
*/
int main() {
    //step 4
    emp::Random random(1);

    emp::vector<Organism> population;
    for (int i = 0; i<NUM_ORGANISMS; i++) {
        population.push_back(*new Organism(0.5));
    }
    //step 1
    //  printf("%f\n", population[0].behavior);

    //step 2
    // Organism * child = population[0].reproduce(random);
    // printf("%f\n", population[0].behavior);
    // printf("%f\n", child->behavior);

    //step 3
    for (int i = 0; i<NUM_TRIALS; i++) {
        int best = 0; // setting the best and worst organism to the first one in the list
        int worst = 0;
        // iterating through all of the organisms in order to find any
        // organism that is better than the best we've seen so far or worse than the worst we've seen so far
        for (int i = 1; i<NUM_ORGANISMS; i++) {
            if (population[i].behavior > population[best].behavior) {
                best = i;
            }
            if (population[i].behavior < population[worst].behavior) {
                worst = i;
            }
        }
        // after we have selected the best and the worst organisms by fitness level
        // we use the best organism and create a child using it and add it into a random spot
        // in the organism list overwriting any one random organism
        Organism * child = (population[best].reproduce(random));
        int new_spot = (std::rand() % NUM_ORGANISMS);
        population[new_spot] = *child;
        printf("%f\n", population[best].behavior);
    }
}