Java Questions

1. What is the default value of an integer array in Java?
    - In Java, arrays are objects, and their elements get default values depending on their data type.
    - For primitive types, default values are: 0, 0.0, '\u0000' (null character), false
    - Object references (e.g., String, Integer, etc.) null
2. How do you define a jagged array in Java?
    - A jagged array (also called a ragged array) in Java is an array of arrays where the inner arrays can have different lengths.
    - So, unlike a rectangular 2D array (where all rows have the same number of columns), in a jagged array each “row” can have a different size.
3. How do you find the largest element in an array in Java?

4. How do you check if two arrays are equal in Java?
    - Arrays.equals()

5. What is the correct way to copy an array in Java?
    - System.arraycopy(source, 0, dest, 0, source.length);
    - Arrays.copyOf(source, source.length);
    - source.clone();
    - Arrays.copyOfRange(source, from, to);

6. What is the time complexity of linear search in an array?
    - The time complexity of linear search is O(n).

7. Why are Strings immutable in Java?
    - Strings are immutable (cannot be changed after creation) for security, performance, and thread safety reasons.

8. How does the intern() method affect Strings in Java?
    - The intern() method ensures that identical string literals share the same reference in the String pool.

9. What happens if multiple threads try to modify a StringBuilder instance?
    - StringBuilder is not thread-safe.
    - If multiple threads modify it at the same time → you get data inconsistency or corruption.

10. What happens if an abstract class does not have any abstract methods?
    - It’s allowed!
    - An abstract class can have only concrete (non-abstract) methods.

11. Which of the following correctly describes the relationship between interfaces and abstract classes in the context of inheritance?
    - A class can implement multiple interfaces but extend only one abstract class.
    - An interface cannot extend a class, but it can extend other interfaces.

12. What will happen if two classes in different packages have the same name and are imported in a Java file?
    - You’ll get a compilation error if you import both explicitly because of ambiguity.

13. Which access modifier allows a member to be accessible within the same package but not from outside?
    - Default (package-private) access — when no modifier is specified.

15. What happens if a class implements two interfaces with the same default method?
    - Compilation error — ambiguity must be resolved manually by overriding the method in the class.

16. Can an interface method be private? 
    - Yes
17. How is a nested interface defined in Java? 
    - Yes
20. What is the primary use of a marker interface in Java?
    - A marker interface provides metadata that can be checked at runtime using instanceof or reflection.

21. How is Comparator different from Comparable?
    - Comparable = “how this object compares to another object” (natural ordering, inside the class).
    - Comparator = “how two objects are compared” (external, allows multiple orders).
    - Comparator is useful for custom sorting without modifying the original class, whereas Comparable is implemented inside the class.

22. What is the benefit of using a lambda expression with a Comparator?
    - Using lambda expressions with Comparator reduces boilerplate code, making sorting concise and readable.

23. Which of the following is NOT a part of the Java Collection Framework?
    - Array is a part of Java's core data structures but is not a part of the Collection Framework.

24. Which method in the Collections class is used to make a collection immutable?
    - Collections.unmodifiableCollection() creates a read-only view of a collection.

25. What will happen if you try to add a null key in a HashMap?
    - HashMap allows one null key but multiple null values.

26. Which of the following is true about LinkedHashSet?
    - LinkedHashSet maintains the insertion order while still using hashing internally.

27. What is the default capacity of ArrayList when using the no-arg constructor?
    - The default capacity of ArrayList is 10, and it increases dynamically when needed.

28. Which of the following Queue implementations provides thread-safe access?
    - ConcurrentLinkedQueue is a thread-safe queue implementation in Java.

29. What is the key difference between Collection and Collections?
    - Collection is a root interface in the Java Collection Framework, while Collections is a utility class that provides helper methods for collections.

30. Which List implementation provides the best performance for random access operations?
    - ArrayList provides O(1) random access using an internal array, whereas LinkedList has O(n) access time.

31. Which of the following statements is true about LinkedList?
    - LinkedList is implemented as a doubly linked list, making insertions and deletions efficient at both ends.

32. What is the time complexity of ArrayList.add(index, element) operation in the worst case?
    - In the worst case, elements must be shifted to the right, making the complexity O(n).

33. Which of the following List implementations is synchronized?
    - Vector is synchronized, while ArrayList and LinkedList are not. CopyOnWriteArrayList is also thread-safe but not fully synchronized.

34. Which method is used to obtain a sublist from an existing List?
    - The subList(start, end) method returns a view of the original list between the given indices.

35. Which of the following methods returns the number of elements in an ArrayList?
    - The size() method returns the number of elements in the ArrayList.

36. What will happen if you try to access an element with an index greater than the size of the ArrayList?
    - Accessing an invalid index (greater than or equal to the size) will throw an IndexOutOfBoundsException.

35. What is the maximum capacity of an ArrayList?
    - The maximum size of an ArrayList is 2^31 - 1, which is the maximum value for an integer in Java. However, practical limits may vary depending on system memory.

36. Which package contains the LinkedList class in Java?
    - The LinkedList class is part of the java.util package in Java.

37. What is the time complexity of inserting an element at the beginning of a LinkedList?
    - Unlike ArrayList, inserting an element at the beginning of a LinkedList is O(1), since it maintains a pointer to the head.

38. What will happen if you try to access an element at an invalid index using get(int index)?
    - If an invalid index is accessed, LinkedList throws an IndexOutOfBoundsException.

39. Which of the following statements about LinkedList and ArrayList is true?
    - Each node in a LinkedList stores data + two pointers (previous & next), increasing memory consumption compared to ArrayList.

40. How does LinkedList differ from ArrayList when searching for an element?
    - ArrayList allows O(1) access using an index, while LinkedList requires O(n) traversal due to its node-based structure.

