#igloo-TAPListener

## How to use

1. Add this repository as submodule.
```
cd $PROJECT_ROOT
git submodule add https://github.com/hideo55/igloo-TAPListener.git extlib/igloo-TAPListener
```

2. Add `extlib/igloo-TAPListener` to include path.

3. Create test 

```c++
#include <igloo/igloo.h>
#include <igloo/TestListener/TAPListener.h>

// Write some tests

int main()
{
  DefaultTestResultsOutput output;
  TestRunner runner(output);

  TapListener listener;
  runner.AddListener(&listener);

  runner.Run();
}
```
## Author

Hideaki Ohno

## License

igloo-TAPListener  is distributed under the [Boost Software License, Version 1.0](http://www.boost.org/users/license.html).
