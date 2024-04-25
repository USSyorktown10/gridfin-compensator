#include <compare>
#include <iostream>

int main() {
  int a = 1;
  int b = 2;
  
  auto result = a <=> b;
  
  if (result < 0) {
    std::cout << "a is less than b" << std::endl;
  } else if (result == 0) {
    std::cout << "a is equal to b" << std::endl;
  } else { // result > 0
    std::cout << "a is greater than b" << std::endl;
  }

  return 0;
}
struct Fao {
    int value;
    
    bool operator==(const Fao& rhs) const {
        return value == rhs.value;   
    }
    bool operator!=(const Fao& rhs) const {
        return !(value == rhs.value);   
    }
    bool operator<(const Fao& rhs) const {
        return value < rhs.value;   
    }
    bool operator>(const Fao& rhs) const {
        return value > rhs.value;   
    }
    bool operator<=(const Fao& rhs) const {
        return value <= rhs.value;   
    }
    bool operator>=(const Fao& rhs) const {
        return value >= rhs.value;   
    }
};

int main() {
  Fao a{1};
  Fao b{2};
  
  std::cout << std::boolalpha << (a == b) << std::endl; // prints false
  std::cout << std::boolalpha << (a != b) << std::endl; // prints true
  std::cout << std::boolalpha << (a < b) << std::endl; // prints true
  std::cout << std::boolalpha << (a > b) << std::endl; // prints false
  std::cout << std::boolalpha << (a <= b) << std::endl; // prints true
  std::cout << std::boolalpha << (a >= b) << std::endl; // prints false
}
#include <compare>

struct Fao {
    int value;
    
    auto operator<=>(const Fao& rhs) const = default;
};

int main() {
  Fao a{1};
  Fao b{2};
  
  std::cout << std::boolalpha << (a == b) << std::endl; // prints false
  std::cout << std::boolalpha << (a != b) << std::endl; // prints true
  std::cout << std::boolalpha << (a < b) << std::endl; // prints true
  std::cout << std::boolalpha << (a > b) << std::endl; // prints false
  std::cout << std::boolalpha << (a <= b) << std::endl; // prints true
  std::cout << std::boolalpha << (a >= b) << std::endl; // prints false
}
#include <compare>

struct Foo {
    int value;
    
    auto operator<=>(const Foo& rhs) const = default;
    bool operator<(const Foo& rhs) const = default;
};

int main() {
  Foo a{1};
  Foo b{2};
  
  std::cout << std::boolalpha << (a < b) << std::endl; // prints true
}
#include <compare>

struct Foo {
  int value;

  bool operator<(const Foo& rhs) const = default;
};

int main() {
  Foo a{1};
  Foo b{2};

  std::cout << std::boolalpha << (a < b) << std::endl; // Object of type 'Foo' cannot be compared because its "operator<" is implicitly deleted
}
#include <compare>

struct Fao {
  int value;

  explicit Fao(int value) : value(value) {}

  bool operator==(const int otherValue) const {
    return value == otherValue;
  }
};

int main() {
  Fao a{10};

  std::cout << std::boolalpha << (a == 10) << std::endl; // prints true
}
#include <compare>

struct Fao {
    int value;

    explicit Fao(int value) : value(value) {}
    
    auto operator<=>(const int otherValue) const {
      return value <=> otherValue;
    }
};

int main() {
  Fao a{1};
  
  std::cout << std::boolalpha << (a < 10) << std::endl; // prints true
}
struct Fao {
  int value;

  auto operator<=>(const Fao& rhs) const = default;
};

int main() {
  Fao a{1};
  Fao b{2};

  std::cout << std::boolalpha << (a < b) << std::endl; // No error. <=> is defaulted, so a < b gets rewritten in terms of <=> 
  std::cout << std::boolalpha << (a == b) << std::endl; // No error. == is implicitly defaulted by defaulting <=>
}
struct Fao {
  int value;

  bool operator==(const Fao& rhs) const = default;
};

int main() {
  Fao a{1};
  Fao b{2};

  std::cout << std::boolalpha << (a < b) << std::endl; // Error. <=> is not defined in any way
  std::cout << std::boolalpha << (a == b) << std::endl; // No error. == is defaulted
}
struct Fao {
  int value;

  auto operator<=>(const Fao& rhs) const {
    return value <=> rhs.value;
  }

  bool operator==(const Fao& rhs) const {
    return value == rhs.value;
  }
};

int main() {
  Fao a{1};
  Fao b{2};

  std::cout << std::boolalpha << (a < b) << std::endl; // No error. <=> is defined, so a < b gets rewritten in terms of <=>
  std::cout << std::boolalpha << (a == b) << std::endl; // No error. == is defined
}
struct Fao {
  int value;

  auto operator<=>(const Fao& rhs) const {
    return value <=> rhs.value;
  }
};

int main() {
  Fao a{1};
  Fao b{2};

  std::cout << std::boolalpha << (a < b) << std::endl; // No error. <=> is defined, so a < b gets rewritten in terms of <=>
  std::cout << std::boolalpha << (a == b) << std::endl; // Error. == is not defined in any way
}
struct Fao {
  int value;

  auto operator<=>(const Fao& rhs) const {
    return value <=> rhs.value;
  }

  bool operator==(const Fao& rhs) const = default;
};

int main() {
  Fao a{1};
  Fao b{2};

  std::cout << std::boolalpha << (a < b) << std::endl; // No error. <=> is defined, so a < b gets rewritten in terms of <=>
  std::cout << std::boolalpha << (a == b) << std::endl; // No error. == is defaulted
}