41. What happens when pollFirst() is called on an empty LinkedList?
    - Unlike removeFirst(), which throws an exception if the list is empty, pollFirst() returns null safely.

42. Which method retrieves, but does not remove, the last element of a LinkedList?
    - The peekLast() method retrieves the last element without removing it, avoiding an exception if the list is empty.

43. Which of the following describes how HashSet stores elements in Java?
    - HashSet internally uses a HashMap to store its elements. The elements are hashed using their hashCode() and then placed into appropriate buckets of the hash table.

44. Which of the following is true about HashSet?
    - HashSet does not maintain insertion order because it is backed by a hash table.

45. What is the time complexity of contains() operation in HashSet?
    - Since HashSet is backed by a HashMap, the contains() method typically runs in O(1) time.

46. What is the key difference between LinkedHashSet and HashSet?
    - Unlike HashSet, which does not maintain insertion order, LinkedHashSet preserves the order in which elements were added.

47. What happens when you insert null in a TreeSet?
    - TreeSet does not allow null because it uses a comparator to sort elements, which throws a NullPointerException when comparing null.

48. Which statement about HashSet, TreeSet, and LinkedHashSet is correct?
    - LinkedHashSet maintains the insertion order, while HashSet does not and TreeSet stores elements in sorted order.

49. Which statement about the Queue interface in Java is correct?
    - The Queue interface follows the FIFO (First In, First Out) principle, meaning elements are processed in the order they were added.

50. What is the time complexity of offer(), poll(), and peek() operations in PriorityQueue?
    - PriorityQueue is implemented using a binary heap, so insertion (offer) and removal (poll) take O(log n), while peeking (peek) takes O(1).
    - PriorityQueue does not maintain insertion order but follows natural ordering (min-heap by default). The smallest element (10) is removed first.

51. Which of the following statements is true about Deque in Java?
    - Deque (Double-ended Queue) allows insertion and removal from both ends, making it useful as both a Queue (FIFO) and a Stack (LIFO).

52. Which of the following is not a valid implementation of Map in Java?
    - LinkedListMap does not exist in Java. The valid implementations of Map include HashMap, TreeMap, LinkedHashMap, and Hashtable.
    - In HashMap, if a key already exists, the new value replaces the old value. "A" initially holds 10, but after map.put("A", 30), the value becomes 30.

53. What is the key difference between HashMap and LinkedHashMap?
    - Unlike HashMap, LinkedHashMap maintains insertion order while still allowing null keys and values.
    - HashMap allows one null key. The value 300 is stored against null, so map.get(null) returns 300.

54. Which of the following statements about TreeMap is correct?
    - TreeMap sorts keys in their natural order (ascending) by default, unlike HashMap or LinkedHashMap.

55. What is the primary difference between Comparable and Comparator?
    - Comparable is implemented in a class to define its natural ordering, while Comparator is used to define custom sorting logic outside the class.

56. Which method must be implemented when using the Comparable interface?
    - The Comparable interface requires the compareTo(T o) method, which determines the natural ordering of objects.

57. What is the return type of the compareTo() method in Comparable?
    - The compareTo() method returns an int value:
    - Negative (< 0) if the current object is smaller
    - Zero (0) if both objects are equal
    - Positive (> 0) if the current object is greater

58. What happens if two objects are equal according to compareTo()?
    - If two objects are equal in comparison, compareTo() must return 0, indicating no difference in order.
    - The compareTo() method sorts employees based on id in ascending order, so the output is [1 - Bob, 2 - Charlie, 3 - Alice].

59. Which of the following statements about Comparator is true?
    - Comparator allows custom sorting logic and can be implemented using lambda expressions to simplify sorting.
    - The correct logic for descending order sorting is return b - a;.
    - Comparator is the best choice when sorting based on multiple attributes dynamically, as different comparator implementations can be used.

60. What is the purpose of an Iterator in Java?
    - An Iterator is used to traverse elements one-by-one in a collection without exposing its structure.

61. Which method of Iterator removes the last element returned by next()?
    - The remove() method removes the last accessed element during iteration.

62. What happens if next() is called on an Iterator when there are no more elements?
    - Calling next() beyond available elements throws NoSuchElementException to prevent accessing invalid data.

63. Which type of Java collection supports ListIterator?
    - ListIterator is only available for List types (like ArrayList, LinkedList) as it supports bidirectional traversal.

64. What is a key advantage of ListIterator over Iterator?
    - ListIterator supports bidirectional traversal with next() and previous().
    - The Iterator interface does not provide previous(); only ListIterator allows backward traversal.

65. How can you safely modify a collection while iterating through it?
    - The only safe way to modify a collection while iterating is by using Iterator.remove().

66. Which exception occurs when an Iterator is used after modifying the collection directly?
    - Directly modifying a collection while iterating triggers ConcurrentModificationException to prevent inconsistencies.

67. What is the difference between checked and unchecked exceptions?
    - Checked exceptions must be declared in throws or handled in try-catch, while unchecked exceptions don't require explicit handling.
    - The finally block executes regardless of whether an exception occurs or not.

68. What will happen if an exception occurs in a catch block?
    - If an exception occurs inside a catch block, the finally block still executes before termination.

69. What exception is thrown if an invalid index is accessed in an array?
    - Attempting to access an index beyond the valid range of an array throws ArrayIndexOutOfBoundsException.

70. What will happen if no exception occurs in a try block?
    - If no exception occurs, the catch block is skipped, but the finally block always executes.
    - Any object of type Throwable (checked, unchecked, or Error) can be thrown using throw.

71. What happens when finalize() is called on an object?
    - The finalize() method is called by the garbage collector before collecting an object but does not guarantee immediate collection.

72. A thread can be created by extending the Thread class or implementing the Runnable interface. Callable is used for returning results from threads.

73. Which method is used to start a thread in Java?
    - The start() method starts a new thread and calls run(). Directly calling run() will not start a new thread.

