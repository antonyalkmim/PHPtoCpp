# PHPtoCpp

PHPtoCpp it is a simple transpiler that transforms your **PHP** file to **C++** file.

### Usage
```sh
$ git clone https://github.com/antonyalkmim/PHPtoCpp
$ cd PHPtoCpp
$ cmake CMakeLists.txt
$ make
$ PHPtoCpp index.php
```
Will generate a ```index.php.cpp``` file.

### Example

**PHP** infile( ```index.php``` ):
```php
<?php
    $foo = $_POST['foo'] ; //string
    $bar = 1 + 2 ; //int

    if ( $foo ) {
        $fb = $bar ; //int
        echo $fb ;
    }
?>
```

**C++** outfile (```index.php.cpp```):
```cpp
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    string foo;
    cin >> foo;

    int bar = 1 + 2 ;

    if ( foo ) {
        int fb = bar ;
        cout << fb ;
    }
}
```


### Issues
- It is converting only sequencial and simple PHP commands
- All tokens should be separeted by a single space ```if ( true ) { ... } ```
- Datatypes should be declared in the final of variable declaration the line:
  - Ex: ```$foo = 1 ; //int```
  - Datatypes: ```//int```,```//float```, ```//double```, ```//bool```, ```//string```
- Input data has to be: ```$_REQUEST['name']```, ```$_POST['name']``` or ```$_GET['name']```, Example:
  - ```$data = $_POST['data'] ; //string``` will be convert to ```string data; cin >> data;```
- It is included unecessary c++ libraries when converts.
- Variable names should be more then one character:
  - ```$a = 1 ; // segmentation error```
  - ```$aa = 1 ; // convert normally```


License
----
WTFPL

![alt tag](https://github.com/antonyalkmim/PHPtoCpp/blob/master/its_free.jpg)

**It's free**
