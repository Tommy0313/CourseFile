// chaseState.cpp
#include "State/ChaseState.hpp"
#include "iostream"
namespace State {
Object::GamePosition ChaseState::Behavior(
    GhostType            type,
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    switch (type) {
    case GhostType::BLINKY:
        return Blinky(pos, playerPos);
    case GhostType::CLYDE:
        return Clyde(pos, playerPos);
    case GhostType::INKY:
        return Inky(pos, playerPos);
    case GhostType::PINKY:
        return Pinky(pos, playerPos);
    default:
        return pos; // 預設保持不動
    }
}

bool ChaseState::IsOutRange(Object::GamePosition pos) {
    return (pos.x < 0 || pos.x >= 12 || pos.y < 0 || pos.y >= 12);
}

Object::GamePosition ChaseState::Blinky(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    // 移動到玩家最近方向
    if (playerPos.x > pos.x) pos.x++;
    else if (playerPos.x < pos.x) pos.x--;

    if (playerPos.y > pos.y) pos.y++;
    else if (playerPos.y < pos.y) pos.y--;

    if (pos.x > 11) {
        pos.x = 11;
    }
    else if (pos.x < 0) {
        pos.x = 0;
    }

    if (pos.y > 11) {
        pos.y = 11;
    }
    else if (pos.y < 0) {
        pos.y = 0;
    }

    return pos;
}

Object::GamePosition ChaseState::Clyde(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    // 判斷玩家是否在範圍內
    if (abs(playerPos.x - pos.x) <= 4 && abs(playerPos.y - pos.y) <= 4) {
        return Blinky(pos, playerPos); // 直接使用 Blinky 的追逐邏輯
    }

    // 隨機移動
    pos.x += rand() % 3 - 1;
    pos.y += rand() % 3 - 1;

    if (pos.x > 11) {
        pos.x = 11;
    }
    else if (pos.x < 0) {
        pos.x = 0;
    }

    if (pos.y > 11) {
        pos.y = 11;
    }
    else if (pos.y < 0) {
        pos.y = 0;
    }

    return pos;
}

Object::GamePosition ChaseState::Inky(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    // 目標點為 玩家座標 + (玩家座標 - 怪物座標)
    Object::GamePosition target = {
        playerPos.x + (playerPos.x - pos.x),
        playerPos.y + (playerPos.y - pos.y)
    };

    if (target.x > pos.x) pos.x++;
    else if (target.x < pos.x) pos.x--;

    if (target.y > pos.y) pos.y++;
    else if (target.y < pos.y) pos.y--;

    if (pos.x > 11) {
        pos.x = 11;
    }
    else if (pos.x < 0) {
        pos.x = 0;
    }

    if (pos.y > 11) {
        pos.y = 11;
    }
    else if (pos.y < 0) {
        pos.y = 0;
    }

    return pos;
}

Object::GamePosition ChaseState::Pinky(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    // 目標點為 玩家 X+4，Y 不變
    Object::GamePosition target = {playerPos.x + 4, playerPos.y};

    if (target.x > pos.x) pos.x++;
    else if (target.x < pos.x) pos.x--;

    if (target.y > pos.y) pos.y++;
    else if (target.y < pos.y) pos.y--;

    if (pos.x > 11) {
        pos.x = 11;
    }
    else if (pos.x < 0) {
        pos.x = 0;
    }

    if (pos.y > 11) {
        pos.y = 11;
    }
    else if (pos.y < 0) {
        pos.y = 0;
    }

    return pos;
}
}  // namespace State