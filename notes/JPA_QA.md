# Summary Diagram

    1. JDBC: Talks directly to the database.
        JDBC is the low-level Java API for interacting directly with a relational database.
        It defines how Java applications connect to databases, execute SQL statements, and retrieve results.
        You have to manually handle:
            *. SQL queries
            *. Connection management
            *. Transactions
            *. Object-to-table mapping
    2. Hibernate: ORM framework that hides JDBC complexity.
    3. JPA: Standard API that Hibernate (and others) implement.

----------------- ------------------------------ -----------------------------------
| Layer         | Role                         | Example                           |
| ------------- | ---------------------------- | --------------------------------- |
| **JPA**       | Specification / Standard API | `EntityManager`, `@Entity`, `@Id` |
| **Hibernate** | Implementation of JPA        | `SessionFactory`, `Session`       |
| **JDBC**      | Low-level DB access          | `Connection`, `PreparedStatement` |
----------------- ----------------------------- ------------------------------------


# JPA Entity Life Cycle
    🔹 1. New / Transient
        The entity is just created in memory.
        It has no database identity (no primary key assigned by DB).
        Not managed by the persistence context.

    🔹 2. Managed / Persistent
        The entity becomes managed when you call persist() or find().
        It is attached to the persistence context.
        Hibernate tracks all changes and automatically syncs them with the database at flush/commit.

    🔹 3. Detached
        The persistence context (session) is closed or the entity is evicted.
        The entity still exists in memory, but Hibernate stops tracking it.
        You must merge it to make it managed again.

    🔹 4. Removed
        The entity is marked for deletion.
        Hibernate will delete it from the database at transaction commit.

------------------------------ --------------------------------------------------------------------------------------------------------------------------------
| State                       | Description                                                                                                                    |
| ----------------------------| ------------------------------------------------------------------------------------------------------------------------------ |
| **1️⃣ New / Transient**      | Not associated with the database yet.                                                                                          |
| **2️⃣ Managed / Persistent** | Managed by the `EntityManager` (or Hibernate `Session`). Changes are automatically tracked and synchronized with the database. |
| **3️⃣ Detached**             | Was managed, but now disconnected from the persistence context. Changes are *not* saved automatically.                         |
| **4️⃣ Removed**              | Marked for deletion — will be deleted when the transaction is committed.                                                       |
------------------------------- --------------------------------------------------------------------------------------------------------------------------------

# Datagram of Life Cycle

 ┌───────────────────────┐
 │       NEW /           │
 │     TRANSIENT         │
 └──────────┬────────────┘
            │ persist()
            ▼
 ┌───────────────────────┐
 │     MANAGED /         │
 │   PERSISTENT          │
 └────────┬──┬───────────┘
  remove()│  │ detach(), close()
          ▼  ▼
   ┌─────────────┐        merge()
   │  REMOVED    │ <──────────┐
   └─────────────┘            │
          ▲                   │
          │                   ▼
          └───────────── DETACHED ──────► persist() → MANAGED

# Summary Table
------------------------------ ------------- ---------- ----------------------------------------
| Method                      | From State | To State  | Description                           |
| --------------------------- | ---------- | --------- | ------------------------------------- |
| `new`                       | —          | Transient | Entity created but not managed        |
| `persist()`                 | Transient  | Managed   | Add new entity to persistence context |
| `find()` / `getReference()` | —          | Managed   | Retrieve existing entity              |
| `remove()`                  | Managed    | Removed   | Mark for deletion                     |
| `detach()`                  | Managed    | Detached  | Stop managing the entity              |
| `merge()`                   | Detached   | Managed   | Reattach entity                       |
| `close()`                   | Managed    | Detached  | Closing EM detaches all entities      |
------------------------------ ------------ ----------- ----------------------------------------

# Relationship Types
------------------- --------------------------------------------------- ------------------------
| Relationship    | Meaning                                           | Example                |
| --------------- | ------------------------------------------------- | ---------------------- |
| **@OneToOne**   | One entity is related to exactly one other entity | User ↔ Profile         |
| **@OneToMany**  | One entity has many related entities              | Department → Employees |
| **@ManyToOne**  | Many entities belong to one parent                | Employees → Department |
| **@ManyToMany** | Many entities relate to many others               | Students ↔ Courses     |
------------------ --------------------------------------------------- -------------------------

# Cascade Types
    - Cascade tells Hibernate how operations should propagate from one entity to its related entities:

