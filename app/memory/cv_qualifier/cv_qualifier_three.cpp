/*
 * REMARK:
 * In multiple inheritance, base classes may reside at different memory offsets
 * within the derived object. This means pointer adjustments are required when
 * accessing different bases.
 *
 * - static_cast: safely adjusts pointers at compile-time for known inheritance.
 * - dynamic_cast: safely adjusts pointers at runtime for polymorphic types.
 * - reinterpret_cast: does NOT adjust pointers; using it here can lead to
 *   undefined behavior, especially with multiple inheritance.
 */

 struct B { int n = 3; };
 struct B1 { float f = 3.5f; };
 class D : public B, public B1 {};
 
 int main() {
    D d;

    // Using static_cast to correctly adjust pointers
    B* b  = static_cast<B*>(&d);   // points to B part
    B1* b1 = static_cast<B1*>(&d); // points to B1 part
    int n = b->n;   // OK
    float f = b1->f; // OK

    // Using reinterpret_cast ignores offsets → fragile/UB
    B* rb   = reinterpret_cast<B*>(&d);   // points to B part (OK but fragile)
    B1* rb1 = reinterpret_cast<B1*>(&d);  // points incorrectly → UB
    int n1   = rb->n;   // accidental correctness
    float f1 = rb1->f;  // undefined behavior
 }
 
 /*
 Memory layout of D:
 
 Address     | Content
 ------------|--------
 0x1000      | B::n = 3
 0x1004      | B1::f = 3.5f
 0x1008      | end of D
 
 Diagram:
 
 D object at &d = 0x1000
 +-----------+-----------+
 |   B::n    |   B1::f   |
 |   int 3   |  float 3.5|
 +-----------+-----------+
 0x1000      0x1004      0x1008
 
 Pointer casts:
 b   = static_cast<B*>(&d)   -> 0x1000 
 b1  = static_cast<B1*>(&d)  -> 0x1004 
 rb  = reinterpret_cast<B*>(&d)  -> 0x1000 (Fragile)
 rb1 = reinterpret_cast<B1*>(&d) -> 0x1000 (UB)
 */
 