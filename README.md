<p align="center">
  <a href="https://42lyon.fr/">
    <img src="./assets/final_grade.png" alt="ft_containers" width=200 height=170>
  </a>

  <h2 align="center">ft_containers</h2>

  <p align="center">
    <br>
    Re-implementation of a selection of standard C++ containers featuring a self-balancing binary search tree (red-black tree).
    <br>
    <br>
    <a href="./assets/en.subject.pdf">English Subject </a>
  </p>
</p>


## Table of contents

- [Quick start](#quick-start)
- [What's included](#whats-included)
- [Creators](#creators)


## Quick start


### ft::vector ###

std::vector construction / destruction behavior is mimicked in this ft version. For security reasons, the original one sometimes constructs / destructs in a specific order before switching to the opposite direction during reallocations.

### ft::map / ft::set ###

A dedicated red-black tree is used to keep the binary search tree balanced during deletion / insertion of a node. It can be found in the utils/ directory.

### tester ###

A TestClass is included. It is printing a dedicated message ("number X copy/default/assignment/... constructor called") everytime a constructor / destructor is called. A static variable is incremented everytime a constructor is called in order to be able to track each action of the standard containers.

/!\ replace [to_test] with the name of the class to test : ``` vector pair stack set map ```  /!\

- compare ft::[to_test] and std::[to_test] output :
```
make [to_test]
```

- perform a full test :
```
make full
```

The output will display a speed test and a diff (that should stay blank for success) between the output files stored in "tester/tester_results/". 

## What's included

```
ft_containers
├── assets
│   ├── en.subject.pdf
│   └── final grade.png
├── containers
│   ├── map.hpp
│   ├── set.hpp
│   ├── stack.hpp
│   └── vector.hpp
├── iterators
│   ├── bidirectional_iterator.hpp
│   ├── iterator.hpp
│   ├── random_access_iterator.hpp
│   └── reverse_iterator.hpp
├── main.cpp
├── Makefile
├── README.md
├── tester
│   ├── scripts
│   │   ├── test_diff.sh
│   │   ├── test_ft.sh
│   │   ├── test_full.sh
│   │   ├── test_map.sh
│   │   ├── test_pair.sh
│   │   ├── test_set.sh
│   │   ├── test_stack.sh
│   │   ├── test_std.sh
│   │   └── test_vector.sh
│   ├── TestClass.cpp
│   ├── TestClass.hpp
│   ├── tester_map.cpp
│   ├── tester_pair.cpp
│   ├── tester_set.cpp
│   ├── tester_stack.cpp
│   └── tester_vector.cpp
└── utils
    ├── metafunctions.hpp
    ├── node.hpp
    ├── pair.hpp
    ├── RB_tree.hpp
    ├── tester.hpp
    ├── tester_utils.hpp
    └── utils.hpp
```

## Creators

**llecoq**

- <https://github.com/llecoq>
