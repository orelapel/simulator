cmake_minimum_required(VERSION 3.15)
project(simulator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(simulator main.cpp Command.h OpenServerCommand.h ConnectCommand.h ConnectCommand.h DefineVarCommand.h
        InformationVar.h ChangeCommand.h SimbolTable.h Sleep.h Print.h ConditionParser.h IfCommand.h LoopCommand.h
        Value.cpp Value.h Variable.cpp Variable.h Plus.cpp Plus.h Minus.cpp Minus.h Mul.cpp Mul.h Div.cpp Div.h
        UPlus.cpp UPlus.h UMinus.cpp UMinus.h BinaryOperator.cpp BinaryOperator.h UnaryOperator.cpp UnaryOperator.h Interpreter.cpp Interpreter.h
        Bigger.cpp Bigger.h BigOrEqual.cpp BigOrEqual.h Smaller.cpp Smaller.h SmallOrEqual.cpp SmallOrEqual.h Equal.cpp Equal.h UnEqual.cpp UnEqual.h Parser.h ConditionParser.cpp IfCommand.cpp LoopCommand.cpp Parser.cpp Sleep.cpp)