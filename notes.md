# CPP_Module_08
## Object Relationships
Complex objects can be build with other objects, hence having different type of relations with sub-objects.
* Composition : this kind of relationship between objects is a "has a" type. For example, a car has an engine, a car also has tyres, a fraction has a numerator and a denominator. Composition is basically the process of creating complex objects from simpler ones.
* Aggregation : this relationship is similar to composition has it is a part-whole relationship. In opposition to composition, in cas of aggregation creation/destruction of the parts won't be the responsibility of the object. Example: the relation between a person and an address
* Association : Like for aggregation, members can belong to other objects and are not managed by the object. However, in an association the member is unrelated to the object and the relationship can be unidirectional as well as bidirectional. The association model is a "uses-a" relationship type. Example: Doctor and Patients, Doctors earns money from patients, patients get medical advice from doctors.
* Dependency: "occurs when one object invokes another object’s functionality in order to accomplish some specific task".

| Property | Composition | Aggregation | Association |
| ----------- | ----------- | ----------- | ----------- |
| Relationship type	| Whole/Part | Whole/Part | Otherwise Unrelated |
| Members can belong to multiple classes | No | Yes | Yes |
| Members’ existence managed by class | Yes | No | No |
| Directionality | Unidirectional | Unidirectional | Bidirectional |
| Relationship verb | Part-of | Has-a | Uses-a |
[Table Source](https://www.learncpp.com/cpp-tutorial/association/)
[Source on depencies](https://www.learncpp.com/cpp-tutorial/dependencies/)

## Containers
A container class is "a class designed to hold and organize multiple instances of another type (either another class, or a fundamental type)." `std::array`and `std::vector`is a common way of representing arrays in cpp. Even if cpp has built-in ways to represent arrays, the corresponding containers have additionnal embeded functions and are safer to use.

Main shared features of a container:
* Create an empty container (via a constructor)
* Insert a new object into the container
* Remove an object from the container
* Report the number of objects currently in the container
* Empty the container of all objects
* Provide access to the stored objects
* Sort the elements (optional)
[Containers Source](https://www.learncpp.com/cpp-tutorial/container-classes/)

Mainly 2 types of containers:
* " *Value containers* are compositions that store copies of the objects that they are holding (and thus are responsible for creating and destroying those copies)."
* " *Reference containers* are aggregations that store pointers or references to other objects "

# STL Containers 
STL stands for STandard Library. It holds multiple classes such as containers, iterators and algorithms.
STL containers are of 3 basics types:
* Sequence Container: this kind of container will keep elements in the order they were provided : `std::array`, `std::list`, `std::deque`, `std::vector`...
* Associative Container: this kind of container will automatically sort provided elements: `std::set` (collection of unique sorted keys), `std::multiset`(collection of sorted keys), `std::map` (collection of unique sorted key-pair elements), `std::multimap` (collection of sorted key-pair elements)
* Adapaters Container: this kind of container will adapt the behaviour of sequence containers: `std::stack`(elements are operated on a LIFO bases), `std::queue` (elements are operated on a FIFO base), `std::priority_queue`