#include <iostream>
#include "Empirical/include/emp/math/Random.hpp"
class Organism {
public:
    double behavior;
    Organism(double in_behavior) {
        behavior = in_behavior;
    }
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
int main() {
    //step 4
    emp::Random random(1);

    emp::vector<Organism> population;
    for (int i = 0; i<100; i++) {
        population.push_back(*new Organism(0.5));
    }
    //step 1
    //  printf("%f\n", population[0].behavior);

    //step 2
    // Organism * child = population[0].reproduce(random);
    // printf("%f\n", population[0].behavior);
    // printf("%f\n", child->behavior);

    //step 3
    for (int i = 0; i<1000; i++) {
        int best = 0;
        int worst = 0;
        for (int i = 1; i<100; i++) {
            if (population[i].behavior > population[best].behavior) {
                best = i;
            }
            if (population[i].behavior < population[worst].behavior) {
                worst = i;
            }
        }
        Organism * child = (population[best].reproduce(random));
        int new_spot = (std::rand() % 100);
        population[new_spot] = *child;
        printf("%f\n", population[best].behavior);
    }
}