SOLID principle

1. Single responsibility principle
  a class should only be responsible for 1 job,
  there is only one reason to edit this class.
2. Open-Close principle
  a class, module or a function should be close for modification
  and open for extension.
3. Liskov substitution principle
  child-class could fully replace its parent, which means inheritance
  only extends functionalities but not break parent-class's original feature.
4. Interface Segregation principle
  client should not depend on interfaces it does not actually requires.
  if a client implements some services, we should segregate interfaces to let
  impl class to only depend on the methods it requires.
5. Dependency Inversion principle
  details rely on abstraction while abstration does not rely on details.
  program's details are implemented on the lower end impl surface.