74. What is the initial state of a thread when it is created but not yet started?
    - When a thread is created but not started, it is in the NEW state. It moves to RUNNABLE after start() is called.
    - The Runnable interface defines the run() method, which must be implemented to define thread behavior.
    - Before start() → NEW
    - After start() → RUNNABLE (ready or running)
    - After completion → TERMINATED

75. What happens if sleep(1000) is called inside a thread?
    - The join() method ensures the current thread waits until the specified thread completes execution.

76. Which method is used to set the name of a thread in Java?
    - The setName(String name) method of the Thread class is used to assign a name to a thread.

77. What is the key difference between start() and run() in Java threads?
    - Calling start() creates a new thread, whereas calling run() executes it like a normal method in the current thread.

78. What is the effect of Thread.sleep(5000) inside a thread?
    - Thread.sleep(5000) pauses execution for 5 seconds and moves the thread to the TIMED_WAITING state.

79. Which of the following is true about a daemon thread in Java?
    - Daemon threads run in the background and terminate when no user threads are running

80. What happens when setDaemon(true) is called after start()?
    - A thread must be set as a daemon before calling start(). Otherwise, IllegalThreadStateException occurs.

81. How can you check if a thread is a daemon thread?
    - The isDaemon() method returns true if a thread is a daemon thread, otherwise false.

82. Which of the following is NOT a type of memory area allocated by the JVM?
    - The JVM allocates Stack, Heap, and Method Area for memory management, but there is no Local Variable Area in the JVM.

83. Which of the following memory areas in JVM is used to store class-level data like static variables and methods?
    - Method Area is used to store class-level data, such as static variables and methods

84. Where does the Method Area in Java store class-level information?
    - The Method Area stores class-level information such as metadata, method definitions, and static variables.

85. Why is synchronization used in Java multithreading?
    - Synchronization ensures only one thread accesses a critical section, preventing data inconsistency.

86. Which of the following can be synchronized in Java?
    - Java allows both methods and blocks to be synchronized for fine-grained control.

87. Which object does a synchronized instance method lock on?
    - An instance synchronized method locks on the object it belongs to (this).

88. Which type of lock is acquired when using a static synchronized method?
    - A static synchronized method locks on the Class object, not an instance.

89. What happens if two threads access a non-synchronized method of the same object?
    - volatile ensures that changes to a variable are visible across threads, while synchronized ensures mutual exclusion to prevent race conditions.

90. Which of the following is the most common cause of a deadlock in multithreading?
    - Deadlocks occur when threads hold resources and wait for others in a circular way, causing each thread to wait indefinitely.

100. How can deadlock be avoided in a multithreading environment?
    - Deadlock can be avoided by ensuring that threads always acquire locks in a predefined order.

101. What is the purpose of the ReentrantLock in Java?
    - ReentrantLock allows interruptible and flexible lock handling, as well as features like timed lock acquisition and multiple lock attempts.

102. What does the ReentrantLock class provide that a synchronized block does not?
    - ReentrantLock allows a thread to acquire the same lock multiple times, providing more flexibility for nested locks compared to synchronized blocks.

103. Which of the following is a method provided by ReentrantLock to acquire a lock but allows the thread to be interrupted?
    - lockInterruptibly() allows a thread to acquire the lock, but it can be interrupted if necessary, unlike lock(), which blocks the thread until the lock is acquired.

104. What happens if two threads try to acquire the same lock using ReentrantLock simultaneously?
    - Only one thread can acquire the lock at a time. The other thread will be blocked until the lock is released by the first thread.

105. Which of the following methods in ReentrantLock allows a thread to acquire the lock only if it is available, without waiting indefinitely?
    - tryLock() allows a thread to attempt to acquire the lock without blocking. It returns false if the lock is not available.

106. Which of the following accurately describes a fairness policy in ReentrantLock?
    - A fairness policy makes sure the thread that has been waiting the longest gets the lock first. This helps avoid starvation.

107. What is the primary purpose of using ReentrantLock over the synchronized block in Java?
    - ReentrantLock provides additional features like tryLock(), lockInterruptibly(), and timed lock acquisition, which offer more flexibility than the synchronized block.

108. Which of the following IP versions is known for having a larger address space compared to its predecessor?
    - IPV6 has a larger address space than IPV4, with 128-bit addresses compared to IPV4’s 32-bit addresses.

109. In Java networking, how is an IPV6 address represented?
    - IPV6 addresses are represented as 128-bit hexadecimal numbers, typically written as eight groups of four hexadecimal digits.

110. Which protocol does a Java ServerSocket use by default?
    - ServerSocket uses TCP by default for establishing reliable, connection-oriented communication.

111. Which of the following is a characteristic of a connectionless protocol?
    - In connectionless protocols like UDP, no dedicated connection is established before sending data.

112. In socket programming, which method is used by the server to wait for a client to connect?
    - accept() method of ServerSocket waits (blocks) until a client connects.

113. What happens if you don't close a socket after communication?
    - An open socket keeps consuming system resources like memory and ports unless explicitly closed.

114. What is the role of InputStream and OutputStream in socket programming?
    - InputStream and OutputStream are used to read from and write data to the connected socket streams.

115. Which JDBC driver type translates JDBC calls into database-specific calls without using native libraries?
    - Type-4 JDBC drivers (thin drivers) directly convert JDBC calls to database-specific protocol without native code.

116. Before executing any SQL query, which method must be called to establish a database connection?
    - DriverManager.getConnection() is used to establish a connection with a specified database.

117. Which interface represents a SQL database connection in JDBC?
    - The Connection interface represents an active connection to a database in JDBC.

118. Which JDBC statement is used when you need to execute dynamic SQL with different parameters at runtime?
    - PreparedStatement allows setting parameters dynamically and executes SQL efficiently.

