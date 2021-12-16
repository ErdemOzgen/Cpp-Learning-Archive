## Factory Method

Define an interface for creating an object, but let subclasses decide which class to instantiate.
Factory Method lets a class defer instantiation to subclasses. The pattern has creational purpose
and applies to classes where deals with relationships through inheritence ie. they are static-fixed
at compile time. In contrast to Abstract Factory, Factory Method contain method to produce only one
type of product.

### When to use

- a class cant anticipate the class of objects it must create
- a class wants its subclasses to specify the objects it creates
- classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate

### Pros

- You avoid tight coupling between the creator and the concrete products
- Single Responsibility Principle. You can move the product creation code into one place in the program, making the code easier to support.

* Open/Closed Principle. You can introduce new types of products into the program without breaking existing client code.

### Cons

- The code may become more complicated since you need to introduce a lot of new subclasses to implement the pattern. The best case scenario is when you’re introducing the pattern into an existing hierarchy of creator classes.

### Relations with Other Patterns

- Many designs start by using Factory Method (less complicated and more customizable via subclasses) and evolve toward Abstract Factory, Prototype, or Builder (more flexible, but more complicated).

- Abstract Factory classes are often based on a set of Factory Methods, but you can also use Prototype to compose the methods on these classes.

- You can use Factory Method along with Iterator to let collection subclasses return different types of iterators that are compatible with the collections.

- Prototype isn’t based on inheritance, so it doesn’t have its drawbacks. On the other hand, Prototype requires a complicated initialization of the cloned object. Factory Method is based on inheritance but doesn’t require an initialization step.

- Factory Method is a specialization of Template Method. At the same time, a Factory Method may serve as a step in a large Template Method.
