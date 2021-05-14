# BrainFuck Creator 

**Friendly Reminder:** This repository is basically for fun!

The BrainFuck Creator program was created to turn a basic ASCII string into a programatical [BrainFuck](https://wikipedia.org/wiki/Brainfuck) program.

## What is the difference between a Simple and a Programmatical BrainFuck Program?
If you read the wiki page the BrainFuck programming language consists of basic syntaxes that can be represented in the C programming language. A basic representation of a string would be just assigning a number to a cell via simple additions for each character in a string. When done in a programmatic way (like in the Wikipedia page) the program has a while loop that shortens your code by a lot. 

## Why?
There is no reason really. My friends and I send BrainFuck programs to eachother instead of normal sentences. I was bored of programming simple strings with BrainFuck and it started to become a challenge. Thus I created a C++ program for it.

## How do I use this?
If you just want to use it, run the .exe and the program will ask you for a string. Only give it ASCII letters as BrainFucks printing is based on ASCII values. If you want to check out the source code open [main.cpp](/main.cpp) and follow the included .hpp files and their corresponding .cpp files.  

----
Here is a cheatsheet for the BrainFuck programming language:

|     Command     | C Equivalent                                     |
| :-------------: | ------------------------------------------------ |
| (Pragram Start) | `char array[30000] = {0}; char *ptr = &array[0]` |
|       `>`       | `++ptr;`                                         |
|       `<`       | `--ptr;`                                         |
|       `+`       | `++*ptr;`                                        |
|       `-`       | `--*ptr;`                                        |
|       `.`       | `putchar(*ptr);`                                 |
|       `,`       | `scanf("%c", ptr);`                              |
|       `[`       | `while(*ptr) {`                                  |
|       `]`       | `}`                                              |

----

## Some Examples Created With This Program

"Hello World"

* Without Spacing

```
++++++++++++++++[>>++++>++++++>++++++>++++++>++++++>++>+++++>++++++>+++++++>++++++>++++++><<<<<<<<<<<<<-]>>++++++++>+++++>++++++++++++>++++++++++++>+++++++++++++++>>+++++++>+++++++++++++++>++>++++++++++++>++++><[<]>[.>]
```
* With Spacing
```
++++++++++++++++
[
        >>
        ++++>
        ++++++>
        ++++++>
        ++++++>
        ++++++>
        ++>
        +++++>
        ++++++>
        +++++++>
        ++++++>
        ++++++>
<<<<<<<<<<<<<-
]
>>
++++++++>
+++++>
++++++++++++>
++++++++++++>
+++++++++++++++>
>
+++++++>
+++++++++++++++>
++>
++++++++++++>
++++><
[<]
>[.>]
```

"Welcome to BrainFuck"

* Without Spacing

```
++++++++++++++++[>>+++++>++++++>++++++>++++++>++++++>++++++>++++++>++>+++++++>++++++>++>++++>+++++++>++++++>++++++>++++++>++++>+++++++>++++++>++++++><<<<<<<<<<<<<<<<<<<<<<-]>>+++++++>+++++>++++++++++++>+++>+++++++++++++++>+++++++++++++>+++++>>++++>+++++++++++++++>>++>++>+>+++++++++>++++++++++++++>++++++>+++++>+++>+++++++++++><[<]>[.>]
```
* With Spacing
```
++++++++++++++++
[
        >>
        +++++>
        ++++++>
        ++++++>
        ++++++>
        ++++++>
        ++++++>
        ++++++>
        ++>
        +++++++>
        ++++++>
        ++>
        ++++>
        +++++++>
        ++++++>
        ++++++>
        ++++++>
        ++++>
        +++++++>
        ++++++>
        ++++++>
<<<<<<<<<<<<<<<<<<<<<<-
]
>>
+++++++>
+++++>
++++++++++++>
+++>
+++++++++++++++>
+++++++++++++>
+++++>
>
++++>
+++++++++++++++>
>
++>
++>
+>
+++++++++>
++++++++++++++>
++++++>
+++++>
+++>
+++++++++++><
[<]
>[.>]
```

You can use this [BrainFuck Interpreter](https://simplexshotz.github.io/BrainFuckInterpreter/) to check if your BrainFuck program works as intended. 