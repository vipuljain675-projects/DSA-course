/**
 * ============================================================================
 * C++ OBJECT-ORIENTED PROGRAMMING (OOP) MASTER REFERENCE GUIDE
 * ============================================================================
 * An integrated, production-ready single file containing all core OOP theory,
 * architectural concepts, and executable code implementations corresponding
 * directly to the complete course curriculum timestamps.
 * * File Layout:
 * 1. Core Introduction & Structural Foundation
 * 2. Access Specifiers & Data Encapsulation
 * 3. Object Lifecycle (Constructors, 'this' Pointer & Destructors)
 * 4. Memory Management (Shallow vs. Deep Copy Dynamics)
 * 5. Inheritance Topologies & Visibility Matrix Modes
 * 6. Polymorphism (Compile-time vs. Runtime Overriding & Virtual VTABLEs)
 * 7. Architectural Interfaces (Abstraction & Pure Virtual Classes)
 * 8. Shared Context Entities (Static Attributes & Methods)
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

// ============================================================================
// TOPIC 1 & 2: CLASSES, OBJECTS, AND STRUCTURAL FOUNDATION [00:03:38]
// ============================================================================
/**
 * THEORY:
 * - Object-Oriented Programming (OOP) is a paradigm that models software via real-world entities 
 * containing state (attributes) and behavior (functions).
 * - Class: A user-defined data type acting as an immutable blueprint. It allocates no memory.
 * - Object: An active instance of a class allocated on the stack or heap at runtime.
 */
class Car {
public:
    // Attributes / Data Members
    string brand;
    int speed;

    // Methods / Member Functions
    void drive() {
        cout << "[Car] " << brand << " is cruising at " << speed << " km/h.\n";
    }
};


// ============================================================================
// TOPIC 3 & 4: ACCESS SPECIFIERS & DATA ENCAPSULATION [00:17:05] / [00:23:48]
// ============================================================================
/**
 * THEORY:
 * - Access Specifiers control component visibility and secure internal class invariants.
 * 1. private: Accessible exclusively within the class itself (Default C++ rule).
 * 2. protected: Accessible within the class and its derived/child classes.
 * 3. public: Globally accessible from any scope where the object is visible.
 * - Encapsulation: The process of grouping data and operations inside a single unit while hiding
 * internal state behind public Accessors (Getters) and Mutators (Setters) to enforce data integrity.
 */
class Employee {
private:
    string name;
    double salary; // Hidden state variable to prevent arbitrary corruption

public:
    // Mutator (Setter) with data validation defenses
    void setSalary(double empiricalSalary) {
        if (empiricalSalary >= 0.0) {
            salary = empiricalSalary;
        } else {
            cout << "[Error] Negative salary assignment rejected! Defaulting to 0.\n";
            salary = 0.0;
        }
    }

    // Accessor (Getter)
    double getSalary() const {
        return salary;
    }

    void setName(string empName) { name = empName; }
    string getName() const { return name; }
};


// ============================================================================
// TOPIC 5: CONSTRUCTORS & THE 'this' POINTER [00:29:10] / [00:41:08]
// ============================================================================
/**
 * THEORY:
 * - Constructor: A unique initialization method executed automatically upon object instantiation. 
 * It matches the exact class name and possesses no return type descriptor.
 * - 'this' Pointer: An implicit rvalue pointer passed to all non-static member functions. 
 * It stores the exact memory address of the calling object instance.
 * Crucial for resolving shadowing conflicts when local parameters mirror class attribute names.
 */
class Student {
public:
    string name;
    int age;

    // 1. Default Constructor
    Student() {
        name = "Unregistered";
        age = 0;
        cout << "[Constructor] Default constructor invoked.\n";
    }

    // 2. Parameterized Constructor resolving namespace collisions via 'this'
    Student(string name, int age) {
        this->name = name; // 'this->name' maps to the class field; 'name' maps to the local parameter
        this->age = age;   // 'this->age' maps to the class field; 'age' maps to the local parameter
        cout << "[Constructor] Parameterized constructor invoked for: " << this->name << "\n";
    }
};


// ============================================================================
// TOPIC 6 & 7: COPY DYNAMICS (SHALLOW VS. DEEP) & DESTRUCTORS [00:46:33] / [00:51:56] / [01:09:07]
// ============================================================================
/**
 * THEORY:
 * - Shallow Copy: Performs a raw bitwise replication of members. If the class manages raw pointers
 * to heap allocations, a shallow copy replicates only the pointer address, forcing both objects
 * to share a single pointer source. This triggers runtime Undefined Behavior (UB) and double-free crashes.
 * - Deep Copy: Explicitly allocates unique heap memory space for the target copy and copies the underlying value.
 * - Destructor: An automatic cleanup routine invoked when an object exits scope or is explicitly deleted.
 * Prepended with a tilde (~), it takes zero parameters, cannot be overloaded, and frees allocated resources.
 */
