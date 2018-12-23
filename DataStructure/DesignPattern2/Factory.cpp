#include "stdafx.h"
#include"Design.h"
enum class ShapeID {ECircle,ESquare,ERectangle};
enum class ColorID {ERed,EBlue,EGreen};
enum class Family{EColor,EShape};
class Color{public :    virtual void draw() = 0;};
class Red:public Color{public:    void draw(){FUN}};
class Blue:public Color{public:    void draw(){FUN}};
class Green:public Color{public:    void draw(){FUN}};
class Shape {public:    virtual void draw() = 0;};
class Circle : public Shape {public:    void draw() { FUN}};
class Square :public Shape {public:    void draw(){FUN}};
class Rectangle :public Shape {public:    void draw(){FUN}};
class AbstractFactory
{
public:
    virtual Color * getColor(ColorID id) = 0;
    virtual Shape * getShape(ShapeID id) = 0;
};
class FactoryShape :public AbstractFactory
{
public:   
    Shape* getShape(ShapeID id)
    {
        Shape *p = NULL;
        switch (id)
        {
        case ShapeID::ECircle: p = new Circle; break;
        case ShapeID::ESquare: p = new Square; break;
        case ShapeID::ERectangle: p = new Rectangle; break;
        }
        return p;
    }
    Color * getColor(ColorID id) { return NULL; }
};
class FactoryColor:public AbstractFactory
{
public:
    Color * getColor(ColorID id)
    {
        Color *p = NULL;
        switch (id)
        {
        case ColorID::EBlue: p = new Blue; break;
        case ColorID::ERed: p = new Red; break;
        case ColorID::EGreen: p = new Green; break;
        }
        return p;
    }
    Shape* getShape(ShapeID id) { return NULL; }
};
class FactoryProducer
{
public:
    AbstractFactory* getFactory(Family f)
    {
        AbstractFactory *p = NULL;
        switch (f)
        {
        case Family::EColor: p = new FactoryColor; break;
        case Family::EShape: p = new FactoryShape; break;
        }
        return p;
    }
};
void DemoFactory()
{
    FactoryShape *fp = new FactoryShape;
    Shape* s = fp->getShape(ShapeID::ECircle);
    s->draw();
    s = fp->getShape(ShapeID::ERectangle);
    s->draw();
}
void DemoAbstractFactory()
{
    FactoryProducer* fp = new FactoryProducer;
    AbstractFactory * abs = fp->getFactory(Family::EShape);
    Shape * c = abs->getShape(ShapeID::ECircle);
    c->draw();
    AbstractFactory* abcolor = fp->getFactory(Family::EColor);
    Color* r = abcolor->getColor(ColorID::ERed);
    r->draw();
}