119. What exception does JDBC primarily throw when something goes wrong?
    - JDBC throws SQLException for database-related errors.

120. Identify the correct order to perform basic JDBC operations:
    - The correct order is: connect to DB, create statement, execute query, then close the resources.

121. Which JDBC driver type uses an intermediate server to communicate with the database?
    - Type-3 (Network Protocol Driver) uses an intermediate server for communication with the database.

122. Which of the following is true for CallableStatement?
    - CallableStatement is used to call database stored procedures.

123. What does the find() method of the Matcher class do?
    - The find() method is used to find the next substring in the input string that matches the pattern.

124. How do you escape special characters in a Java regular expression?
    - In Java, to escape special characters in regular expressions, you use a double backslash (\\) because a single backslash is an escape character in Java strings.

125. What is the purpose of the Pattern.compile() method in Java regex?
    - Pattern.compile() compiles the given regular expression into a Pattern object, which can then be used for matching.

126. Consider the following regular expression pattern \\w+. What will it match?
    \\w+ matches one or more word characters, which includes letters, digits, and underscores.



1. What is ConcurrentHashMap?
Thread-safe HashMap allowing concurrent reads/writes without locking the entire map.

2. What is immutability in Java?
Objects whose state cannot be changed after creation (e.g., String).

3. How do you reverse a String in Java?
new StringBuilder(str).reverse().toString().

4. Remove duplicates using Java Streams?
list.stream().distinct().collect(Collectors.toList()).

5. Difference between ArrayList and LinkedList?
ArrayList: fast random access, slow insert/delete; LinkedList: fast insert/delete, slow access.

6. Major features introduced in Java 8?
Lambda expressions, Streams API, Optional, Default methods, Date/Time API.

7. What is a functional interface?
Interface with exactly one abstract method.

8. What are lambda expressions?
Anonymous functions providing concise implementation of functional interfaces.

9. How to handle global exceptions in Spring Boot?
Use @ControllerAdvice with @ExceptionHandler.

10. What is @ControllerAdvice?
Handles exceptions globally across all controllers.

11. How do you connect to a database in Spring Boot?
Configure application.properties and use JPA Repository or JdbcTemplate.

12. Flow of a Spring Boot project:
Client → Controller → Service → Repository → Database → Response

13. How to configure multiple databases in Spring Boot?
Create multiple DataSource beans with @Primary and @Qualifier.

14. What is Eureka Server?
Service registry for microservices; allows dynamic service discovery.

15. Difference between Spring and Spring Boot?
Spring: requires configuration; Spring Boot: auto-configuration, embedded server, faster setup.

16. Difference between DROP and DELETE?
DROP: deletes table and data; DELETE: deletes rows only.

17. SQL query to fetch emails that appear more than once:
    SELECT email, COUNT(*) 
    FROM users 
    GROUP BY email 
    HAVING COUNT(*) > 1;

18. Have you worked on production issues?
Yes – debugging, hotfixes, monitoring logs, performance tuning.

19. Code deployment stages?
Dev → QA → Staging → Production

20. Checked vs Unchecked exceptions:
    Checked: must be handled (IOException)
    Unchecked: runtime exceptions, optional handling (NullPointerException)

21. Design patterns you use in projects:
Singleton, Factory, Repository, Service, Observer


22. What is Hashtable and explain features of Hashtable?
    Definition: Hashtable is a legacy class in Java used to store key-value pairs. It implements Map and is synchronized.
    Features:
        Stores data as key-value pairs.
        Keys are unique; values can be duplicate.
        Synchronized (thread-safe).
        Doesn’t allow null keys or null values.
        Legacy class; replaced by ConcurrentHashMap in modern applications.

23. Explain about fail-fast iterators in Java
    Definition: Iterators that throw ConcurrentModificationException if the collection is modified while iterating.
    Example: ArrayList, HashMap iterators.
    Purpose: Detect concurrent modification quickly.


24. Explain about fail-safe iterators in Java
    Definition: Iterators that do not throw exceptions if the collection is modified.
    Example: Iterators of ConcurrentHashMap or CopyOnWriteArrayList.
    Mechanism: Operates on a clone of the collection, so modifications do not affect iteration.

25. If two threads have same priority, which thread will be executed first?
    Thread scheduling is platform-dependent.
    The thread scheduler decides, usually first-come, first-serve, but not guaranteed.

26. What methods are used to prevent thread execution?
    sleep(milliseconds) → pauses thread for a time.
    wait() → waits until notified.
    join() → waits for another thread to finish.
    suspend() → deprecated, but stops thread temporarily.
    yield() → temporarily pauses to allow other threads to execute.

27. Explain yield() method in Thread class
    Definition: Suggests that the thread pause execution to allow other threads of same priority to run.
    Syntax: Thread.yield();
    Note: It’s only a hint to scheduler, not guaranteed.

28. Is it possible for yielded thread to get chance for its execution again?
    Yes, the thread can be rescheduled and resume execution later.

29. Explain the importance of join() method in Thread class
    Definition: Causes the current thread to wait until the thread on which join() is called finishes execution.
    Use: Useful for sequential execution of threads.

30. What are alternatives to Java serialization?
    Alternatives:
        Externalizable interface → custom serialization logic.
        JSON/XML libraries → Jackson, Gson, JAXB.
        Custom object streams → write manually.

31. Explain Serializable interface in Java
    Definition: Marker interface (java.io.Serializable) that enables an object to be converted into a byte stream for storage or transfer.
    Marker interface: Has no methods, used to indicate the class can be serialized.

32. How to make an object serializable in Java?
    Steps:
        Implement Serializable interface.
        Ensure all instance variables are either serializable or marked transient.
        Optional: Define serialVersionUID.

33. What is serialVersionUID and its importance in Java?
    Definition: Unique identifier for a Serializable class.
    Purpose: Ensures version compatibility during deserialization.
    Syntax: private static final long serialVersionUID = 1L;

