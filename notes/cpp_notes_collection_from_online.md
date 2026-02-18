# C++ Array & Pointer Weirdness
10 quirkiest behaviors of arrays and pointers in C++ that often confuse newcomers.

---

## 1️⃣ Swapped Subscript
```cpp
int nums[3] = {10, 20, 30};
std::cout << 1[nums]; // prints 20, same as nums[1]
```
- Reason: `a[b] ≡ *(a + b)` → commutative.

---

## 2️⃣ Pointer Arithmetic Moves by Type
```cpp
int nums[3] = {10, 20, 30};
int* p = nums;
p++;             // moves to nums[1], not the next byte
std::cout << *p; // prints 20
```
- Pointer arithmetic respects **sizeof(type)**.

---

## 3️⃣ Arrays Decay to Pointers
```cpp
void print(int* arr) { std::cout << arr[0]; }
int nums[3] = {10, 20, 30};
print(nums); // works
```
- Arrays automatically convert to pointers in function calls.

---

## 4️⃣ Multidimensional Arrays
```cpp
int mat[2][3] = {{1,2,3},{4,5,6}};
std::cout << *(*(mat+1)+2); // prints 6
```
- Each row is itself an array; pointer arithmetic is layered.

---

## 5️⃣ `sizeof` Confusion
```cpp
int nums[10];
int* p = nums;
std::cout << sizeof(nums); // 10 * sizeof(int)
std::cout << sizeof(p);    // size of pointer, usually 8
```
- Arrays vs pointers give different sizes.

---

## 6️⃣ Pointer to the Whole Array
```cpp
int nums[3] = {1,2,3};
int (*ptr)[3] = &nums; // pointer to entire array
std::cout << (*ptr)[1]; // prints 2
```
- Different from `int* p = nums;`.

---

## 7️⃣ `const` Pointer Rules
```cpp
const int nums[3] = {1,2,3};
int* p = nums;       // ❌ error
const int* cp = nums; // ✅ OK
```
- Respect **const-correctness**.

---

## 8️⃣ Pointer Arithmetic Can Go "Past the Array"
```cpp
int nums[3] = {1,2,3};
int* p = nums + 3; // points just past the array, legal to compute
```
- Dereferencing past the array is **undefined**, but arithmetic itself is allowed.

---

## 9️⃣ `std::array` vs C-style Array
```cpp
std::array<int,3> nums = {1,2,3};
nums[1];        // ✅ works
1[nums];        // ❌ won’t compile
1[nums.data()]; // ✅ works (using pointer)
```
- `std::array` is a class; `[]` is a member function, not raw pointer arithmetic.

---

## 🔟 Fun with Pointer Casts
```cpp
char buffer[4] = {1,2,3,4};
int* ip = (int*)buffer;
std::cout << *ip; // may print 67305985 on little-endian machines
```
- Interprets memory differently, can be used for “type punning.”
- ⚠️ Dangerous and platform-dependent.

---

💡 **Takeaway:**
Most C++ array/pointer quirks boil down to **memory layout + pointer arithmetic + array decay**. Once you see memory as a contiguous sequence of bytes with pointer math, many quirks stop being "magic."


