#include <iostream>

#include <iostream>


class DP {
public:
    virtual ~DP() {};
    virtual std::string drawLine() const = 0;
    virtual std::string drawCircle() const = 0;
};

class DP1 : public DP {
public:
    std::string drawLine() const override {
        return "Drawn line by DP1\n";
    }
    std::string drawCircle() const override {
        return "Drawn circle by DP1\n";
    }
};

class DP2 : public DP {
public:
    std::string drawLine() const override {
        return "Drawn line by DP2\n";
    }
    std::string drawCircle() const override {
        return "Drawn circle by DP2\n";
    }
};

class Drawing {
protected:
    DP* lib_;

public:
    explicit Drawing(DP* lib) : lib_(lib) {}

    virtual ~Drawing() = default;

    virtual std::string drawLine() const {
        return "Drawing: Operation:\n" + lib_->drawLine();
    }
    virtual std::string drawCircle() const {
        return "Drawing: Operation:\n" + lib_->drawCircle();
    }
};

class V1Drawing : public Drawing {
public:
    explicit V1Drawing(DP* lib) : Drawing(lib) {}
    std::string drawLine() const override {
        return "V1Drawing: Extended operation:\n" + this->lib_->drawLine();
    }
    std::string drawCircle() const override {
        return "V1Drawing: Extended operation:\n" + this->lib_->drawCircle();
    }
};

class V2Drawing : public Drawing {
public:
    explicit V2Drawing(DP* lib) : Drawing(lib) {}
    std::string drawLine() const override {
        return "V2Drawing: Extended operation:\n" + this->lib_->drawLine();
    }
    std::string drawCircle() const override {
        return "V2Drawing: Extended operation:\n" + this->lib_->drawCircle();
    }
};

class Shape {
protected:
    Drawing* drawing_;

public:
    explicit Shape(Drawing* drawing) : drawing_(drawing) {}

    virtual ~Shape() = default;

    virtual void setLib(Drawing* drawing) {
        drawing_ = drawing;
    }

    virtual std::string draw() const = 0;
};

class Rectangle : public Shape {
public:
    explicit Rectangle(Drawing* drawing) : Shape(drawing) {}
    std::string draw() const override {
        return "Rectangle: Extended operation with:\n" + drawing_->drawLine();
    }
};

class Circle : public Shape {
public:
    explicit Circle(Drawing* drawing) : Shape(drawing) {}
    std::string draw() const override {
        return "Circle: Extended operation with:\n" + drawing_->drawCircle();
    }
};

void draw(const Shape& d)
{
    std::cout << d.draw() << std::endl;
}


int main()
{
    DP* library1 = new DP1;
    DP* library2 = new DP2;
    Drawing* d1 = new V1Drawing(library1);
    Drawing* d2 = new V2Drawing(library2);
    Shape* p1 = new Rectangle(d1);
    Shape* p2 = new Circle(d2);
    draw(*p1);
    draw(*p2);
    p1->setLib(d2);
    p2->setLib(d1);
    draw(*p1);
    draw(*p2);
    delete p1;
    delete p2;
    delete d1;
    delete d2;
    delete library1;
    delete library2;
}