34. What happens if we don’t define serialVersionUID?
    Java generates it automatically.
    If class structure changes, deserialization may throw InvalidClassException.

35. Can we serialize static variables in Java?
    ❌ No, static variables belong to the class, not the object.
    Only instance variables are serialized.

36. What is the primary purpose of the wait() and notify() methods in Java?
    - The wait() and notify() methods are used for inter-thread communication in Java, allowing threads to wait for certain conditions to be met before continuing.
    - The primary purpose of wait() and notify() is to synchronize threads by allowing one thread to pause execution until another thread signals that it can continue.
    - In Java, the wait() and notify() methods are used for inter-thread communication — that is, they allow multiple threads to coordinate and share resources safely.

37. You get a NullPointerException. What is the most likely cause?
    - The object you are using has not been instantiated.

38. If you encounter UnsupportedClassVersionError it means the code was **\_** on a newer version of Java than the JRE **\_** it.
    - Compiled, Execution

39. Normally, to access a static member of a class such as Math.PI, you would need to specify the class "Math". What would be the best way to allow you to use simply "PI" in your code?
    - Add a static import.




# Java Object Class (11 Predefined Methods)

Methods	Description
1. clone()	            Returns a copy of the object (requires Cloneable)
2. equals(Object obj)	Compares objects for equality (override to compare content)
3. finalize()	        Called by GC before object destruction (rarely used)
4. getClass()	        Returns runtime class of object
5. hashCode()	        Returns integer hash code, used in hashing collections
6. notify()	        Wakes one thread waiting on this object’s monitor
7. notifyAll()	        Wakes all threads waiting on this object’s monitor
8. toString()	        Returns string representation (override to show meaningful info)
9. wait()	            Causes thread to wait indefinitely
10. wait(long timeout)	Wait with timeout (ms)
11. wait(long timeout, int nanos)	Wait with timeout + nanos

# MARKER Interface
    No methods or fields – purely used for identification.
    Used by the JVM or frameworks to provide special behavior.
    Examples in Java:
        Serializable → marks a class as serializable.
        Cloneable → marks a class whose objects can be cloned.
        Remote → marks a class as usable in RMI.



# Thread Analysis    
    *** A thread is a unit of execution inside a process. Every process has at least one thread, called the main thread. A process can be single-threaded or multi-threaded ***

1. "A thread is a unit of execution inside a process."
    * A thread executes code within the context of a process.

2. "Every process has at least one thread, called the main thread."
    * When a program starts, the JVM creates a main thread to run the main() method.
    *  Even if you create no other threads, the process still has this main thread.

3. "A process can be single-threaded or multi-threaded."
    * Single-threaded → only the main thread executes.
    * Multi-threaded → additional threads are created alongside the main thread.


 # UNARY OPERATOR
 1. Bitwise AND - “both must be 1 for the result to be 1. if not 0”

 2. Operator (XOR) - “1 if the bits are different, 0 if they are the same.”

 3. Operator (Right Shift) - “Moves the bits of a number to the right by a certain number of positions”

 4. Operator (Left Shift) - “Moves the bits of a number to the left by a certain number of positions” / “Left shift is like multiplying by 2 for each shift”







# THREAD STATE - Here are all 6 thread states and what they mean:
-------------------- ------------------------------------------
| State             | Description                             |
| ----------------- | --------------------------------------- |
| **NEW**           | Thread created but not started          |
| **RUNNABLE**      | Ready to run or running                 |
| **BLOCKED**       | Waiting for a monitor lock              |
| **WAITING**       | Waiting indefinitely for another thread |
| **TIMED_WAITING** | Waiting for a specified time            |
| **TERMINATED**    | Execution completed                     |
-------------------- -----------------------------------------


# LIST: Time Complexity + Thread Safety
--------------------------- -------------------- ----------------- --------------------------- ----------------------------------- ------------------------------------------------------
| Class                    | Thread-Safe?      | Access (get/set) | Search (contains/indexOf) | Insert/Delete                     | Notes                                                |
| ------------------------ | ----------------  | ---------------- | ------------------------- | --------------------------------- | ---------------------------------------------------- |
| **ArrayList**            | ❌                | O(1)             | O(n)                      | O(n) worst-case (shift elements)  | Resizable array                                      |
| **LinkedList**           | ❌                | O(n)             | O(n)                      | O(1) at ends, O(n) middle         | Doubly-linked list                                   |
| **Vector**               | ✅ (synchronized) | O(1)             | O(n)                      | O(n) worst-case                   | Legacy, synchronized                                 |
| **Stack**                | ✅ (synchronized) | O(1)             | O(n)                      | O(1) (push/pop)                   | Extends Vector                                       |
| **CopyOnWriteArrayList** | ✅                | O(1)             | O(n)                      | O(n) (copy entire array on write) | Best for read-heavy                                  |
| **SynchronizedList**     | ✅ (wrapper)      | O(1)             | O(n)                      | O(n)                              | Uses single lock; iteration needs synchronized block |
---------------------------- ------------------ ------------------- --------------------------- ---------------------------------- -------------------------------------------------------

# SET: Time Complexity + Thread Safety
----------------------------- -------------- ----------- ---------- ------------------- -------------------------------
| Class                     | Thread-Safe?  | Add      | Remove   | Search (contains) | Notes                         |
| ------------------------- | ------------  | -------- | -------- | ----------------- | ----------------------------- |
| **HashSet**               | ❌            | O(1) avg | O(1) avg | O(1) avg          | Backed by HashMap             |
| **LinkedHashSet**         | ❌            | O(1) avg | O(1) avg | O(1) avg          | Maintains insertion order     |
| **TreeSet**               | ❌            | O(log n) | O(log n) | O(log n)          | Red-Black Tree, sorted        |
| **CopyOnWriteArraySet**   | ✅            | O(n)     | O(n)     | O(n)              | Based on CopyOnWriteArrayList |
| **ConcurrentSkipListSet** | ✅            | O(log n) | O(log n) | O(log n)          | Thread-safe, sorted           |
| **SynchronizedSet**       | ✅            | O(1) avg | O(1) avg | O(1) avg          | Wrapper with coarse lock      |
---------------------------- --------------- ---------- ---------- -------------------- -------------------------------

