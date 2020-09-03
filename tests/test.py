import cmake_example as m

# Verify everything works
m.myFunc1(4)
print(m.myFunc2(5))

# works fine
print("some_func_operation with myFunc1")
m.some_func_operation(m.myFunc1, 1)

# hangs - you can see that it also calls the wrong overload
# (it prints "void return overload")
print("some_func_operation with myFunc2")
m.some_func_operation(m.myFunc2, 2)
