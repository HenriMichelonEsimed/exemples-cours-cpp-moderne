module;
import std;

module my_module_2;

MyClass2::MyClass2(const std::string& name): name{name} {

}

void MyClass2::function1() {
  std::cout << name << std::endl;
}