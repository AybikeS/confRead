# confRead
This is a simple library for reading configuration files.

## Instructions
The formatting of the config file must be as follows per line for the library to function:

data_name: The name by which the data will be searched within the memory.
data_value: The relevant value attached to the name.
```
data_name=data_value
```

## Additional Features
To write comments within the config file, make sure that the first character in the line is "#".
To print out the contents of the config file to the shell, call the ```printFileContent()``` function.

## Install library
```
$ git clone https://github.com/AybikeS/confRead.git
$ make
$ make install
```

## Usage example
```
$ cd example/
$ make
$ ./usage_example_lib.out test.conf
```
## Functions
Read the data from the config file and make it avaliable in memory.
```takeFileContent()```

Search for the given data_name and return the respective value -as int.
```dataAsInt()```

Search for the given data_name and return the respective value -as string.
```dataAsStr()```

Search for the given data_name and return the respective value -as float.
```dataAsFloat()```

## Credits
This library was written by Efe Yılmaz, Narin Yaren Coşkun, Aybike Sena Şahin and Ali Yiğit Ergen during their internship at Ford Otosan.
