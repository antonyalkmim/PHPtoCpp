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
    $foo = "bar " ; //string
    $age = 21 ; //int

    $enter = $_POST['enter'] ; //string

    echo $foo;
?>
```

**C++** outfile:
```cpp
#include <iostream>
#include <string>

int main(){
    std::string foo = "bar ";
    int age = 21;
    string enter;
    cin >> enter;
    std::cout << foo << std::age;
}
```



### Status
 - Developing




License
----
WTFPL


**It's free**
