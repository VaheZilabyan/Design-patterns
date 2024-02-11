#include <iostream>
#include <string>
#include <memory>

/* Car parts */
struct Wheel
{
    int size;
};

struct Engine
{
    int horsepower;
};

struct Body
{
    std::string shape;
};

/* Final product -- a car */
class Car
{
public:
    Wheel*   wheels[4];
    Engine*  engine;
    Body* body;

    void specifications()
    {
        std::cout << "body: " << body->shape << std::endl;
        std::cout << "engine horsepower: " << engine->horsepower << std::endl;
        std::cout << "tire size: " << wheels[0]->size << "'" << std::endl;
    }
};

/* Builder is responsible for constructing the smaller parts */
class Builder
{
public:
    virtual Wheel* getWheel() = 0;
    virtual Engine* getEngine() = 0;
    virtual Body* getBody() = 0;
};

/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Builder
{
public:
    Wheel* getWheel()
    {
        Wheel* wheel = new Wheel();
        wheel->size = 22;
        return wheel;
    }

    Engine* getEngine()
    {
        Engine* engine = new Engine();
        engine->horsepower = 400;
        return engine;
    }

    Body* getBody()
    {
        Body* body = new Body();
        body->shape = "SUV (Jeep)";
        return body;
    }
};

/* Concrete builder for Nissan family cars */
class NissanBuilder : public Builder
{
public:
    Wheel* getWheel()
    {
        Wheel* wheel = new Wheel();
        wheel->size = 16;
        return wheel;
    }

    Engine* getEngine()
    {
        Engine* engine = new Engine();
        engine->horsepower = 85;
        return engine;
    }

    Body* getBody()
    {
        Body* body = new Body();
        body->shape = "hatchback (Nissan)";
        return body;
    }
};

/* Director is responsible for the whole process */
class Director
{
    Builder* builder;

public:
    void setBuilder(Builder* newBuilder)
    {
        builder = newBuilder;
    }

    std::unique_ptr<Car> getCar()   //Car*
    {
        //Car* car = new Car();
        auto car = std::make_unique<Car>();
        car->body = builder->getBody();
        car->engine = builder->getEngine();
        car->wheels[0] = builder->getWheel();
        car->wheels[1] = builder->getWheel();
        car->wheels[2] = builder->getWheel();
        car->wheels[3] = builder->getWheel();
        return car;
    }
};

int main()
{
    //Car* car; // Final product
    auto car = std::make_unique<Car>();

    /* A director who controls the process */
    Director director;

    /* Concrete builders */
    JeepBuilder jeepBuilder;
    NissanBuilder nissanBuilder;

    /* Build a Jeep */
    std::cout << "Jeep" << std::endl;
    director.setBuilder(&jeepBuilder); // using JeepBuilder instance
    car = director.getCar();
    car->specifications();
    //delete car;

    std::cout << std::endl;

    /* Build a Nissan */
    std::cout << "Nissan" << std::endl;
    director.setBuilder(&nissanBuilder); // using NissanBuilder instance
    car = director.getCar();
    car->specifications();

    return 0;
}
