/*
继承：
	作用：
	1.实现代码复用,避免代码冗余
	2.保持原有类特性的基础上进行扩展，增加新功能
	3.面向对象设计的层次结构

继承之后：成员变量成员函数都被继承了，sizeof == 父类 + 子类新增的
基类：类似根结点，所有子类的祖先

继承方式：
class Base{};
class Child : 继承权限 + Base
{};

继承规则：
	继承方式：          基类的成员的访问权限 
						public		protected	    private
	   public			public		protected		不可被访问(继承到子类中了)
	protected			protected   protected       不可被访问(继承到子类中了)
	  private			private     private         不可被访问(继承到子类中了)
	
	注意：这里的访问权限是针对类外的访问权限，也就是子类对象在main函数中的权限，子类中还是可以访问父类中public和protected成员的！

如果不写继承权限：class 默认给private的继承权限
				  struct 默认给public

在C++中class 和 struct 的区别
	1.访问权限
	2.继承权限
	3.定义一个模板 template <class T> ，而不能用struct
























*/