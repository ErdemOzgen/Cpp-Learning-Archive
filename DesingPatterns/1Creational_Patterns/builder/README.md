## Builder

Builder pattern has creational purpose and separates the construction of a complex object 
from its representation so that the same construction process can create different 
representations. It is object pattern, ie. relationships can be changed at run-time
and are more dynamic. Often is used for building composite structures but constructing
objects requires more domain knowledge of the client than using a Factory.

### When to use

* the algorithm for creating a object should be independent of the parts and how they're assembled
* the construction process must allow different representations for the object that's constructed  

### Pros

*  You can construct objects step-by-step, defer construction steps or run steps recursively.

* You can reuse the same construction code when building various representations of products.

* Single Responsibility Principle. You can isolate complex construction code from the business logic of the product.


### Cons
* The overall complexity of the code increases since the pattern requires creating multiple new classes.

### Relationships With Other Patterns

* Many designs start by using Factory Method (less complicated and more customizable via subclasses) and evolve toward Abstract Factory, Prototype, or Builder (more flexible, but more complicated).

* Builder focuses on constructing complex objects step by step. Abstract Factory specializes in creating families of related objects. Abstract Factory returns the product immediately, whereas Builder lets you run some additional construction steps before fetching the product.

* You can use Builder when creating complex Composite trees because you can program its construction steps to work recursively.

* You can combine Builder with Bridge: the director class plays the role of the abstraction, while different builders act as implementations.

* Abstract Factories, Builders and Prototypes can all be implemented as Singletons.