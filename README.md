这是一个学习仓库，我正在尝试以面向对象的方式包装SDL2库
但实际上这个仓库更像是我学习C++的笔记

# 继承 -> 组合

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



# 对象创建模式

## 工厂模式
Base
Factory  -> DerivedFactory1 -> Derived1
        |-> DerivedFactory2 -> Derived2
        |-> DerivedFactory3 -> Derived3

在需要某个类的时候，通过工厂来创建
Factory {
  virtual Base *create() = 0;
}
DerivedFactory1 {
  Base *create() {
    return new Derived1();
  }
}
Class {
  Factory *factory;

  fun() {
    Base obj = factory->create();
  }
}

## 抽象工厂模式
BaseSeries -> DerivedSeries1
           |-> DerivedSeries2
           |-> DerivedSeries3

Factory -> DerivedFactory1 -> DerivedSeries1
             |-> DerivedFactory2 -> DerivedSeries2
             |-> DerivedFactory3 -> DerivedSeries3

Factory {
  virtual Base1 *createBase1() = 0;
  virtual Base2 *createBase2() = 0;
  virtual Base3 *createBase3() = 0;
  ...
}
DerivedFactory1 {
  Base1 *createBase1() {
    return new Derived1();
  }
  Base2 *createBase2() {
    return new Derived2();
  }
  Base3 *createBase3() {
    return new Derived3();
  }
  ...
}

Class {
  Factory *factory;

  fun() {
    Base1 obj1 = factory->createBase1();
    Base2 obj2 = factory->createBase2();
    Base3 obj3 = factory->createBase3();
    ...
  }
}

## Prototype模式
Interface {
  // 业务逻辑
  virtual type execute() = 0;
  // 克隆方法
  virtual Interface *clone() = 0;
}
ConcreteInterface1 {
  type execute() {
    // 业务逻辑
  }
  Interface *clone() {
    return new ConcreteInterface1(*this);
  }
}
ConcreteInterface2 {
  type execute() {
    // 业务逻辑
  }
  Interface *clone() {
    return new ConcreteInterface2(*this);
  }
}
Class {
  Interface *interface;

  fun() {
    Interface *obj = interface->clone();
    obj->execute();
  }
}
