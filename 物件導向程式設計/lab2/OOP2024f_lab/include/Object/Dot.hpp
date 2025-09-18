#ifndef OOPLAB_DOT_HPP
#define OOPLAB_DOT_HPP

#include "GameObject.hpp"
#include "Interface/GetPointer.hpp"

namespace Object {
class Dot : public Object::GetPointer, public Object::GameObject {
    Object::GamePosition position;
private:
    std::string name = "d";

public:
    Dot(Object::GamePosition pos);

    ~Dot() = default;

    uint8_t GetPoint() override;

    std::string GetName() const override;

    void SetName(std::string name);

    Object::GamePosition GetPosition() const override;
};
}  // namespace Object

#endif  // OOPLAB_DOT_HPP
