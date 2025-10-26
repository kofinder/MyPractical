# **S.O.L.I.D Principles**
> Principles for writing clean, maintainable, and scalable object-oriented code.

---

## **1. Single Responsibility Principle (SRP)**
- Each class should have **one and only one responsibility** — promoting high cohesion.  
- A class should have a **single reason to change**, improving maintainability, clarity, and modularity.

---

## **2. Open/Closed Principle (OCP)**
- **Open for extension, closed for modification.**  
- Software entities (classes, modules, functions) should allow new behavior to be added **without altering existing code**.

---

## **3. Liskov Substitution Principle (LSP)**
- **Subtypes must be substitutable for their base types.**  
- Objects of a parent class should be replaceable with objects of a subclass **without breaking program behavior**.

---

## **4. Interface Segregation Principle (ISP)**
- **Keep interfaces small and focused.**  
- Clients should not depend on methods they do not use. Prefer multiple fine-grained interfaces over one large interface.

---

## **5. Dependency Inversion Principle (DIP)**
- **Depend on abstractions, not concretions.**  
- High-level modules should not depend on low-level modules; both should depend on **abstractions** (interfaces or abstract classes).

---

# **Design Patterns Overview**
> A **design pattern** is a general, reusable solution to a common software design problem.  
> It serves as a **template** for structuring and solving recurring challenges.

**Key Characteristics:**
- **Problem-Solving:** Standard approaches to recurring design issues.  
- **Reusability:** Applicable across different projects and contexts.  
- **Abstraction:** Focuses on concepts and relationships rather than concrete implementations.  
- **Communication:** Establishes a common vocabulary among developers.

---

# **Creational Design Patterns**
> Focus: Object creation mechanisms — making object instantiation flexible and reusable.  
> Purpose: Abstract creation so systems are independent of how objects are created.

---

## **1. Singleton Pattern**
- **Intent:** Ensure a class has only one instance with a global access point.  
- **Structure:** Private constructor, static instance, global access method.  
- **When to Use:** Exactly one instance is needed to coordinate actions across the system.  
- **Key Participants:** The class itself and its clients.  
- **Benefits:** Controlled global access, prevents multiple instances, saves resources.  
- **Analogy:** President of a country — only one recognized instance exists at a time.

---

## **2. Factory Method Pattern**
- **Intent:** Define an interface for creating objects but let subclasses decide which class to instantiate.  
- **Structure:** `AbstractCreator`, `ConcreteCreator`, `Product`  
- **When to Use:** When a class cannot anticipate the type of objects it must create or wants to delegate creation.  
- **Key Participants:** `Creator`, `ConcreteCreator`, `Product`  
- **Benefits:** Promotes loose coupling, supports Open/Closed Principle.  
- **Analogy:** Remote control button creating different devices depending on the button pressed.

---

## **3. Abstract Factory Pattern**
- **Intent:** Provide an interface for creating **families of related objects** without specifying concrete classes.  
- **Structure:** `AbstractFactory`, `ConcreteFactory`, `AbstractProduct`, `ConcreteProduct`  
- **When to Use:** System must work with multiple families of related objects.  
- **Key Participants:** `AbstractFactory`, `ConcreteFactory`, product families  
- **Benefits:** Ensures product consistency across families, promotes scalability.  
- **Analogy:** GUI factory creating either Windows or Mac widgets.

---

## **4. Builder Pattern**
- **Intent:** Separate construction of a complex object from its representation.  
- **Structure:** `Builder`, `ConcreteBuilder`, `Director`, `Product`  
- **When to Use:** Object creation involves multiple steps or configurations.  
- **Key Participants:** `Director`, `Builder`, `ConcreteBuilder`, `Product`  
- **Benefits:** Simplifies construction, improves readability and flexibility, supports multiple representations.  
- **Analogy:** Building a house — foundation → walls → roof → finishing.

---

## **5. Prototype Pattern**
- **Intent:** Create new objects by **cloning existing ones** rather than creating from scratch.  
- **Structure:** `Prototype`, `ConcretePrototype`, `Client`  
- **When to Use:** Object creation is expensive or similar objects are needed.  
- **Key Participants:** `Prototype`, `ConcretePrototype`, `Client`  
- **Benefits:** Reduces creation cost, preserves object state, simplifies dynamic creation.  
- **Analogy:** Cloning a document or image for reuse.

