#igloo-TapTestListener

## How to use

1. Add this repository as submodule.
  ```
  cd $PROJECT_ROOT
  git submodule add https://github.com/hideo55/igloo-TapTestListener.git extlib/igloo-TapTestListener
  ```

2. Add `extlib/igloo-TapTestListener` to include path.

3. Create test 

  ```c++
  #include <igloo/igloo.h>
  #include <igloo/TapTestListener.h>
  
  using namespace igloo;

  // Write some tests

  int main()
  {
    DefaultTestResultsOutput output;
    TestRunner runner(output);

    TapTestListener listener;
    runner.AddListener(&listener);

    runner.Run();
  }
  ```
  
## Author

Hideaki Ohno

## License

igloo-TapTestListener is distributed under the [Boost Software License, Version 1.0](http://www.boost.org/users/license.html).