# MAP: Time Complexity + Thread Safety
----------------------------- ------------- ---------- ----------- ---------- ----------------------------------------------
| Class                     | Thread-Safe?  | Put      | Get      | Remove   | Notes                                         |
| ------------------------- | ------------  | -------- | -------- | -------- | --------------------------------------------- |
| **HashMap**               | ❌            | O(1) avg | O(1) avg | O(1) avg | Backed by array+linked list/tree after Java 8 |
| **LinkedHashMap**         | ❌            | O(1) avg | O(1) avg | O(1) avg | Maintains insertion order                     |
| **TreeMap**               | ❌            | O(log n) | O(log n) | O(log n) | Red-Black Tree, sorted                        |
| **ConcurrentHashMap**     | ✅            | O(1) avg | O(1) avg | O(1) avg | Lock-free, high-performance concurrency       |
| **ConcurrentSkipListMap** | ✅            | O(log n) | O(log n) | O(log n) | Sorted, concurrent                            |
| **Hashtable**             | ✅            | O(1) avg | O(1) avg | O(1) avg | Legacy synchronized                           |
| **SynchronizedMap**       | ✅            | O(1) avg | O(1) avg | O(1) avg | Wrapper using coarse-grained lock             |
---------------------------- --------------- ---------- ----------- ---------- -----------------------------------------------

# QUEUE: Time Complexity + Thread Safety
----------------------------- ------------- ------------- ----------- -------- --------------------------------------
| Class                     | Thread-Safe?  | Add       | Remove    | Search | Notes                                |
| ------------------------- | ------------  | --------- | --------- | ------ | ------------------------------------ |
| **PriorityQueue**         | ❌            | O(log n)  | O(log n)  | O(n)   | Heap-based priority queue            |
| **ArrayDeque**            | ❌            | O(1)      | O(1) ends | O(n)   | Resizable array deque                |
| **LinkedList**            | ❌            | O(1) ends | O(1) ends | O(n)   | Can act as queue/deque               |
| **ConcurrentLinkedQueue** | ✅            | O(1)      | O(1)      | O(n)   | Lock-free, unbounded                 |
| **ConcurrentLinkedDeque** | ✅            | O(1)      | O(1)      | O(n)   | Lock-free, double-ended              |
| **LinkedBlockingQueue**   | ✅            | O(1)      | O(1)      | O(n)   | Blocking, uses locks                 |
| **ArrayBlockingQueue**    | ✅            | O(1)      | O(1)      | O(n)   | Bounded blocking queue               |
| **PriorityBlockingQueue** | ✅            | O(log n)  | O(log n)  | O(n)   | Blocking priority queue              |
| **SynchronousQueue**      | ✅            | O(1)      | O(1)      | N/A    | No internal capacity; direct handoff |
---------------------------- ---------------- ---------- ------------ -------- --------------------------------------



-------------------------- ----------------------------------------------------------------------------------------------------------- -------------------------------------------------------------------
| **Keyword**             | **Purpose / Meaning**                                                                                     | **Example**                                                      |
| ----------------------- | --------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------- |
| `module`                | Declares the module and its name                                                                          | `module com.ejavaguru { }`                                       |
| `requires`              | Specifies a dependency on another module                                                                  | `requires java.logging;`                                         |
| `exports`               | Makes a package accessible to other modules                                                               | `exports com.ejavaguru.api;`                                     |
| `opens`                 | Makes a package accessible **via reflection** (for frameworks like serialization or dependency injection) | `opens com.ejavaguru.impl;`                                      |
| `uses`                  | Declares a **service interface** the module consumes                                                      | `uses com.ejavaguru.Service;`                                    |
| `provides ... with ...` | Declares a **service implementation** for a service interface                                             | `provides com.ejavaguru.Service with com.ejavaguru.ServiceImpl;` |
| `with`                  | Paired with `provides` to specify implementation                                                          | See above (`provides ... with ...`)                              |
-------------------------- ----------------------------------------------------------------------------------------------------------- -------------------------------------------------------------------

---------------------------- ------------------------------------------------- ---------------------------------------------------------- --------------------------------------------------------
| Feature                  | Static Initializer                               | Instance Initializer                                     | Constructor                                            |
| ------------------------ | ------------------------------------------------ | -------------------------------------------------------- | ------------------------------------------------------ |
| **Syntax**               | `static { ... }`                                 | `{ ... }`                                                | `ClassName() { ... }`                                  |
| **Execution Time**       | When class is loaded (once)                      | Every time an object is created                          | Every time an object is created (after instance block) |
| **Number of Executions** | Once per class                                   | Once per object                                          | Once per object                                        |
| **Access**               | Only static variables                            | Instance & static variables                              | Instance & static variables                            |
| **Purpose**              | One-time setup (static variables, configuration) | Common initialization for all constructors               | Object-specific initialization                         |
| **Order of Execution**   | 1st                                              | 2nd (per object)                                         | 3rd (per object)                                       |
| **Relation to main()**   | Executes before `main()` if class is loaded      | Executes when object is created                          | Executes when object is created                        |
| **Keyword Needed**       | `static` keyword                                 | None                                                     | None                                                   |
| **Use Case Example**     | Load configuration files, static constants       | Initialize instance variables shared by all constructors | Custom object initialization logic                     |
--------------------------- -------------------------------------------------- ---------------------------------------------------------- ---------------------------------------------------------

