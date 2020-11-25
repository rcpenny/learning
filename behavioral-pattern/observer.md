观察者模式 Observer
观察者模式非常常见，近年来逐渐流行的响应式编程就是观察者模式的应用之一。观察者模式的思想就是一个对象发生一个事件后，逐一通知监听着这个对象的监听者，监听者可以对这个事件马上做出响应。

生活中有很多观察者模式的例子，比如我们平时的开关灯。当我们打开灯的开关时，灯马上亮了；当我们关闭灯的开关时，灯马上熄了。这个过程中，灯就对我们控制开关的事件做出了响应，这就是一个最简单的一对一观察者模式。当力扣公众号发表一篇文章，所有关注了公众号的读者立即收到了文章，这个过程中所有关注了公众号的微信客户端就对公众号发表文章的事件做出了响应，这就是一个典型的一对多观察者模式。

再举个例子，比如警察一直观察着张三的一举一动，只要张三有什么违法行为，警察马上行动，抓捕张三。

这个过程中：

警察称之为观察者（Observer）
张三称之为被观察者（Observable，可观察的）
警察观察张三的这个行为称之为订阅（subscribe），或者注册（register）
张三违法后，警察抓捕张三的行动称之为响应（update）
众所周知，张三坏事做尽，是一个老法外狂徒了，所以不止一个警察会盯着张三，也就是说一个被观察者可以有多个观察者。当被观察者有事件发生时，所有观察者都能收到通知并响应。观察者模式主要处理的是一种一对多的依赖关系。它的定义如下：

观察者模式（Observer Pattern）：定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。

我们使用程序来模拟一下这个过程。

观察者的接口：

Java
```java
public interface Observer {
    void update(String event);
}
```
接口中只有一个 update 方法，用于对被观察者发出的事件做出响应。

被观察者的父类：

Java
```java
public class Observable {

    private List<Observer> observers = new ArrayList<>();

    public void addObserver(Observer observer) {
        observers.add(observer);
    }

    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    public void notifyObservers(String event) {
        for (Observer observer : observers) {
            observer.update(event);
        }
    }
}
```
被观察者中维护了一个观察者列表，提供了三个方法：

addObserver：将 observer 对象添加到观察者列表中
removeObserver：将 observer 对象从观察者列表中移除
notifyObservers：通知所有观察者有事件发生，具体实现是调用所有观察者的 update 方法
有了这两个基类，我们就可以定义出具体的罪犯与警察类。

警察属于观察者：

Java
```java
public class PoliceObserver implements Observer {
    @Override
    public void update(String event) {
        System.out.println("警察收到消息，罪犯在" + event);
    }
}
```
警察实现了观察者接口，当警察收到事件后，做出响应，这里的响应就是简单的打印了一条日志。

罪犯属于被观察者：

Java
```java
public class CriminalObservable extends Observable {
    public void crime(String event) {
        System.out.println("罪犯正在" + event);
        notifyObservers(event);
    }
}
```
罪犯继承自被观察者类，当罪犯有犯罪行为时，所有的观察者都会收到通知。

客户端测试：

Java
```java
public class Client {
    @Test
    public void test() {
        CriminalObservable zhangSan = new CriminalObservable();
        PoliceObserver police1 = new PoliceObserver();
        PoliceObserver police2 = new PoliceObserver();
        PoliceObserver police3 = new PoliceObserver();
        zhangSan.addObserver(police1);
        zhangSan.addObserver(police2);
        zhangSan.addObserver(police3);
        zhangSan.crime("放狗咬人");
    }
}
```
在客户端中，我们 new 了一个张三，为其添加了三个观察者：police1，police2，police3。

运行程序，输出如下：


罪犯正在放狗咬人
警察收到消息，罪犯在放狗咬人
警察收到消息，罪犯在放狗咬人
警察收到消息，罪犯在放狗咬人
可以看到，所有的观察者都被通知到了。当某个观察者不需要继续观察时，调用 removeObserver 即可。

这就是观察者模式，它并不复杂，由于生活中一对多的关系非常常见，所以观察者模式应用广泛。

Java 源码中的观察者模式
实际上，Java 已经为我们提供了的 Observable 类和 Observer 类，我们在用到观察者模式时，无需自己创建这两个基类，我们来看一下 Java 中提供的源码：

java.util.Observer 类：
```java
Java

public interface Observer {
    void update(Observable o, Object arg);
}
```
Observer 类和我们上例中的定义基本一致，都是只有一个 update 方法用于响应 Observable 的事件。区别有两点：

update 方法将 Observable 对象也提供给了 Observer
update 方法中的参数类型变成了 Object
这两点区别都是为了保证此 Observer 的适用范围更广。

java.util.Observable 类：
```java
Java

public class Observable {
    private boolean changed = false;
    private Vector<Observer> obs;

    public Observable() {
        obs = new Vector<>();
    }

    public synchronized void addObserver(java.util.Observer o) {
        if (o == null)
            throw new NullPointerException();
        if (!obs.contains(o)) {
            obs.addElement(o);
        }
    }

    public synchronized void deleteObserver(java.util.Observer o) {
        obs.removeElement(o);
    }

    public void notifyObservers() {
        notifyObservers(null);
    }

    public void notifyObservers(Object arg) {
        Object[] arrLocal;
        synchronized (this) {
            if (!hasChanged())
                return;
            arrLocal = obs.toArray();
            clearChanged();
        }
        for (int i = arrLocal.length - 1; i >= 0; i--)
            ((Observer) arrLocal[i]).update(this, arg);
    }

    public synchronized void deleteObservers() {
        obs.removeAllElements();
    }

    protected synchronized void setChanged() {
        changed = true;
    }

    protected synchronized void clearChanged() {
        changed = false;
    }

    public synchronized boolean hasChanged() {
        return changed;
    }

    public synchronized int countObservers() {
        return obs.size();
    }
}
```
Observable 类和我们上例中的定义也是类似的，区别在于：

用于保存观察者列表的容器不是 ArrayList，而是 Vector
添加了一个 changed 字段，以及 setChanged 和 clearChanged 方法。分析可知，当 changed 字段为 true 时，才会通知所有观察者，否则不通知观察者。所以当我们使用此类时，想要触发 notifyObservers 方法，必须先调用 setChanged 方法。这个字段相当于在被观察者和观察者之间添加了一个可控制的阀门。
提供了 countObservers 方法，用于计算观察者数量
添加了一些 synchronized 关键字保证线程安全
这些区别仍然是为了让 Observable 的适用范围更广，核心思想与本文介绍的都是一致的。
