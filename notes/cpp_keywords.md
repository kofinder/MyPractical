# Noexcept Checklist

## 1. Does it throw?
**Ask:** Could this function ever throw an exception?  

- **Yes →** Don’t use `noexcept`  
- **No →** Proceed to next check

---

## 2. Does it allocate memory or call functions that might throw?
**Examples:** `new`, `std::string`, `std::vector`, file I/O  

- **Yes →** Don’t use `noexcept`  
- **No →** Proceed

---

## 3. Is it a destructor, move constructor, or move assignment?
These should almost always be `noexcept` if possible.  

- **Yes →** Use `noexcept`  
- **No →** Continue checking

---

## 4. Is it small, simple, and guaranteed safe?
**Example:** Pure calculations, pointer manipulations, or trivial functions  

- **Yes →** Safe to mark `noexcept`

---

## 5. Is it part of a template?
Use **conditional `noexcept`**: `noexcept(expr)` where `expr` is a boolean expression depending on template parameters.  

**Example:**
```cpp
template <typename T>
void f(T t) noexcept(noexcept(T())) { 
    T obj;
}
