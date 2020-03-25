// Identifying inheritance situations
Inheritance describes an "Is a" Relationship
A Student is a Person
A Car is a type of Vehicle

// Using inheritance
Overriding
Allowing a subclass to replace the implementation
Of  a method from the superclass

// Abstract and concrete classes
Abstract classes
Exists for other classes to inherit
Cannot be instantiated b/c it contains at least one abstract method declared with signature but no implementation.

Concrete classes
Simple class create objects...
A concrete class has no children.

// Interfaces
Lists of methods for a class to implement. It doesn't contain any actual behaviors / functionalities (no code).
void move(int x, int y);

Interface vs abstract class
Interface represents capabilities while abstract class represents a type.

// Aggregation
Aggregation describes 'has a' relationship
A farm has a farmer
Or Aggregation describes 'use a' relationship

// Composition
Composition implies ownership.
A spaceship owns an engine.
If a composition dies, the contents die.