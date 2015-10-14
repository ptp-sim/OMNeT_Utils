
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
To support his, OMNeT++ provides the macros `Enter_Method()` and `Enter_Method_Silent()`.
But these methods only support the case when one module directly calls another module.
They do not support the case when one module would like to call a subclass of another module.
Consider the following pseudo-code:

    clase A
    {
        public: void foo() {};   // <-- Can't call Enter_Method_Silent() here,
                                 //     as A doe not inherit from cModule
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
        b = heck_and_cast<B *>(getModuleByPath("^.b"));

        b->a.foo();
    }

The _Callable_ subproject provides helper functions to enable this scenario.

### Channels

The _Channels_ subproject provides additional channel definitions.
At the moment, it only provides a single channel: `VolatileDelayChannel`.
This channel is meant to behave similar to OMNeT's own `DelayChannel`, but
the delay parameter is volatile, and thus re-read on every access.

### DynamicSignals

OMNeT++ provides the possibility to register signals with dynamic names during runtime.
Teh _DynamicSignals_ subproject provides helper functions to make this a little bit easier.

### InitBase

OMNeT++ provides an API for structured initialization, by using the functions `numInitStages()` and `initialize(stage)`.
However, the tasks that are implemented in this stages are often the same: parsing parameters, registering signals, etc.
Thus it makes sense to introduce a common initialization approach.
This is what the _InitBase_ subprojects does.
The interface class `IInitBase` provides the following functions:

* __ParseResourceParameters():__ Parse parameters that are required to allocate further resources.
* __AllocateResources():__ Allocate required resources.
* __InitHierarchy():__ Establish all needed parent-child relationships between this class and child classes.
* __ParseParameters():__ Parse all remaining configuration parameters.
* __RegisterSignals():__ Register signals.
* __InitInternalState():__ Initialize a consistent state for this module depending on the configuration.
* __InitSignals():__ If the semantic of signals makes sense on startup (e.g. the size of a queue could be 0 at startup), the initial signal values may be emitted here. After this stage it is allowed to use the module's signals.
* __FinishInit():__ If the module needs to schedules event on startup or things like that, this should be done here.
* __PrintDebugOutput():__ If the configuration tells the module to print initial debug output, this can be implemented here.

* __ForwardInit( int stage ):__ In case that this module has child classes that implement the `IInitBase` interface, `ForwardInit(stage)` has to call their `initialize(stage)` routine with its own `stage` parameter. `IInitBase` takes care that child classes are only initialized after the parent process is ready.

The _InitBase_ project provides the following helper classes:

* __ModuleInitBase__: this is for simple modules and directly inherits from `cSimpleModule`.
* __SubmoduleInitBase__: the purpose of this class is to introduce the _InitBase_ interface to classes that are used as childs from other moduls that support the interface. The parents `ForwardInit()` function is responsible to call the child's `initialize()`.

In case `ModuleInitBase` or `SubmoduleInitBase` are use, the following functions from original OMNeT++ initialization API __should not__ be used otherwise anymore:

* __numInitStages()__
* __initialize( int stage )__

Things are different if you would like to use `IInitBase` with a class that already inherits from `cSimpleModule`.
This can be the case if you extend modules provided by external libraries, like e.g. the INET library.
In this case you have to inherit from `IInitBase` and make sure your implementations of `numInitStages()` and `initialize()` forward to the correct base classes.
Consider as an example the following pseudo code:

    // This is a class from an external library, and you can't change it.
    // You would like to inherit from it and use IInitBase.
    class ExternalModule: public cSimpleModule
    {
    }

    // This is you class
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

### ParameterParser

This subproject helps to parse parameter strings into enumerations.

Building
---------------------

See INSTALL.txt for details.

License
---------------------

This project is licensed unter the 3-clause BSD license. See the LICENSE.txt file for details.

Contact
---------------------

wolfgang-wallner [AT] gmx.at
