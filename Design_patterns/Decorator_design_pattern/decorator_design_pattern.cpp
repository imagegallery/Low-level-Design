/*

 It enables the dynamic addition of new behaviors or responsibilities to individual objects without altering their 
 underlying class structure. It achieves this by creating a set of decorator classes that are used to wrap concrete 
 components, which represent the core functionality.

 Characteristics:
 1) Decorators conform to the same interface as the components they decorate, allowing them to be used interchangeably.
 2) This pattern promotes flexibility and extensibility in software systems by allowing developers to compose objects with different combinations of functionalities at runtime.
 3) It adheres to the open/closed principle, as new decorators can be added without modifying existing code, making it a powerful tool for building modular and customizable software components.
 4) The Decorator Pattern is commonly used in scenarios where a variety of optional features or behaviors need to be added to objects in a flexible and reusable manner, such as in text formatting, graphical user interfaces, or customization of products like coffee or ice cream.

 Key Components:
 1. Component Interface
This is an abstract class or interface that defines the common interface for both the concrete components and decorators. It specifies the operations that can be performed on the objects.
 2. Concrete Component
These are the basic objects or classes that implement the Component interface. They are the objects to which we want to add new behavior or responsibilities.
 3. Decorator
This is an abstract class that also implements the Component interface and has a reference to a Component object. Decorators are responsible for adding new behaviors to the wrapped Component object.
 4. Concrete Decorator
These are the concrete classes that extend the Decorator class. They add specific behaviors or responsibilities to the Component. Each Concrete Decorator can add one or more behaviors to the Component. 

 Advantages of the Decorator Pattern in C++ Design Patterns
 The decorator pattern is a structural design pattern that allows us to add behavior to individual objects, either statically or dynamically, without affecting the behavior of other objects from the same class. It is often used to extend the functionality of classes in a flexible and reusable way. Here are some of the advantages of the decorator pattern:
 1. Open-Closed Principle:
 The decorator pattern follows the open-closed principle, which states that classes should be open for extension but closed for modification. This means you can introduce new functionality to an existing class without changing its source code.
 2. Flexibility:
 It allows you to add or remove responsibilities (i.e., behaviors) from objects at runtime. This flexibility makes it easy to create complex object structures with varying combinations of behaviors.
 3. Reusable Code:
 Decorators are reusable components. You can create a library of decorator classes and apply them to different objects and classes as needed, reducing code duplication.
 4. Composition over Inheritance:
 Unlike traditional inheritance, which can lead to a deep and inflexible class hierarchy, the decorator pattern uses composition. You can compose objects with different decorators to achieve the desired functionality, avoiding the drawbacks of inheritance, such as tight coupling and rigid hierarchies.
 5. Dynamic Behavior Modification:
 Decorators can be applied or removed at runtime, providing dynamic behavior modification for objects. This is particularly useful when you need to adapt an object’s behavior based on changing requirements or user preferences.
 6. Clear Code Structure:
 The Decorator pattern promotes a clear and structured design, making it easier for developers to understand how different features and responsibilities are added to objects.

 Disadvantages of the Decorator Pattern in C++ Design Patterns
 While the Decorator pattern offers several advantages, it also has some disadvantages and trade-offs to consider when deciding whether to use it in a particular software design. Here are some of the disadvantages of the Decorator pattern:
 1. Complexity:
 As you add more decorators to an object, the code can become more complex and harder to understand. The nesting of decorators can make the codebase difficult to navigate and debug, especially when there are many decorators involved.
 2. Increased Number of Classes:
 When using the Decorator pattern, you often end up with a large number of small, specialized decorator classes. This can lead to a proliferation of classes in your codebase, which may increase maintenance overhead.
 3. Order of Decoration:
 The order in which decorators are applied can affect the final behavior of the object. If decorators are not applied in the correct order, it can lead to unexpected results. Managing the order of decorators can be challenging, especially in complex scenarios.
 4. Potential for Overuse:
 Because it’s easy to add decorators to objects, there is a risk of overusing the Decorator pattern, making the codebase unnecessarily complex. It’s important to use decorators judiciously and only when they genuinely add value to the design.
 5. Not Suitable for Every Situation:
 The Decorator pattern is best suited for situations where you need to add responsibilities to objects dynamically. In cases where the object structure is relatively stable and changes are infrequent, using other design patterns or techniques might be more efficient and straightforward.
 6. Limited Support in Some Languages:
 Some programming languages may not provide convenient support for implementing decorators. Implementing the pattern can be more verbose and less intuitive in such languages
 
 
 Adding additional features to decorate on top of base obj, 
 For eg: like you have base pizza, then you can add mushroooms, cheese, vegetables on it in any order or 
 coffee machine where you can add diff milk, sugar, diff types of coffee or
 diff cars with various features.
 its like we have one base and we are adding features on top of it.

 why do we need decorator pattern? To handle class explosion, because we cant make classes for all permutation 
 and combination of decoration we need to do.

*/


#include <bits/stdc++.h>
using namespace std;

// Component Interface - defines the basic base operation
class Ibase{
    public:
    virtual int cost() = 0;
    virtual ~Ibase() = default;
};

class Derived1 : public Ibase{  //Is a relationship with Ibase
    public:
    int cost(){
        return 100;
    }
};

class Derived2 : public Ibase{ //Is a relationship with Ibase
    public:
    int cost(){
        return 200;
    }
};

/*
class Idecorator : public Ibase{  //Ia s relationship with Ibase (its a type of base obj only it gives you type)
};

class Decorator1 : public Idecorator{
    Ibase *base;  //Has a relationship with Ibase (as base obj always be there on which we are decorating it gives you the bhaviour)
    public:
    Decorator1(Ibase *b){
        this->base = b;
    }
    int cost(){
        return base->cost() + 10;
    }
};

class Decorator2 : public Idecorator{
    Ibase *base;
    public:
    Decorator2(Ibase *b){
        this->base = b;
    }
    int cost(){
        return base->cost() + 20;
    }
};
*/
//another way to define decorator - Abstract class that extends Ibase
class Idecorator : public Ibase{  //Ia s relationship with Ibase (its a type of base obj only it gives you type matching)
    protected:
    Ibase *base;  //Has a relationship with Ibase (as base obj always be there on which we are decorating it gives you the bhaviour)

    public:
    Idecorator(Ibase *b){
        this->base = b;
    }
    int cost(){
        return this->base->cost();
    }
};

class Decorator1 : public Idecorator{
    public:
    Decorator1(Ibase *b) : Idecorator(b){
    }
    int cost(){
        //return Idecorator::cost() + 10;
        //or
        return base->cost() + 10;
    }
};

class Decorator2 : public Idecorator{
    public:
    Decorator2(Ibase *b) : Idecorator(b){
    }
    int cost(){
        return Idecorator::cost() + 20;
    }
};

int main(){
    Ibase *b = new Derived1();
    Idecorator * d1 = new Decorator1(b);
    Idecorator * d2 = new Decorator2(d1);

    cout << "total cost is: " <<  d2->cost() << endl;
    cout << "d1 cost is: " <<  d1->cost() << endl;
    cout << "base cost is: " <<  b->cost() << endl;
    
}