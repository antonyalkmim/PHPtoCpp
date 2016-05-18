# PHPtoCpp

PHPtoCpp it is a simple transpiler that transforms your **PHP** code to **C++**.

### TODO
- Identifier Tokens, keywords and datatypes
- Assignments (=, .)
- Arithmetic (+, -, *, /, %)
- Booleans (<, >, >=, <=, ==, !=, ||, &&)

### Usage
```sh
$ phptocpp index.php
```
Will generate a ```index.php.cpp``` file.

### Example

**PHP** infile:
```php
<?php
    $foo = "bar ";
    $age = 21;
    echo $foo . $age;
?>
```

**C++** outfile:
```cpp
#include <iostream>
#include <string>

int main(){
    std::string foo = "bar ";
    int age = 21;
    std::cout << foo << std::age;
}
```



### Status
 - Developing




License
----
WTFPL


**It's free**
