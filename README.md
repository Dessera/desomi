这是一个学习仓库，我正在尝试以面向对象的方式包装SDL2库
但实际上这个仓库更像是我学习C++的笔记

## 桥模式
Base - Some base api && has a BaseImpl
BaseImpl - Other base api
子类可以继承Base或者BaseImpl
继承Base的子类作为更底层的实现，继承BaseImpl的子类作为更高层的实现
运行时将二者组合起来，这样就可以在不同的实现之间切换
解耦抽象和实现

可以看做如下图：
Base -- BaseImpl
 |        |
 |        |
Derived1  DerivedImpl1
Derived2  DerivedImpl2

然后可以通过如下方式组合：
Derived1 -- DerivedImpl1
Derived2 -- DerivedImpl2
Derived1 -- DerivedImpl2
Derived2 -- DerivedImpl1

## 装饰器
Base - Some base api
Decorator - Base && has a Base
子类可以继承Base，也可以继承Decorator
Decorator作为Base的装饰器，可以在Base的基础上添加扩展功能
运行时将二者组合起来，这样就可以在不同的扩展之间切换
解耦实现和扩展实现

可以看做如下图：
Base -- Decorator
 |        |
 |        |
Derived1  Decorator1
Derived2  Decorator2

然后可以通过如下方式组合：
Derived1 -- Decorator1
Derived2 -- Decorator2
Derived1 -- Decorator2
Derived2 -- Decorator1
