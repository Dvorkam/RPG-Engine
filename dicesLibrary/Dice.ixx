module;
#include <random>

export module dicesLibrary.Dice;

export class Dice{
    size_t sides;
    public:
    Dice(size_t sides);
    ~Dice();

    size_t get_sides();
    size_t roll_dice();

};
Dice::Dice(size_t sides):sides(sides){};
Dice::~Dice() = default;

size_t Dice::get_sides(){return sides;}
size_t Dice::roll_dice(){return sides;}