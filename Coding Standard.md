# C++ Coding Standards

## Functions

- Curly braces should start on the same line

- Function names should be PascalCase (Ex. FooBar)

  - Function names should typically be a verb

- Parameters should be named using CamelCase (same as public variables)

  ```cpp
  void DoSomething(int myParam, ) {
      
  }
  ```

  

## Variables

- Public variables should be CamelCase
- Private variables should start with an underscore

```cpp
public:
	int example = 1;
private:
	int _example2 = 2;
```



## Classes

- Class names should be PascalCase
- In a class, the ordering should follow in the public/private section
  - Public should always be declared first (public -> private)
  - Variables should be above function definitions



## Allocating Memory

- Never allocate memory unless you really need to
- Use a unique/shared pointer if you do have to allocate