---

# **Structural Design Patterns**
> Focus: Object composition — simplifying relationships and organizing objects into larger structures.

---

## **1. Adapter Pattern**
- **Intent:** Convert one interface to another to enable interoperability.  
- **Structure:** `Target`, `Adapter`, `Adaptee`  
- **When to Use:** Integrating incompatible classes without modifying their code.  
- **Key Participants:** `Target`, `Adapter`, `Adaptee`  
- **Benefits:** Promotes reuse, avoids code modification.  
- **Analogy:** Power plug converter for international devices.

---

## **2. Composite Pattern**
- **Intent:** Treat individual objects and compositions uniformly.  
- **Structure:** `Component`, `Leaf`, `Composite`  
- **When to Use:** Managing tree structures or hierarchies.  
- **Key Participants:** `Component`, `Leaf`, `Composite`  
- **Benefits:** Simplifies tree management, uniform treatment of objects.  
- **Analogy:** File system directories and files.

---

## **3. Proxy Pattern**
- **Intent:** Provide a surrogate to control access or add functionality.  
- **Structure:** `Subject`, `RealSubject`, `Proxy`  
- **When to Use:** Access control, lazy initialization, or adding extra behavior.  
- **Key Participants:** `Subject`, `RealSubject`, `Proxy`  
- **Benefits:** Reduces cost, adds control transparently.  
- **Analogy:** Virtual assistant acting on behalf of a user.

---

## **4. Bridge Pattern**
- **Intent:** Decouple abstraction from implementation so both can vary independently.  
- **Structure:** `Abstraction`, `RefinedAbstraction`, `Implementor`, `ConcreteImplementor`  
- **When to Use:** Abstraction and implementation may change independently.  
- **Key Participants:** `Abstraction`, `RefinedAbstraction`, `Implementor`, `ConcreteImplementor`  
- **Benefits:** Flexible extension, reduced dependencies.  
- **Analogy:** TV remote controlling different TV brands.

---

## **5. Decorator Pattern**
- **Intent:** Add responsibilities dynamically without modifying the class.  
- **Structure:** `Component`, `ConcreteComponent`, `Decorator`, `ConcreteDecorator`  
- **When to Use:** Enhance behavior at runtime without subclassing.  
- **Key Participants:** `Component`, `ConcreteComponent`, `Decorator`, `ConcreteDecorator`  
- **Benefits:** Flexible behavior extension, avoids subclass explosion.  
- **Analogy:** Coffee with milk, sugar, or flavor additions.

---

## **6. Facade Pattern**
- **Intent:** Provide a unified interface to a complex subsystem.  
- **Structure:** `Facade`, `Subsystems`, `Client`  
- **When to Use:** Simplify usage of complex subsystems.  
- **Key Participants:** `Facade`, `Subsystems`, `Client`  
- **Benefits:** Reduces client complexity, hides internal details.  
- **Analogy:** Car dashboard controlling engine, AC, and music system.

---

## **7. Flyweight Pattern**
- **Intent:** Use shared objects to support many fine-grained objects efficiently.  
- **Structure:** `Flyweight`, `ConcreteFlyweight`, `FlyweightFactory`  
- **When to Use:** Large number of similar objects, memory efficiency is important.  
- **Key Participants:** `Flyweight`, `ConcreteFlyweight`, `FlyweightFactory`, `Client`  
- **Benefits:** Reduces memory usage, improves performance.  
- **Analogy:** Trees in a forest sharing common data.

---

# **Behavioral Design Patterns**
> Focus: Communication and responsibility among objects; managing algorithms, interactions, and object duties.

---

## **1. Command Pattern**
- **Intent:** Encapsulate requests as objects for flexible execution.  
- **Structure:** `Command`, `ConcreteCommand`, `Receiver`, `Invoker`, `Client`  
- **When to Use:** Issuing requests without knowing the receiver or operation.  
- **Key Participants:** `Command`, `ConcreteCommand`, `Receiver`, `Invoker`  
- **Benefits:** Decouples sender and receiver, supports undo/redo, allows dynamic sequencing.  
- **Analogy:** Remote control buttons executing actions.

