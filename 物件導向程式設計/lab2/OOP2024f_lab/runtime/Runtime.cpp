#include <iostream>
#include <memory>
#include <vector>
#include "Interface/MonsterMovable.hpp"
#include "Object/GameObject.hpp"
#include "Util/Map.hpp"
#include "Util/RuntimeFramework.hpp"

namespace Util {

void RuntimeFramework::Initial() {
    allGameObjects.push_back(player);
    allGameObjects.push_back(blinky);
    allGameObjects.push_back(clyde);
    allGameObjects.push_back(inky);
    allGameObjects.push_back(pinky);

    allMonsterMovables.push_back(blinky);
    allMonsterMovables.push_back(clyde);
    allMonsterMovables.push_back(inky);
    allMonsterMovables.push_back(pinky);

    dots.push_back(dot1->GetPosition());
    dots.push_back(dot2->GetPosition());
    dots.push_back(dot3->GetPosition());
    dots.push_back(dot4->GetPosition());
    dots.push_back(cherry1->GetPosition());
    dots.push_back(cherry2->GetPosition());
    dots.push_back(cherry3->GetPosition());

    point_manager = std::make_shared<Util::DotManager>(player,dots);
    for(int i = 4; i < 7; i++) {
        point_manager->SetName("x",i);
    }
}

void RuntimeFramework::Running() {
    state = RuntimeState::RUNNING;
    char input;
    char mode;
    std::cin>> input;
    std::cin>> mode;

    player->Move(input);

    for(int i = 0; i < allMonsterMovables.size(); i++) {
        switch (mode) {
        case 'c':
                allMonsterMovables[i]->SetState(Object::MonsterState::Chase);
                break;
        case 'x':
                allMonsterMovables[i]->SetState(Object::MonsterState::Scatter);
                break;
        }
        allMonsterMovables[i]->Move(player->GetPosition());
    }

    point_manager->IsOverlapping();

    if(point_manager->GetPointListSize()==0) {
        std::cout << "Winner!!!" << std::endl;
        state = RuntimeState::END;
    }
    for(int i = 1; i < 5; i++) {
        if(allGameObjects[0]->GetPosition() == allGameObjects[i]->GetPosition()) {
            std::cout << "GameOver!!!" << std::endl;
            state = RuntimeState::END;
        }
    }
}

void RuntimeFramework::Render() {
    allGameObjects.erase(allGameObjects.begin()+5,allGameObjects.end());
    for(int i = 0; i < point_manager->GetPointList().size(); i++) {
        allGameObjects.push_back(point_manager->GetPointList()[i]);
    }
    Map::Draw(allGameObjects);
}

void RuntimeFramework::End() {
}
};  // namespace Util
