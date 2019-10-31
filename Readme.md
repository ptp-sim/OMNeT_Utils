
Generic OMNeT++ Utilities
===============================

Project description
-------------------------------

This repository provides useful utilities to be used with the [OMNeT++][1] network simulation framework.

[1]: https://omnetpp.org/

## Sub projects

This repository contains the following subprojects:

* __Callable:__ Helper functions for classes that can be called directly from other classes.
* __Channels:__ Additional channel definitions.
* __DynamicSignals:__ Helper functions for registering signals during runtime.
* __InitBase:__ Structured initialization of modules and subclasses of modules.
* __ParameterParser:__ Helper functions to parse parameter strings to C++ enumerations.

### Callable

In OMNeT++ modules usually communicate via message exchange.
But sometimes it is more suitable that modules directly call each other.
To support this, OMNeT++ provides the macros `Enter_Method()` and `Enter_Method_Silent()`.
But these methods only support the case when one module directly calls another module.
They do not support the case when one module would like to call a subclass of another module.
Consider the following pseudo-code:

```c++
    clase A
    {
        public: void foo() {};   // <-- Can't call Enter_Method_Silent() here,
                                 //     as A does not inherit from cModule
    }

    class B: public cSimpleModule
    {
        public:
            A   a;
    }

    class C: public cSimpleModule
    {
        B *b;

        C();
    }

    C::C()
    {
        b = check_and_cast<B *>(getModuleByPath("^.b"));

        b->a.foo();   // <-- Directly calling a method from a child class of b
    }
```

The _Callable_ subproject provides helper functions to enable this scenario.

### Channels

The _Channels_ subproject provides additional channel definitions.
At the moment, it only provides a single channel: `VolatileDelayChannel`.
This channel is meant to behave similar to OMNeT++'s own `DelayChannel`, but
the delay parameter is volatile, and thus re-read on every access.
As a result, the delay of the channel can vary during the simulation run, instead of only being randomly selected at the beginning and then being constant for the rest of the simulation run.

### DynamicSignals

OMNeT++ provides the possibility to register signals with dynamic names during runtime.
The _DynamicSignals_ subproject provides helper functions to make this a little bit easier.

### InitBase

OMNeT++ provides an API for structured initialization, by using the folloging functions:

* `numInitStages()`: returns the number of required calls to `initialize(stage)`
* `initialize(stage)`: initializes the stage given by the `stage` parameter

However, the tasks which are implemented in this stages are often the same for many different modules: parsing parameters, registering signals, etc.
This results in similar, yet different code in multiple places.

To avoid code duplication and mistakes, it makes sense to introduce a common initialization approach.
This is what the _InitBase_ subprojects does.
The interface class `IInitBase` provides the following functions:

* __ParseResourceParameters():__ Parse parameters that are required to allocate further resources.
* __AllocateResources():__ Allocate required resources.
* __InitHierarchy():__ Establish all needed parent-child relationships between this class and child classes (e.g. a child class might need a pointer to its parent class).
* __ParseParameters():__ Parse all remaining configuration parameters.
* __RegisterSignals():__ Register signals.
* __InitInternalState():__ Initialize a consistent state for this module depending on the configuration.
* __InitSignals():__ If the semantic of signals makes already sense on startup (e.g. the size of a queue could be 0 at startup), the initial signal values may be emitted here. After this stage it is allowed to use the module's signals.
* __FinishInit():__ If the module needs to schedule events on startup or things like that, this should be done here.
* __PrintDebugOutput():__ If the configuration tells the module to print initial debug output, this can be implemented here.

* __ForwardInit( int stage ):__ In case that this module has child classes that also implement the `IInitBase` interface, `ForwardInit()` has to call their `initialize(stage)` routine with its own `stage` parameter. `IInitBase` takes care that child classes are only initialized after the parent process is ready.

The _InitBase_ project provides the following helper classes:

* __ModuleInitBase__: this is for simple modules and directly inherits from `cSimpleModule`.
* __SubmoduleInitBase__: the purpose of this class is to introduce the `IInitBase` interface to classes that are used as childs from other moduls that support the interface.
The parent's `ForwardInit()` function is responsible to call the child's `initialize()`. On the other hand, the childs may rely on the parent for cSimpleModule-specific functions, like calling `par()`.

In case `ModuleInitBase` or `SubmoduleInitBase` are used, the following functions from the original OMNeT++ initialization API __should not__ be used otherwise anymore:

* __numInitStages()__
* __initialize( int stage )__

Things are different if you would like to use `IInitBase` with a class that already inherits from `cSimpleModule`.
This can be the case if you extend modules provided by external libraries, like e.g. the INET library.
In this case you have to inherit from `IInitBase` and make sure your implementations of `numInitStages()` and `initialize()` forward to the correct base classes.
Consider as an example the following pseudo code:

```c++
    // Suppose this is a class from an external library, and you can't change it.
    // You would like to inherit from it and use IInitBase.
    class ExternalModule: public cSimpleModule
    {
    }

    // This is your class
    class MyModule: public ExternalModule, public IInitBase
    {
    }

    int
    MyModule::numInitStages() const
    {
        // Ensure we are called often enough
        return std::max( IInitBase::numInitStages(), ExternalModule::numInitStages() );
    }

    void
    MyModule::initialize(int stage)
    {
        // Forward initialize() calls to where they are needed
        if( stage < ExternalModule::numInitStages() )
        {
            ExternalModule::initialize();
        }

        if( stage < IInitBase::numInitStages() )
        {
            IInitBase::initialize( stage );
        }
    }
```

### ParameterParser

This subproject helps to parse parameter strings into enumerations.
This is done by providing a simple helper array for string/enumeration assignment and a stupid loop with element comparison.
There is lots of room for improvement in the implementation of this subproject, but for now it works and does what it should :)

Pseudo code example:

```c++
    // The enumeration you would like to use in your code
    enum MyType
    {
        MY_TYPE_OPTION_A,
        MY_TYPE_OPTION_B,
    };

    // A helper array to help assign strings -> enumerations
    ParseType<MyType>   MyTypeParseArray[] =
    {
        { MY_TYPE_OPTION_A, "MY_TYPE_OPTION_A" },
        { MY_TYPE_OPTION_B, "MY_TYPE_OPTION_B" },
    };

    // Your custom paramter parsing class
    class MyParser
    {
        public:
            static MyType ParseMyType(const char *Str);
    };

    // Function to parse your enumerations
    MyType
    MyParser::ParseMyType(const char *Str)
    {
        return Parse<MyType>( MyTypeParseArray, ArrayLen(MyTypeParseArray), Str );
    }

    // Using the parser in your initialize routines (ParseParameters(), if you use InitBase):
    MyType  t = MyParser::ParseMyType( par( "MyTypeParameter" ).stringValue() );
```

Building
---------------------

See INSTALL.md for details.

License
---------------------

This project is licensed under the 3-clause BSD license. See the LICENSE.txt file for details.

Contact
---------------------

wolfgang-wallner [AT] gmx.at
