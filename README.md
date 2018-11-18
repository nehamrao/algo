*NOTES*

1) Static method in python (@staticmethod) can be invoked w/o class initialization
2) Files named __init__.py are used to mark directories on disk as Python package directories.
   If you remove the __init__.py file, Python will no longer look for submodules inside that directory, 
   so attempts to import the module will fail. Furthermore, this is the first file to be loaded in a module, 
   so you can use it to execute code that you want to run each time a module is loaded, 
   or specify the submodules to be exported.
3) Decorators: This is ideal when you need to extend the functionality of functions that you don't want to modify.
    decorators work as wrappers, modifying the behavior of the code before and after a target function execution, 
    without the need to modify the function itself, augmenting the original functionality, thus decorating it.
    In python we can do a whole bunch of cool things - 
    https://www.thecodeship.com/patterns/guide-to-python-function-decorators/
 4) Closure: Inner functions have access to the enclosing scope