class DeepCopyDemo {
private:
    int* dataPointer; // Resource pointer managing dynamic heap allocation

public:
    // Standard Parameterized Constructor
    DeepCopyDemo(int value) {
        dataPointer = new int(value); // Allocate heap storage
        cout << "[Resource] Allocated integer on heap at address: " << dataPointer << "\n";
    }

    // Custom Deep Copy Constructor mapping separate allocations
    DeepCopyDemo(const DeepCopyDemo& source) {
        // Allocate a unique, isolated heap position for the copy instance
        dataPointer = new int(*source.dataPointer);
        cout << "[Deep Copy] Instantiated isolated duplicate allocation at: " << dataPointer << "\n";
    }

    // Destructor to release allocations and avoid severe memory leaks
    ~DeepCopyDemo() {
        cout << "[Destructor] Deallocating heap memory at address: " << dataPointer << "\n";
        delete dataPointer;
    }

    void setValue(int val) { *dataPointer = val; }
    int getValue() const { return *dataPointer; }
};


// ============================================================================
// TOPIC 8: INHERITANCE TOPOLOGIES & VISIBILITY MATRIX MODES [01:14:35] / [01:24:45] / [01:27:01]
// ============================================================================
/**
 * THEORY:
 * - Inheritance allows a Derived (Child) class to acquire the data and operations of a Base (Parent) class.
 * - Inheritance Visibilities affect public/protected members of the Parent when exposed within Child scope:
 * 1. public mode: Base public -> Derived public; Base protected -> Derived protected.
 * 2. protected mode: Base public -> Derived protected; Base protected -> Derived protected.
 * 3. private mode: Base public -> Derived private; Base protected -> Derived private.
 * *Note: Private members of a base class are always hidden and completely inaccessible to derived classes.
 * - Structural Typologies include Single, Multilevel, Multiple, Hierarchical, and Hybrid systems.
 */
class Animal {
public:
    void breathe() { cout << "[Animal] Consuming oxygen gas...\n"; }
};

// Single public inheritance mode
class Mammal : public Animal {
public:
    void walk() { cout << "[Mammal] Moving across terrestrial terrain.\n"; }
};

// Multilevel Inheritance chain (Animal -> Mammal -> Dog)
class Dog : public Mammal {
public:
    void bark() { cout << "[Dog] Woof! Woof!\n"; }
};


// ============================================================================
// TOPIC 9 & 10: POLYMORPHISM, OVERRIDING & VIRTUAL FUNCTIONS [01:35:10] / [01:43:33] / [01:46:40]
// ============================================================================
/**
 * THEORY:
 * - Polymorphism ("Many Forms") is broken down into Compile-time (Overloading) and Runtime (Overriding).
 * - Function Overriding occurs when a derived class defines a method with an identical signature to a base class method.
 * - Runtime Polymorphism requires the 'virtual' keyword. Without 'virtual', C++ uses static binding
 * based solely on the compilation type of the pointer rather than the active type of the object.
 * - Marking a function 'virtual' instructs the compiler to generate a Virtual Table (VTABLE). At runtime, 
 * the dynamic object type is inspected, tracking down the accurate overriding function signature.
 */
class BaseVisualizer {
public:
    // Standard method resolved via Compile-time Static Binding
    void renderStatic() {
        cout << "[Base] Rendering standard static frame.\n";
    }

    // Virtual method resolved via Runtime Dynamic Binding
    virtual void renderDynamic() {
        cout << "[Base] Executing base virtual dynamic rendering sequence.\n";
    }

    virtual ~BaseVisualizer() = default; // Essential virtual destructor for polymorphic classes
};

class DerivedVisualizer : public BaseVisualizer {
public:
    // Overriding the static structural function name
    void renderStatic() {
        cout << "[Derived] Rendering custom static frame.\n";
    }

    // Formally Overriding the dynamic base virtual method
    void renderDynamic() override {
        cout << "[Derived] Executing custom overridden derived rendering path!\n";
    }
};


// ============================================================================
// TOPIC 11: ARCHITECTURAL INTERFACES (ABSTRACTION & ABSTRACT CLASSES) [01:48:25] / [01:49:58]
// ============================================================================
/**
 * THEORY:
 * - Abstraction: Hiding implementation details while presenting a clean interface.
 * - Pure Virtual Function: A virtual function assigned to zero (= 0), carrying no base definition.
 * - Abstract Class: Any class containing at least one pure virtual function. It cannot be instantiated
 * directly using the 'new' operator or standard declarations. It acts purely as a structural interface contract.
 * Derived classes must override all pure virtual targets to become concrete, instantiable units.
 */
class DatabaseInterface {
public:
    // Pure Virtual Function declaring an absolute behavioral contract
    virtual void connect() = 0; 
    virtual ~DatabaseInterface() = default;
};

class PostgreSQLDriver : public DatabaseInterface {
public:
    // Concretely satisfying the pure interface constraint
    void connect() override {
        cout << "[Database] Successfully opened socket to PostgreSQL instance via port 5432.\n";
    }
};


