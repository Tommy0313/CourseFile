#include "Blinky.hpp"
#include "Clyde.hpp"
#include "Inky.hpp"
#include "Pacman.hpp"
#include "Pinky.hpp"
#include "Util.hpp"

#include <iostream>
#include <ostream>

int main(){
    struct Point point(0,0);
    struct Point point1(15,15);
    struct Point point2(0,15);
    struct Point point3(7,7);
    struct Point point4(10,10);
    Draw(point,point1,point2,point3,point4);
    Blinky blinky = Blinky("B",point);
    Inky inky = Inky("I",point1);
    Pinky pinky = Pinky("P",point2);
    Clyde clyde = Clyde("C",point3);
    Pacman pacman = Pacman("P",point4);

    std::shared_ptr<Character> P = std::make_shared<Pacman>(pacman);
    std::shared_ptr<Character> B = std::make_shared<Blinky>(blinky);
    std::shared_ptr<Character> I = std::make_shared<Inky>(inky);
    std::shared_ptr<Character> PY = std::make_shared<Pinky>(pinky);
    std::shared_ptr<Character> C = std::make_shared<Clyde>(clyde);



    for (int i = 0;i<5;i++) {
        P->DoBehavior(P->GetPosition());

        C->DoBehavior(P->GetPosition());
        PY->DoBehavior(P->GetPosition());
        I->DoBehavior(P->GetPosition());
        B->DoBehavior(P->GetPosition());

        int P_x = P->GetPosition().x;
        int P_y = P->GetPosition().y;

        if(P_x == C->GetPosition().x && P_y == C->GetPosition().y) {
            std::cout << "You lose!!!" << std::endl;
            std::cout << C->GetPosition().x << " " << C->GetPosition().y << std::endl;
            std::cout << P->GetPosition().x << " " << P->GetPosition().y << std::endl;
            break;
        }
        else if(P_x == PY->GetPosition().x && P_y == PY->GetPosition().y) {
            std::cout << "You lose!!!" << std::endl;
            break;
        }
        else if(P_x == I->GetPosition().x && P_y == I->GetPosition().y) {
            std::cout << "You lose!!!" << std::endl;
            break;
        }
        else if(P_x == B->GetPosition().x && P_y == B->GetPosition().y) {
            std::cout << "You lose!!!" << std::endl;
            break;
        }
        if(i==4) {
            std::cout << "You win!!!" << std::endl;
        }
        Draw(B->GetPosition(),I->GetPosition(),PY->GetPosition(),C->GetPosition(),P->GetPosition());
    }
}