---------------- ---------------------------------------
| Cascade Type | Description                            |
| ------------ | -------------------------------------- |
| `PERSIST`    | Save child when parent is saved        |
| `MERGE`      | Update child when parent is updated    |
| `REMOVE`     | Delete child when parent is deleted    |
| `REFRESH`    | Refresh child when parent is refreshed |
| `ALL`        | All of the above                       |
--------------- -----------------------------------------

# Fetch Types
    - Defines when related entities are loaded:
-------------------------------------- -------------------------------
| Fetch Type                         | Behavior                      |
| ---------------------------------- | ----------------------------- |
| `EAGER`                            | Load immediately (JOIN query) |
| `LAZY` *(default for collections)* | Load on demand when accessed  |
------------------------------------- --------------------------------


# Summary
--------------------------- ------------ ---------------------------- ------------------
| Relationship            | Direction  | Database Mapping           | Example          |
| ----------------------- | ---------- | -------------------------- | ---------------- |
| @OneToOne               | Bi/Uni     | Foreign key                | User → Profile   |
| @OneToMany / @ManyToOne | Usually bi | Foreign key on “many” side | Dept → Employees |
| @ManyToMany             | Bi         | Join table                 | Student ↔ Course |
-------------------------- ------------- ---------------------------- ------------------

# JPQL, Criteria API, and Native SQL (SQL Query)
---------------------------------------------- -------------------------------------- ------------- -----------------------------------------------------------
| Query Type                                 | Language                              | Level      | Key Use Case                                              |
| ------------------------------------------ | ------------------------------------- | ---------- | --------------------------------------------------------- |
| **JPQL (Java Persistence Query Language)** | Object-oriented query language        | High-level | Queries using **entity names** and **fields**, not tables |
| **Criteria API**                           | Type-safe, programmatic query builder | High-level | Dynamic query creation at runtime                         |
| **Native SQL (Native Query)**              | Plain SQL                             | Low-level  | Use real SQL (e.g., for complex DB-specific queries)      |
--------------------------------------------- ---------------------------------------- ------------------------------------------------------------------------

# Summary Table
----------------------------- ------------------------- --------------------------- ------------------------------
| Feature                    | **JPQL**               | **Criteria API**          | **Native SQL**               |
| -------------------------- | ---------------------- | ------------------------- | ---------------------------- |
| **Query Language**         | JPQL (object-oriented) | Java API                  | SQL                          |
| **Targets**                | Entities & fields      | Entities & fields         | Tables & columns             |
| **Type Safety**            | ❌ No                   | ✅ Yes                     | ❌ No                      |
| **Dynamic Query Building** | ⚠️ Limited             | ✅ Excellent               | ✅ (manual string)          |
| **Database Independence**  | ✅ Yes                  | ✅ Yes                     | ❌ No                      |
| **Performance**            | Normal                 | Normal                    | Potentially faster (depends) |
| **Use Case**               | Static queries         | Dynamic / runtime filters | DB-specific logic            |
------------------------------ ------------------------ ---------------------------- -----------------------------

# Typical Usage Pattern in Real Projects

----------------------------------------------- -------------------
| Scenario                                     | Recommended API  |
| -------------------------------------------- | ---------------- |
| Simple, static queries                       | **JPQL**         |
| Complex dynamic filters (e.g., search forms) | **Criteria API** |
| Vendor-specific SQL, stored procedures       | **Native SQL**   |
----------------------------------------------- -------------------


# Recommendation
    * Use get() when you need the actual entity or are not sure if it exists.

    * Use load() when you only need a reference (e.g., for associations) and you know it exists — improves performance.

Let’s break down the difference between get() and load() methods in Hibernate, which are both used to retrieve entities from the database — but behave quite differently.
    They are both methods of the Session interface:
        Session session = sessionFactory.openSession();
        session.get(Entity.class, id);
        session.load(Entity.class, id);

    GET - get() immediately hits the database and returns the actual entity object — or null if not found.
    LOAD - load() does not hit the database immediately — it returns a proxy object (a placeholder). The database is accessed only when you try to use the data.



# Hibernate vs JPA connection pooling

    * JPA doesn’t do pooling — Hibernate (as a JPA provider) or your container does.

    * Hibernate integrates easily with real connection pool providers like HikariCP, C3P0, or DBCP2.

    * Neither JPA nor Hibernate directly implements connection pooling.

    * They use or delegate to a connection pool provider underneath (like HikariCP, C3P0, DBCP, etc.).
    
    * The difference lies in how and where you configure it.