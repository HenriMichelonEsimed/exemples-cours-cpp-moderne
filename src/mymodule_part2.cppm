module;
import std;

export module my_module.part2;

import my_module.part1;

export void function2() {
  function1();
  std::cout << "Hello from my_module, partition 2\n";
}