```
class Demo {
    static { System.out.println("Static block"); }
    { System.out.println("Instance block"); }
    Demo() { System.out.println("Constructor"); }
    public static void main(String[] args) {
        System.out.println("Main starts");
        new Demo();
        new Demo();
    }
}
```


# Compare IS-A vs HAS-A relationships in Java:

| Feature               | IS-A Relationship                                              | HAS-A Relationship                                                       |
| --------------------- | -------------------------------------------------------------- | ------------------------------------------------------------------------ |
| **Definition**        | Represents **inheritance**; “is a type of”                     | Represents **composition/aggregation**; “has a” or “contains a”          |
| **Implementation**    | Achieved using `extends` (class) or `implements` (interface)   | Achieved by including an object of one class as a field in another class |
| **Nature**            | **Tight coupling**                                             | **Looser coupling**                                                      |
| **Code Example**      | `class Car extends Vehicle { }` → Car **is a** Vehicle         | `class Car { Engine engine; }` → Car **has an** Engine                   |
| **Relationship Type** | Parent-child                                                   | Whole-part                                                               |
| **Access to Methods** | Can access parent class methods (depending on access modifier) | Can access methods via object reference                                  |
| **When to Use**       | When there is a **natural “is a” relationship**                | When one class **contains or uses another**                              |
------------------------ ---------------------------------------------------------------- ---------------------------------------------------------------------------


# Compare Arrays vs Collections in Java:
------------------------ ------------------------------------------ --------------------------------------
| Feature               | Arrays                                   | Collection                          |
| --------------------- | ---------------------------------------- | ----------------------------------- |
| **Size**              | Fixed                                    | Growable                            |
| **Data type**         | Homogeneous only                         | Homogeneous or Heterogeneous        |
| **Primitive support** | Supports both primitive and Object types | Supports only Object types          |
| **Memory management** | Poor                                     | Better                              |
| **Performance**       | Better if size is known in advance       | Less performant                     |
| **Methods**           | Limited predefined methods               | Large library of predefined methods |
------------------------ ------------------------------------------ --------------------------------------


# Compare Collection, List, Queue, and Set in Java:
------------------------- ------------------------ ---------------------------- ------------------------------ -----------------------------
| Feature               | Collection             | List                        | Queue                       | Set                         |
| --------------------- | ---------------------- | --------------------------- | --------------------------- | --------------------------- |
| **Type**              | Super interface        | Sub-interface of Collection | Sub-interface of Collection | Sub-interface of Collection |
| **Duplicates**        | Can store duplicates   | Can store duplicates        | Can store duplicates        | Cannot store duplicates     |
| **Order**             | No guaranteed order    | Maintains insertion order   | No guaranteed order         | No guaranteed order         |
| **Element Retrieval** | Forward direction only | Forward & backward          | Forward & backward          | Forward only                |
| **Adding Elements**   | Only at end            | Anywhere (index-based)      | At start or end             | Only at end                 |
| **Null Values**       | Can store null         | Can store null              | Cannot store null           | Only one null allowed       |
------------------------ ------------------------ ----------------------------- ----------------------------- ------------------------------


# Compare Comparable vs Comparator
------------------------------------ ------------------------------------------- ---------------------------------------------------
| Feature                           | Comparable                               | Comparator                                         |
| --------------------------------- | ---------------------------------------- | -------------------------------------------------- |
| **Sorting sequence**              | Single sorting sequence (e.g., id, name) | Multiple sorting sequences (e.g., id, name, price) |
| **Effect on original class**      | Modifies the original class              | Does not modify the original class                 |
| **Method used**                   | `compareTo()`                            | `compare()`                                        |
| **Package**                       | `java.lang`                              | `java.util`                                        |
| **Usage with Collections.sort()** | `Collections.sort(list)`                 | `Collections.sort(list, comparator)`               |
| **Purpose**                       | Defines natural ordering                 | Defines custom ordering                            |
------------------------------------ ------------------------------------------ -----------------------------------------------------

---------------------------- ----------------------------------------------------------------- -----------------------------------------------------------------
| **Feature**              | **`Stack` (`java.util.Stack`)**                                  | **Notes / Modern Alternative**                                  |
| ------------------------ | ---------------------------------------------------------------- | --------------------------------------------------------------- |
| **Type**                 | Class (extends `Vector`)                                         | Legacy class; part of Java Collections but extends old `Vector` |
| **Collection Framework** | Indirectly implements `List` / `Collection`                      | Not recommended for new code; use `Deque` instead               |
| **Data Structure**       | LIFO (Last-In-First-Out)                                         | Push/pop operations follow LIFO principle                       |
| **Duplicates Allowed**   | Yes                                                              | Can store repeated elements                                     |
| **Order Maintained**     | Yes, elements maintain insertion order (as in `Vector`)          | LIFO order enforced by push/pop                                 |
| **Null Values**          | Yes, can store `null`                                            | Same as `Vector`                                                |
| **Main Methods**         | `push(E item)`, `pop()`, `peek()`, `empty()`, `search(Object o)` | `push` adds to top, `pop` removes from top                      |
| **Thread Safety**        | Yes, because `Vector` methods are synchronized                   | Synchronization can cause overhead; `Deque` is faster           |
| **Modern Replacement**   | `ArrayDeque` (implements `Deque`)                                | Recommended for non-thread-safe stack operations                |
--------------------------- ------------------------------------------------------------------- -----------------------------------------------------------------

