# Fast JOAAT Hash Library in C++

This C++ Library offers an implementation of the JOAAT Hashing algorythm. You may refer to the source code for a deeper understanding.

## Usage

```cpp
JOAAT joaat;

uint32_t myData = joaat.hash("HelloWorld");
std::cout << myData << std::endl; // Output: 1654641804

// Or use it with an streaming option:

 while (dataflow) {
     joaat.add("DATA");
 }

uint32_t data = joaat.hash();
std::cout << data << std::endl;
```
