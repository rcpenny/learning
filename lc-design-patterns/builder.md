建造者模式用于创建过程稳定，但配置多变的对象。在《设计模式》一书中的定义是：将一个复杂的构建与其表示相分离，使得同样的构建过程可以创建不同的表示。

经典的“建造者-指挥者”模式现在已经不太常用了，现在建造者模式主要用来通过链式调用生成不同的配置。比如我们要制作一杯珍珠奶茶。它的制作过程是稳定的，除了必须要知道奶茶的种类和规格外，是否加珍珠和是否加冰是可选的。使用建造者模式表示如下：

```java
public class MilkTea {
    /** 
     * 类型 
     */
    private final String type;
    
    /** 
     * 大小
     */
    private final String size;
    
    /** 
     * 是否加珍珠
     */
    private final boolean pearl;
    
    /**
     * 是否加冰
     */
    private final boolean ice;

   private MilkTea(Builder builder) {
       this.type = builder.type;
       this.size = builder.size;
       this.pearl = builder.pearl;
       this.ice = builder.ice;
   }

   // Getters....

    public static class Builder {
       private String type;
       private String size = 'medium';
       private boolean pearl = true;
       private boolean ice = false;
    
	public Builder() {
        }
	
	public Builder type(String type) {
		this.type = type;
		return this;
	}


	public Builder size(String type) {
		this.size = size;
		return this;
	}

	public Builder pearl(boolean pearl) {
		this.pearl = pearl;
		return this;
	}

	public Builder ice(boolean ice) {
		this.ice = ice;
		return this;
	}

	public MilkTea() {
		return new MilkTea(this);
	}
    }
}
```

可以看到，我们将 MilkTea 的构造方法设置为私有的，所以外部不能通过 new 构建出 MilkTea 实例，只能通过 Builder 构建。对于必须配置的属性，通过 Builder 的构造方法传入，可选的属性通过 Builder 的链式调用方法传入，如果不配置，将使用默认配置，也就是中杯、加珍珠、不加冰。根据不同的配置可以制作出不同的奶茶：

```java
public class User {
    private void buyMilkTea() {
        MilkTea milkTea = new MilkTea.Builder("原味").build();
        show(milkTea);

        MilkTea chocolate =new MilkTea.Builder("巧克力味")
                .ice(false)
                .build();
        show(chocolate);
        
        MilkTea strawberry = new MilkTea.Builder("草莓味")
                .size("大杯")
                .pearl(false)
                .ice(true)
                .build();
        show(strawberry);
    }

    private void show(MilkTea milkTea) {
        String pearl;
        if (milkTea.isPearl())
            pearl = "加珍珠";
        else
            pearl = "不加珍珠";
        String ice;
        if (milkTea.isIce()) {
            ice = "加冰";
        } else {
            ice = "不加冰";
        }
        System.out.println("一份" + milkTea.getSize() + "、"
                + pearl + "、"
                + ice + "的"
                + milkTea.getType() + "奶茶");
    }
}
```

运行程序，输出如下：

一份中杯、加珍珠、不加冰的原味奶茶
一份中杯、加珍珠、不加冰的巧克力味奶茶
一份大杯、不加珍珠、加冰的草莓味奶茶

使用建造者模式的好处是不用担心忘了指定某个配置，保证了构建过程是稳定的。在 OkHttp、Retrofit 等著名框架的源码中都使用到了建造者模式。