# Java COURRENT
----------------------------- ------------- -------------------------- ----------------------------------------
| Feature                    | Level      | Purpose                   | Notes                                 |
| -------------------------- | ---------- | ------------------------- | ------------------------------------- |
| `Thread`                   | Low-level  | Run code in a new thread  | Manual management                     |
| `Runnable`                 | Low-level  | Encapsulate task logic    | Pass to Thread/Executor               |
| `synchronized`             | Low-level  | Protect critical sections | Only one thread at a time             |
| `ExecutorService`          | High-level | Thread pool for tasks     | Efficient task execution              |
| `Future`                   | High-level | Retrieve async result     | Used with ExecutorService             |
| `CompletableFuture`        | High-level | Async composition         | Chain tasks, handle exceptions        |
| `ForkJoinPool`             | High-level | Parallel recursive tasks  | Divide-and-conquer                    |
| `Parallel Stream`          | High-level | Parallel data processing  | Simple syntax, leverages ForkJoinPool |
| `ScheduledExecutorService` | High-level | Delayed/periodic tasks    | Timer-like behavior                   |
------------------------------ ------------ -------------------------- ----------------------------------------


# Java Functional Interfaces Summary

| **Interface**           | **Method (Signature)** | **Input**                | **Output**             | **Purpose / Example Use**                                                                                       |
| ----------------------- | ---------------------- | ------------------------ | ---------------------- | --------------------------------------------------------------------------------------------------------------- |
| **Function<T, R>**      | `R apply(T t)`         | One argument (`T`)       | Returns a value (`R`)  | Transform a value → e.g., convert a String to its length:<br>`Function<String, Integer> len = s -> s.length();` |
| **Predicate<T>**        | `boolean test(T t)`    | One argument (`T`)       | Boolean (`true/false`) | Test a condition → e.g., check if a number is even:<br>`Predicate<Integer> isEven = n -> n % 2 == 0;`           |
| **Consumer<T>**         | `void accept(T t)`     | One argument (`T`)       | No return (void)       | Perform an action → e.g., print a value:<br>`Consumer<String> print = s -> System.out.println(s);`              |
| **Supplier<T>**         | `T get()`              | No input                 | Returns a value (`T`)  | Provide or generate data → e.g., return a random number:<br>`Supplier<Double> random = () -> Math.random();`    |
| **BiFunction<T, U, R>** | `R apply(T t, U u)`    | Two arguments (`T`, `U`) | Returns a value (`R`)  | Combine two inputs → e.g., sum two integers:<br>`BiFunction<Integer, Integer, Integer> add = (a, b) -> a + b;`  |


+--------------------------------------------------------+
|                 JVM Process (Java Virtual Machine)     |
|                                                        |
|   ┌─────────────────────────────────────────────────┐  |
|   │                Application Threads              │  |
|   │                                                 │  |
|   │   [Main Thread]   → runs your main() method      │  |
|   │   [Worker Thread] → (if you create Thread/Runnable)│
|   │   [Executor Threads] → (if you use thread pools) │  |
|   └─────────────────────────────────────────────────┘  |
|                                                        |
|   ┌─────────────────────────────────────────────────┐  |
|   │                JVM System Threads               │  |
|   │                                                 │  |
|   │   [Garbage Collector Thread]  → frees memory     │  |
|   │   [JIT Compiler Thread]       → optimizes code   │  |
|   │   [Finalizer Thread]          → calls finalize() │  |
|   │   [Reference Handler Thread]  → manages Weak/Soft|
|   │   [Signal Dispatcher Thread]  → handles OS signals│
|   │   [Attach Listener Thread]    → debugger/profiler │
|   │   [Common-Cleaner Thread]     → clean up resources│
|   └─────────────────────────────────────────────────┘  |
|                                                        |
+--------------------------------------------------------+




# Java memory layout
------------------------------------ ----------------------------------------------------------------------------------- -----------------------------------------------------------------------------------------------------
| **Memory Segment**                | **Purpose / What it Stores**                                                      | **Notes / JVM Mapping**                                                                            |
| --------------------------------- | --------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| **Method Area**                   | Class-level data: class definitions, static variables, constants, method bytecode | Corresponds to **Text, Data, BSS** segments in traditional memory layout; shared among all threads |
| **Heap**                          | All **objects and arrays** created at runtime                                     | Garbage-collected; instance variables reside here                                                  |
| **Stack**                         | **Method call frames**, local variables, and references                           | Each thread has its own stack; memory is released when method call ends                            |
| **Program Counter (PC) Register** | Holds **address of the current instruction** for each thread                      | One PC register per thread                                                                         |
| **Native Method Stack**           | Memory for **native (non-Java) method execution**                                 | Used when Java calls native libraries (JNI)                                                        |
------------------------------------ ------------------------------------------------------------------------------------ ----------------------------------------------------------------------------------------------------

# Mapping to Classical Segments
-------------------- -------------- ---------------------------------
| Classical Segment | JVM Area    | Explanation                     |
| ----------------- | ----------- | ------------------------------- |
| **Text**          | Method Area | Method bytecode                 |
| **Data**          | Method Area | Initialized static fields       |
| **BSS**           | Method Area | Uninitialized static fields     |
| **Heap**          | Heap        | Objects and arrays              |
| **Stack**         | Stack       | Local variables & method frames |
-------------------- ------------- ---------------------------------

# Memory Samgemnt
------------ ---------------------------------- ---------------- ------------------------
| Segment   | Stores                           | Access         | Purpose               |
| --------- | -------------------------------- | -------------- | --------------------- |
| **Text**  | Code (machine instructions)      | Read + Execute | Runs your program     |
| **Data**  | Initialized globals              | Read + Write   | Keeps static data     |
| **BSS**   | Uninitialized globals            | Read + Write   | Zero-initialized vars |
| **Heap**  | Dynamically allocated memory     | Read + Write   | `new` / `malloc`      |
| **Stack** | Local variables & function calls | Read + Write   | Call frames           |
------------ ---------------------------------- ---------------- ------------------------


The Method Area in Java corresponds to:
    Text segment – method bytecode
    Data segment – initialized static fields
    BSS segment – uninitialized static fields
So, Text + Data + BSS relate to the Method Area.