// ============================================================================
// TOPIC 12: SHARED CONTEXT ENTITIES (THE STATIC KEYWORD) [01:55:15]
// ============================================================================
/**
 * THEORY:
 * - Static Data Members: Attributes bound to the class scope itself rather than independent object instances.
 * Only a single shared instance exists in memory for the duration of the execution flow. Must be defined externally.
 * - Static Member Functions: Methods executable directly via the class name using the scope resolution operator (`::`).
 * They hold no implicit 'this' pointer and can only interact with other static data or functions.
 */
class ExecutionTracker {
public:
    static int activeInstancesCount; // Shared static variable declaration

    ExecutionTracker() {
        activeInstancesCount++;
    }

    // Shared Static Member Function
    static int getActiveCount() {
        return activeInstancesCount; // Accessible without instantiating an object
    }
};

// Mandatory external scope resolution definition of static class tracking attributes
int ExecutionTracker::activeInstancesCount = 0;


// ============================================================================
// MAIN INTEGRATED EXECUTION HARNESS
// ============================================================================
int main() {
    cout << "=======================================================================\n";
    cout << "RUNNING INTEGRATED C++ OOP COMPREHENSIVE EXECUTION RUN\n";
    cout << "=======================================================================\n\n";

    // 1. Classes & Objects Execution Test
    cout << "--- 1 & 2. Classes & Objects ---\n";
    Car myCar;
    myCar.brand = "Tesla Model S";
    myCar.speed = 200;
    myCar.drive();
    cout << "\n";

    // 2. Encapsulation Execution Test
    cout << "--- 3 & 4. Access Specifiers & Encapsulation ---\n";
    Employee emp;
    emp.setName("Alice Vance");
    emp.setSalary(95000.50);
    cout << "[Employee Data] Name: " << emp.getName() << " | Salary: $" << emp.getSalary() << "\n";
    emp.setSalary(-5000.00); // Triggers validation error safety catch
    cout << "\n";

    // 3. Constructors & This Pointer Execution Test
    cout << "--- 5. Constructors & 'this' Pointer ---\n";
    Student fallbackStudent; // Default
    Student customStudent("John Doe", 21); // Parameterized
    cout << "[Student Data] Name: " << customStudent.name << " | Age: " << customStudent.age << "\n\n";

    // 4. Memory Copy Contours Execution Test
    cout << "--- 6 & 7. Copy Dynamics (Shallow vs. Deep) & Destructors ---\n";
    {
        cout << "[Scope Start] Initializing master entity:\n";
        DeepCopyDemo masterEntity(42);
        
        cout << "[Scope Action] Executing Deep Copy tracking duplicate allocation:\n";
        DeepCopyDemo copiedEntity = masterEntity; // Invokes deep copy constructor cleanly
        
        copiedEntity.setValue(99);
        cout << "[Verification] Master Value: " << masterEntity.getValue() << " | Copied Value: " << copiedEntity.getValue() << "\n";
        cout << "[Scope End] Exiting block scope context safely...\n";
    }
    cout << "\n";

    // 5. Inheritance Chains Execution Test
    cout << "--- 8. Inheritance Topologies ---\n";
    Dog myDog;
    myDog.breathe(); // Inherited from Animal
    myDog.walk();    // Inherited from Mammal
    myDog.bark();    // Local to Dog
    cout << "\n";

    // 6. Dynamic Binding & Polymorphism Execution Test
    cout << "--- 9 & 10. Polymorphism & Virtual Functions ---\n";
    DerivedVisualizer actualDerivedObj;
    BaseVisualizer* polyPointer = &actualDerivedObj;

    cout << "[Static Binding Test] Calling non-virtual renderStatic() via Base pointer:\n";
    polyPointer->renderStatic(); // Executes Base version due to compilation pointer mapping

    cout << "[Dynamic Binding Test] Calling virtual renderDynamic() via Base pointer:\n";
    polyPointer->renderDynamic(); // Executes Derived version because of VTABLE dynamic routing
    cout << "\n";

    // 7. Architectural Abstract Contracts Execution Test
    cout << "--- 11. Abstraction & Abstract Classes ---\n";
    // DatabaseInterface invalidInstance; // Compilation Error! Abstract interfaces cannot be instantiated.
    PostgreSQLDriver pgDb;
    DatabaseInterface* interfacePtr = &pgDb;
    interfacePtr->connect();
    cout << "\n";

    // 8. Shared Class Context Execution Test
    cout << "--- 12. Static Keywords ---\n";
    cout << "[Initial Counter] Active global entities: " << ExecutionTracker::getActiveCount() << "\n";
    ExecutionTracker instanceA;
    ExecutionTracker instanceB;
    ExecutionTracker instanceC;
    cout << "[Post-Instantiation Counter] Active global shared entities: " << ExecutionTracker::getActiveCount() << "\n";
    cout << "=======================================================================\n";
    
    return 0;
}