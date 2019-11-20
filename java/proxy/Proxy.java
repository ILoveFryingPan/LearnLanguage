import staticProxy.StaticProxy;
import staticProxy.Hello;
import staticProxy.IHello;
import dynamic.HelloInvocationHandler;
//import java.lang.reflect.Proxy;

public class Proxy {
	public static void main(String[] args) {
		Hello hello = new Hello();
		StaticProxy staticProxy = new StaticProxy();
		staticProxy.setIHello(hello);
		staticProxy.sayHello();

		HelloInvocationHandler handler = new HelloInvocationHandler<IHello>(hello);
		IHello ihello = (IHello) java.lang.reflect.Proxy.newProxyInstance(IHello.class.getClassLoader(), new Class<?>[]{IHello.class}, handler);
		ihello.sayHello();
	}
}
