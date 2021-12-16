## Abstract Factory

Abstract factory pattern has creational purpose and provides an interface for
creating families of related or dependent objects without specifying their
concrete classes. Pattern applies to object and deal with object relationships,
which are more dynamic. In contrast to Factory Method, Abstract Factory pattern
produces family of types that are related, ie. it has more than one method of
types it produces.

### When to use

- a system should be independent of how its products are created, composed, and represented
- a system should be configured with one of multiple families of products
- a family of related product objects is designed to be used together
- you want to provide a class library of products, and you want to reveal just their interfaces, not their implementations

### Pros

- You can be sure that the products you’re getting from a factory are compatible with each other.
- You avoid tight coupling between concrete products and client code.

* Single Responsibility Principle. You can extract the product creation code into one place, making the code easier to support.

* Open/Closed Principle. You can introduce new variants of products without breaking existing client code.

### Cons

- The code may become more complicated than it should be, since a lot of new interfaces and classes are introduced along with the pattern.

### Relations with Other Patterns

- Many designs start by using Factory Method (less complicated and more customizable via subclasses) and evolve toward Abstract Factory, Prototype, or Builder (more flexible, but more complicated).

- Builder focuses on constructing complex objects step by step. Abstract Factory specializes in creating families of related objects. Abstract Factory returns the product immediately, whereas Builder lets you run some additional construction steps before fetching the product.

- Abstract Factory classes are often based on a set of Factory Methods, but you can also use Prototype to compose the methods on these classes.

- Abstract Factory can serve as an alternative to Facade when you only want to hide the way the subsystem objects are created from the client code.

- You can use Abstract Factory along with Bridge. This pairing is useful when some abstractions defined by Bridge can only work with specific implementations. In this case, Abstract Factory can encapsulate these relations and hide the complexity from the client code.

- Abstract Factories, Builders and Prototypes can all be implemented as Singletons.