---

## **2. Iterator Pattern**
- **Intent:** Sequentially access elements without exposing the collection’s structure.  
- **Structure:** `Iterator`, `ConcreteIterator`, `Aggregate`, `ConcreteAggregate`  
- **When to Use:** Uniform access to different collections.  
- **Key Participants:** `Iterator`, `ConcreteIterator`, `Aggregate`, `ConcreteAggregate`  
- **Benefits:** Simplifies traversal, consistent iteration.  
- **Analogy:** Walking through a playlist of songs.

---

## **3. Mediator Pattern**
- **Intent:** Centralize communication to reduce dependencies.  
- **Structure:** `Mediator`, `ConcreteMediator`, `Colleague`  
- **When to Use:** Frequent communication among tightly coupled objects.  
- **Key Participants:** `Mediator`, `ConcreteMediator`, `Colleague`  
- **Benefits:** Simplifies relationships, promotes loose coupling.  
- **Analogy:** Chat room managing messages between participants.

---

## **4. Memento Pattern**
- **Intent:** Capture and restore internal state without breaking encapsulation.  
- **Structure:** `Originator`, `Memento`, `Caretaker`  
- **When to Use:** Undo/redo or state restoration.  
- **Key Participants:** `Originator`, `Memento`, `Caretaker`  
- **Benefits:** Preserves encapsulation, enables rollback.  
- **Analogy:** Undo feature in text editors.

---

## **5. Observer Pattern**
- **Intent:** One-to-many dependency; dependents notified automatically.  
- **Structure:** `Subject`, `ConcreteSubject`, `Observer`, `ConcreteObserver`  
- **When to Use:** Event-driven or publish–subscribe systems.  
- **Key Participants:** `Subject`, `ConcreteSubject`, `Observer`, `ConcreteObserver`  
- **Benefits:** Promotes loose coupling, supports dynamic behavior.  
- **Analogy:** Newspaper subscribers receiving updates automatically.

---

## **6. State Pattern**
- **Intent:** Change object behavior dynamically based on its internal state.  
- **Structure:** `Context`, `State`, `ConcreteState`  
- **When to Use:** Behavior depends on internal state.  
- **Key Participants:** `Context`, `State`, `ConcreteState`  
- **Benefits:** Simplifies state-specific logic, clean transitions.  
- **Analogy:** TCP connection states (Closed, Listening, Established).

---

## **7. Strategy Pattern**
- **Intent:** Encapsulate interchangeable algorithms.  
- **Structure:** `Strategy`, `ConcreteStrategy`, `Context`  
- **When to Use:** Multiple algorithms exist; selection is dynamic.  
- **Key Participants:** `Strategy`, `ConcreteStrategy`, `Context`  
- **Benefits:** Flexible, reusable, simplifies substitution.  
- **Analogy:** Choosing navigation routes — car, bike, walking.

---

## **8. Template Method Pattern**
- **Intent:** Define algorithm skeleton; let subclasses redefine steps.  
- **Structure:** `AbstractClass`, `ConcreteClass`  
- **When to Use:** Shared algorithm structure with varying details.  
- **Key Participants:** `AbstractClass`, `ConcreteClass`  
- **Benefits:** Code reuse, consistent framework.  
- **Analogy:** Game lifecycle: setup → play → teardown.

---

## **9. Visitor Pattern**
- **Intent:** Add operations without changing classes.  
- **Structure:** `Visitor`, `ConcreteVisitor`, `Element`, `ConcreteElement`  
- **When to Use:** Frequently adding new operations to a stable structure.  
- **Key Participants:** `Visitor`, `ConcreteVisitor`, `Element`, `ConcreteElement`  
- **Benefits:** Extends functionality, separates logic from structure.  
- **Analogy:** Exporting objects to XML or JSON.

---

## **10. Chain of Responsibility Pattern**
- **Intent:** Pass requests along a chain until handled.  
- **Structure:** `Handler`, `ConcreteHandler`  
- **When to Use:** Multiple possible handlers; handler unknown in advance.  
- **Key Participants:** `Handler`, `ConcreteHandler`  
- **Benefits:** Reduces coupling, flexible request handling.  
- **Analogy:** Event handling in UI components or middleware pipelines.
